//cUser.h


#ifndef CUSER_H_
#define CUSER_H_


enum accountStatus{
	Active=1,
	Restricted,
	Closed
};

class cUser
{
	private:
		bool needGuardian;
		bool isAdmin;
		char status;
		int balance;
		int Age;
		std::string pass;
		std::string bankAccountID;
		std::string nationalID;
		std::string guardNationalID;
		std::string fullName;
		std::string fullAddress;

	public:
		cUser();
		~cUser() {}
		void SetAccStatus(int tmp);
		int GetAccStatus();
		void SetAccID(std::string tmp);
		std::string GetAccID()const;
		void SetFullName(std::string tmp);
		void SetFullAddress(std::string tmp);
		void makeAdmin(bool tmp);
		void SetNationalID(std::string tmp);
		void SetPass(std::string tmp);	
		void SetNeedGuardian(bool f);
		void SetAGE(int tmp);
		void SetBalance(int tmp);
		void SetguardNationalID(std::string tmp);
		std::string GetguardNationalID()const;
		std::string GetFullName()const;
		std::string GetFullAddress()const;
		std::string GetPass()const;
		int GetAGE();
		int GetBalance();
		std::string GetNationalID()const;
		void create(const std::string &AccID);
		std::string ToString();
		

};

	
#endif /* CUSER_H_ */