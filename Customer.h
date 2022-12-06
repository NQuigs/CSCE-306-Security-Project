#pragma once
#include "User.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>
#include <cstring>
#include "Utilities.h"
#include "BusinessCustomer.h"


//#define MAX_LINES 100
//#define MAX_LEN 1000


class Customer :public User {
protected:
	std::string customerName;
	std::string address;
	std::string city;
	std::string state;
	std::string country;
	int zipCode;
	std::string email;
	std::string status;
	Utilities utilities;
public:
	//virtual void updateCustInfo(Customer);
	//virtual void orderProduct();
	
	//User login(std::string, std::string);

	std::vector<std::string> getCustInfo()
	{
		std::vector<std::string> custInfo;

		custInfo.push_back(customerName);
		custInfo.push_back(address);
		custInfo.push_back(city);
		custInfo.push_back(state);
		custInfo.push_back(country);
		custInfo.push_back(std::to_string(zipCode));
		custInfo.push_back(email);
		custInfo.push_back(status);
		
		return custInfo;

	}


	Customer test(std::string username, std::string password) {
		std::ifstream myfile;
		std::vector<std::string> lineWords;
		std::regex exp(password);
		myfile.open("CustAccountInfo.txt");
		std::string myline;

		if (myfile.is_open()) {
			while (myfile.good()) { // equivalent to myfile.good()
				std::getline(myfile, myline);
				if (myline.find(username) != std::string::npos) {

					if (std::regex_search(myline, exp))
					{
						const char* charLine = myline.c_str();
						int count = std::strlen(charLine);
						char* accountinfo = const_cast<char*>(charLine);
						std::vector<std::string> customerInfo = utilities.split(accountinfo);
						
						

						Customer cust;
						cust.customerName = customerInfo[0];
						cust.password = customerInfo[1];
						cust.accessLevel = customerInfo[2];
						
						if (cust.accessLevel == "1")
						{
							BusinessCustomer bus;
							return bus;
						}
						
					}
				}
			}
		}

		else
			return false;
		
	}

	


	std::string getCustName()
	{
		return customerName;
	}

	
	std::vector<std::string> stringSplit(std::string custInfo)
	{
		int count = 0;
		std::vector<std::string> customerStuff;
		for (int i = 0; i < custInfo.length(); i++)
		{
			if (custInfo[i].Equals(' '))
			{
				customerStuff.push_back(custInfo.substr(0, i - 1));
				//custInfo = custInfo.erase(custInfo.begin(), custInfo.find_first_of(' '))
			}
		}



	}

};

//User Customer::login(std::string username, std::string password) {
//	std::ifstream file;
//	bool found;
//	file.open("Accounts.txt", std::ios::in);
//	Customer account;
//	std::string line;
//	std::regex exp(username);
//	while (!found)
//	{
//		std::getline(file, line);
//		//if()
//	}
//	
//	//if(file.getline((char*)&account, sizeof(account)) == username)
//
//	file.read((char *)&account, sizeof(account));
//
//	
//
//}