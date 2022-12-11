#pragma once


class Services {
	std::string serviceType;
	int packageNum;
	std::string packageDescription;
	float packagePrice;
public:
	std::vector<std::string> getServiceDetails();
};

std::vector<std::string> Services::getServiceDetails()
{
	std::string package = std::to_string(packageNum);
	std::string packageCost = std::to_string(packagePrice);

	std::vector<std::string> serviceDetails;

	serviceDetails.push_back(serviceType);
	serviceDetails.push_back(package);
	serviceDetails.push_back(packageDescription);
	serviceDetails.push_back(packageCost);

	return serviceDetails;
}