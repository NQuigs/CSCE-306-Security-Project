#pragma once

#include <fstream>
#include <sstream>
#include <cstring>
#include <regex>
#include "User.h"
#include <iostream>
#include "Product.h"
#include "Services.h"





using namespace System::Data;


//#define MAX_LINES 100
//#define MAX_LEN 1000


class Customer : public User {
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


	void setName(std::string name)
	{
		customerName = name;
	}
	


	std::string getCustName()
	{
		return customerName;
	}

	//
	//std::vector<std::string> stringSplit(std::string custInfo)
	//{
	//	int count = 0;
	//	std::vector<std::string> customerStuff;
	//	for (int i = 0; i < custInfo.length(); i++)
	//	{
	//		if (custInfo[i].Equals(' '))
	//		{
	//			customerStuff.push_back(custInfo.substr(0, i - 1));
	//			//custInfo = custInfo.erase(custInfo.begin(), custInfo.find_first_of(' '))
	//		}
	//	}



	//}

	

	void getInfoForFile(Customer cust, std::string fileName, Product* prod = nullptr, Services* serv = nullptr)
	{

		std::vector<std::string> productDetails;
		std::vector<std::string> serviceDetails;
		std::vector<std::string> custInfo;
		std::string custName = "";

		std::ofstream outFile;
		outFile.open(fileName);

		if (prod != nullptr)
			productDetails = prod->getProductDetails();

		if (serv != nullptr)
			serviceDetails = serv->getServiceDetails();

		if (prod == nullptr && serv == nullptr)
			custInfo = cust.getCustInfo();

		else
			custName = cust.getCustName();
		
		util.write(fileName, custName, custInfo, productDetails, serviceDetails);

	}


	//StringDictionary getOrderInfo(Customer* cust = nullptr)
	//{
	//	std::string data;
	//	std::ifstream myFile;
	//	StringDictionary sd;

	//	myFile.open("OrderInfo.txt");
	//	std::unordered_map<std::string, std::string> test;
	//	if (myFile.is_open())
	//	{
	//		while (myFile.good())
	//		{
	//			if (cust != nullptr)
	//			{
	//				std::getline(myFile, data, ' ');
	//				sd.Add("CustomerName", msclr::interop::marshal_as<System::String^>(data));
	//				std::getline(myFile, data, ' ');
	//				sd.Add("ProductName", msclr::interop::marshal_as<System::String^>(data));
	//				std::getline(myFile, data, ' ');
	//				sd.Add("ProductPrice", msclr::interop::marshal_as<System::String^>(data));
	//				
	//				IEnumerable<int>
	//				

	//				return ;
	//			}
	//		}

	//	}
	//}



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