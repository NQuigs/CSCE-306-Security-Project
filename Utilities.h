#pragma once
#include <regex>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>

class Utilities {
public:

	std::vector<std::string> split(const char* charLine)
	{
		int count = std::strlen(charLine);
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

	std::vector<std::string> read(std::string fileName, std::string username, std::string password = "")
	{
		std::ifstream myfile;
		std::regex exp(password);
		myfile.open(fileName);
		std::string myline;
		const char* charLine;
		int count;
		char* accountInfo;

		if (myfile.is_open()) {
			while (myfile.good()) { // equivalent to myfile.good()
				std::getline(myfile, myline);
				if (myline.find(username) != std::string::npos) {

					if (password.length() != 0 && std::regex_search(myline, exp))
					{
						myfile.close();
						return split(myline.c_str());
					}

					else
					{
						myfile.close();
						return split(myline.c_str());
					}
				}
			}
		}

		myfile.close();
		return {};
	}

};
