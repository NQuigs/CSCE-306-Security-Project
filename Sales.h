#pragma once
#include "Customer.h"
#include "ShoppingCart.h"

class Sales : public User
{
public: 
	void processOrders(CartItem, std::string);
	void updateCustomerInfo(Customer);
	void deleteAccount(User);
	void modProductDetails();
	void checkoutCustomer();
	void createAccount(User);
};

void Sales::processOrders(CartItem cartItem, std::string username)
{
	std::string fileName = "PendingOrders.txt";

	std::vector<std::string> orderInfo = util.read(fileName, username);
	

}

void Sales::updateCustomerInfo(Customer cust)
{

}

void Sales::deleteAccount(User user)
{

}

void Sales::modProductDetails()
{

}

void Sales::checkoutCustomer()
{

}

void Sales::createAccount(User user)
{

}