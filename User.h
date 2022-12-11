#pragma once
#include "CartItem.h"
#include "Utilities.h"

class User {
protected:
	std::string userID;
	std::string password;
	std::string accessLevel;
	std::string phoneNum; //changed from long long int to string
	Utilities util;
public:

#pragma region setters
	void setUserId(std::string id)
	{
		userID = id;
	}

	void setPassword(std::string pass)
	{
		password = pass;
	}

	void setAccessLevel(std::string level)
	{
		accessLevel = level;
	}

	void setPhoneNum(std::string num)
	{
		phoneNum = num;
	}
#pragma endregion

#pragma region getters
	std::string getUserId()
	{
		return userID;
	}

	std::string getPassword()
	{
		return password;
	}

	std::string getAccessLevel()
	{
		return accessLevel;
	}

	std::string getPhoneNum()
	{
		return phoneNum;
	}
#pragma endregion
	
	//virtual User login(std::string, std::string);
	//virtual float taxCalc();
	//virtual void logout();
	//virtual CartItem checkStatus();
	//virtual std::string returnAccountInfo(User);
};
