#pragma once
//#include "User.h"
#include "Customer.h"
class Manager : public User {
public:
	void processOrders(CartItem);
	void updateCustomerInfo(Customer);
	void deleteAccount(User);
	void modProductDetails();
	void checkoutCustomer();

	
};
