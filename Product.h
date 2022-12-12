#pragma once
#include <string>
#include <vector>

class Product {
	std::string productName;
	int productNum;
	std::string manufacturer;
	float price;
	std::string productDescription;

public:
	std::vector<std::string> getProductDetails();
};


std::vector<std::string> Product::getProductDetails()
{
	std::string productNumber = std::to_string(productNum);
	std::string prodPrice = std::to_string(price);

	std::vector<std::string> productDetails;

	if (productName.length() > 0)
	{
		productDetails.push_back(productName);
		productDetails.push_back(productNumber);
		productDetails.push_back(manufacturer);
		productDetails.push_back(prodPrice);
		productDetails.push_back(productDescription);
	}

	return productDetails;

}