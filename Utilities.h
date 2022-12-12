#pragma once
#include <regex>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>

class Utilities {
public:

	/// <summary>
	/// Takes a string and splits each word into a vector
	/// </summary>
	/// <param name="charLine"></param>
	/// <returns></returns>
	std::vector<std::string> split(const char* charLine)
	{
		char* accountInfo = const_cast<char*>(charLine);
		std::vector<std::string> fileData;
		accountInfo = std::strtok(accountInfo , " ");
		while (accountInfo != NULL)
		{
			fileData.push_back(accountInfo);
			accountInfo = std::strtok(NULL, " ");
		}

		return fileData;
	}

	/// <summary>
	/// Writes to a file. Different file based on the file name and the parameters that were passed in
	/// </summary>
	/// <param name="fileName"></param>
	/// <param name="vector"></param>
	/// <param name="productDetails"></param>
	/// <param name="custInfo"></param>
	/// <param name="serviceDetails"></param>
	void write(std::string fileName, std::string custName, std::vector<std::string> custInfo, std::vector<std::string> productDetails, std::vector<std::string> serviceDetails)
	{
		std::string data = "";
		std::string error = "";

		std::ofstream outFile;
		outFile.open(fileName);

		if (productDetails.size() == 0 && serviceDetails.size() == 0 && custInfo.size() != 0)
		{
			for (int i = 0; i < custInfo.size(); i++)
			{
				data.append(custInfo[i] + " ");
			}
		}

		else if (productDetails.size() != 0 && serviceDetails.size() == 0 && custInfo.size() == 0)
		{
			data.append(custName + " ");

			for (int i = 0; i < productDetails.size(); i++)
			{
				data.append(productDetails[i] + " ");
			}

		}

		else if (productDetails.size() == 0 && serviceDetails.size() != 0 && custInfo.size() == 0)
		{
			data.append(custName + " ");

			for (int i = 0; i < serviceDetails.size(); i++)
			{
				data.append(serviceDetails[i] + " ");
			}
		}

		else if (productDetails.size() != 0 && serviceDetails.size() != 0 && custInfo.size() == 0)
		{
			data.append(custName + " ");
			for (int i = 0; i < productDetails.size(); i++)
			{
				data.append(productDetails[i] + " ");
			}

			for (int i = 0; i < serviceDetails.size(); i++)
			{
				data.append(serviceDetails[i] + " ");
			}
		}

		else
			error = "Something went wrong";
		
		if (error.length() == 0)
			outFile << data << "\n";

		else
			outFile << error << "\n";

		outFile.close();
	}

	/// <summary>
	/// Reads data from a file. Can read from any file based on filename. Reads products/services if no password provided
	/// </summary>
	/// <param name="username"></param>
	/// <param name="fileName"></param>
	/// <param name="password"></param>
	/// <returns></returns>
	std::vector<std::string> read(std::string fileName, std::string username, std::string password = "")
	{
		std::ifstream myfile;
		std::regex exp(password);
		myfile.open(fileName);
		std::string myline;
		const char* charLine;
		int count;
		char* accountInfo;
		std::vector<std::string> userData;

		if (myfile.is_open()) {
			while (myfile.good()) { // equivalent to myfile.good()
				std::getline(myfile, myline);
				if (myline.find(username) != std::string::npos) {

					userData = split(myline.c_str());
					if (password.length() != 0 && std::regex_match(userData[1], exp))
					{
						myfile.close();
						return userData;
					}

					else if (password.length() == 0)
					{
						myfile.close();
						return userData;
					}
				}
			}
		}

		myfile.close();
		return {};
	}

	

};
