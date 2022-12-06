#pragma once
#include <string>
#include <vector>
#include "Customer.h"
#include "Product.h"
#include "Services.h"

class Utilities
{
public:
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

	void write(Customer cust, std::string fileName, Product* prod = nullptr, Services* serv = nullptr)
	{

		std::vector<std::string> productDetails;
		std::vector<std::string> serviceDetails;
		std::vector<std::string> custInfo;

		std::ofstream outFile;
		outFile.open(fileName);

		if(prod != nullptr)
			productDetails = prod->getProductDetails();
		
		if (serv != nullptr)
			serviceDetails = serv->getServiceDetails();

		std::string data = "";
		

		if (productDetails.size() == 0 && serviceDetails.size() == 0)
		{
			custInfo = cust.getCustInfo();
			for (int i = 0; i < custInfo.size(); i++)
			{
				data.append(custInfo[i] + " ");
			}
		}

		else if (productDetails.size() != 0 && serviceDetails.size() == 0)
		{
			data.append(cust.getCustName() + " ");

			for (int i = 0; i < productDetails.size(); i++)
			{
				data.append(productDetails[i] + " ");
			}
			
		}

		else if (productDetails.size() == 0 && serviceDetails.size() != 0)
		{
			data.append(cust.getCustName() + " ");

			for (int i = 0; i < serviceDetails.size(); i++)
			{
				data.append(serviceDetails[i] + " ");
			}
		}

		else
		{
			data.append(cust.getCustName() + " ");
			for (int i = 0; i < productDetails.size(); i++)
			{
				data.append(productDetails[i] + " ");
			}

			for (int i = 0; i < serviceDetails.size(); i++)
			{
				data.append(serviceDetails[i] + " ");
			}
		}

		outFile << data << "\n";
	
		outFile.close();
	}

	
};
