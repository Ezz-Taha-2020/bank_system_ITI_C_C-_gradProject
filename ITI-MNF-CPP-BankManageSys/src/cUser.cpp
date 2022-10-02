//cUser.cpp

#include <iostream>
#include <vector>
#include <sstream>		

#include "../inc/cUser.h"


cUser::cUser():needGuardian(false),isAdmin(false),
			status(1), balance(0), Age(0), pass(""), bankAccountID(""),
			nationalID(""), guardNationalID(""), fullName(""), fullAddress(""){}



void cUser::SetAccID(std::string tmp)
{
	this->bankAccountID=tmp;
}
std::string cUser::GetAccID()const
{
	return bankAccountID;
}



void cUser::SetNeedGuardian(bool f)
{
	needGuardian =f;
}
void cUser::SetguardNationalID(std::string tmp)
{
	guardNationalID=tmp;
}
std::string cUser::GetguardNationalID()const
{
	return guardNationalID;
}


void cUser::SetFullName(std::string tmp)
{
	fullName=tmp;
}
std::string cUser::GetFullName()const
{
	return fullName;
}


void cUser::SetFullAddress(std::string tmp)
{
	fullAddress=tmp;
}
std::string cUser::GetFullAddress()const
{
	return fullAddress;
}


void cUser::SetNationalID(std::string tmp)
{
	nationalID=tmp;
}
std::string cUser::GetNationalID()const
{
	return nationalID;
}


void cUser::SetPass(std::string tmp)
{
	pass=tmp;
}
std::string cUser::GetPass()const
{
	return pass;
}

void cUser::SetAGE(int tmp)
{
	Age=tmp;
}
int cUser::GetAGE()
{
	return Age;
}

void cUser::SetBalance(int tmp)
{
	balance=tmp;
}
int cUser::GetBalance()
{
	return balance;
}


void cUser::makeAdmin(bool tmp)
{
	isAdmin=tmp;
}

void cUser::SetAccStatus(int tmp)
{
	status = tmp;
}
int cUser::GetAccStatus()
{
	return status;
}

std::string cUser::ToString() {
		std::ostringstream oss;
		oss << "Account ID: " << bankAccountID << "\n";
		oss << "Name: " << fullName ;
		if (isAdmin)
			oss << " | Admin";
		oss << "\n";
		oss << "Balance: " << balance << "\n";
		oss << "Password: " << pass << "\n";
		return oss.str();
}


void cUser::create(const std::string &AccID) {
	SetAccID(AccID);

	std::string str;
	int tmp=0;


	std::cout << "Enter your full name: ";
	getline(std::cin , str); 
	// fullname
	SetFullName(str);

	std::cin.ignore();
	std::cout << "Enter your full Address: ";
	getline(std::cin , str); 
	// full Address
	SetFullAddress(str);
	
	std::cin.ignore();
	std::cout << "Enter your NationalID: ";
	getline(std::cin , str); 
	// NationalID
	SetNationalID(str);
	
	std::cin.ignore();
	std::cout << "Enter your Password: ";
	getline(std::cin , str); 
	// password
	SetPass(str);
	
	std::cin.ignore();
	std::cout << "Enter your Age: ";
	std::cin >> tmp; 
	// Age
	SetAGE(tmp);
	std::cin.ignore();
	if(Age<=21)
	{
		std::cin.ignore();
		std::cout << "Enter your Guardian nationalID : ";
		getline(std::cin , str); 
		SetguardNationalID(str);
	}
	std::cin.ignore();	
	std::cout << "Enter your Balance : ";
	std::cin.ignore();
	tmp=0;
	std::cin >> tmp; 
	// Balance
	SetBalance(tmp);
		std::cin.ignore();
	
}




