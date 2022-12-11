#pragma once
#include "Customer.h"

class ShoppingCart {
	int numberOfItems;
public:
	void addItem(Customer, Product, Services);
	void deleteItem();
};

void ShoppingCart::addItem(Customer cust, Product prod, Services serv)
{
	numberOfItems++;
	
	std::vector<std::string> products = prod.getProductDetails();
	std::vector<std::string> service = serv.getServiceDetails();

	std::ofstream myfile;
	myfile.open("example.txt");
	myfile << cust.getCustName() + " ";

	if (products.size() > 0)
	{
		myfile << "Products ordered: ";
		for(int i = 0; i < products.size(); i++)
			myfile << products[i] + " ";
	}

	if (service.size() > 0)
	{
		myfile << "Services ordered: ";
		for (int i = 0; i < service.size(); i++)
			myfile << service[i] + " ";
	}

	myfile << "\n";

	myfile.close();

}