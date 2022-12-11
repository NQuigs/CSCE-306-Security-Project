#pragma once
#include "Customer.h"

class GovernmentCustomer :public Customer {
	std::string govPosition;
	std::string salesRepName;
	std::string salesRepPhone;
};