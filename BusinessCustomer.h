#pragma once
#include "Customer.h"

class BusinessCustomer:public Customer {
	std::string salesRepName;
	std::string phoneNumber;
	std::string companyName;
};
