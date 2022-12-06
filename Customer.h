#pragma once
#include "User.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>
#include <cstring>



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

public:
	//virtual void updateCustInfo(Customer);
	//virtual void orderProduct();
	
	//User login(std::string, std::string);

	bool test(std::string username, std::string password) {
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
						std::vector<std::string> customerInfo = split(accountinfo);
						
						

						Customer cust;
						cust.customerName = customerInfo[0];
						cust.password = customerInfo[1];
						cust.accessLevel = customerInfo[2];
						
						return true;
					}
				}
			}
		}

		else
			return false;
		
	}

	std::vector<std::string> split(char* things)
	{
		char* accountinfo;
		std::vector<std::string> stuff;
		accountinfo = std::strtok(things, " ");
		while (accountinfo != NULL)
		{
			stuff.push_back(accountinfo);
			accountinfo = std::strtok(NULL, " ");
		}

		return stuff;
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