//main.cpp

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include "inc/cUser.h"
#include "inc/repo.h"




template<typename T>
void read_File(std::map<std::string, T*> &objInfoMap)
{
    // File pointer
    std::ifstream fin;
  
    // Open an existing file
	fin.open("addAccounts.txt");
    
  
    // Read the Data from the file
    // as std::string Vector
    std::vector<std::string> row;
    std::string line, word, temp;
  
    while (std::getline(fin, line)) {
  
        row.clear();
  
        // read an entire row and
        // store it in a std::string variable 'line'
        //std::getline(fin, line);
  
        // used for breaking words
        std::stringstream s(line);
  
        // read every column data of a row and
        // store it in a std::string variable, 'word'
        while (getline(s, word, ',')) {
  
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
		T* obj=new T();
  
        // Account Id
        obj->SetAccID(row[0]);     
		 
		// fullname
		obj->SetFullName(row[1]);
		
		// full Address
		obj->SetFullAddress(row[2]);
		
		// NationalID
		obj->SetNationalID(row[3]);
		
		// password
		obj->SetPass(row[4]);
		
		// Age
		obj->SetAGE(stoi(row[5]));
		// Balance
		obj->SetBalance(stoi(row[6]));
		
		// Account Status
		obj->SetAccStatus(stoi(row[7]));
		
		//need Guard
		obj->SetNeedGuardian( (row[8]=="t") ) ;
		obj->makeAdmin((row[9]=="t"));
		objInfoMap[obj->GetAccID()] = obj;
		
    }
}










template<typename T>
class cManage
{
	private:
		T* currentObj = nullptr;
		T* newObj = nullptr;
		std::map<std::string, T*> m_objInfoMap;

		void FreeLoadedData() {
			// std::map<std::string, T* >::iterator it;
			// for(it = m_objInfoMap.begin();  it < m_objInfoMap.end() ; it++ )
			// {
				// delete it.second;
			// }
			for (auto it : m_objInfoMap) {
				delete it.second;
			}
			
			
			m_objInfoMap.clear();
			currentObj = nullptr;
			newObj = nullptr;
		}
		
	public:
		cManage() {}

		~cManage() {
			std::cout<<"Destuctor: Manager\n";
			FreeLoadedData();
		}
		
		void LoadDatabase(){
			std::cout<<"Manager: LoadDatabase\n";

			FreeLoadedData();
			
			read_File( m_objInfoMap );
			
			
		}

		void AccessSystem() {
			int choice = ShowReadMenu( { "Login", "Sign Up" });
			if (choice == 1)
				DoLogin();
			else
				DoSignUp();
		}

		void DoLogin() {
			LoadDatabase();

			while (true) {
				std::string accID, pass;
				std::cout << "Enter user Account ID : ";
				std::cin >> accID;
				std::cout << "Enter user Account Password: ";
				std::cin >>pass;

				if (!m_objInfoMap.count(accID)) {
					std::cout << "\nInvalid user user_name or password. Try again\n\n";
					continue;
				}
				cUser* user_exist = m_objInfoMap.find(accID)->second;
				if (user_exist->GetAccStatus() != Active) {
					std::cout << "\nSorry!! You Account not Active\n ";
					return ;			
				}
				if (pass != user_exist->GetPass()) {
					std::cout << "\nInvalid user accID or password. Try again\n\n";
					continue;
				}
				
				currentObj = user_exist;
				break;
			}
		}

		void DoSignUp() {
			LoadDatabase();
			std::string accID;
			newObj = new cUser();
			
			std::string str;

			while (true) {
				std::cout << "Enter account ID. (No spaces): ";
				std::cin >> accID;

				if (m_objInfoMap.count(accID))
				{
					std::cout << "Already used. Try again\n";
					system("pause");
					return;
				}
				else
					break;
			}
		
			newObj->create(accID);
			m_objInfoMap[newObj->GetAccID()] = newObj;
			currentObj=newObj;
		}


		T* GetCurrentUser() {
			return currentObj;
		}
		
		T* GetAccount(std::string accID) {
			LoadDatabase();
		
			while (true) {
				if (!m_objInfoMap.count(accID)) {
					std::cout << "\nuser not found. Try again\n\n";
					return nullptr;
					//return new cUser;
				}
				return m_objInfoMap.find(accID)->second;
				//break;
			}
		}

		void ShowAll() {
			for (auto const &pair: m_objInfoMap) {
				std::cout << "{\n" << pair.first << ": " << pair.second ->ToString() << "}\n";
			}
			system("pause");
		}
};


class UserView {
private:
	cManage<cUser> &users_manager;
public:
	UserView(cManage<cUser> & users_manager) :users_manager(users_manager) {}

	void DisplayUser() {
		system("CLS");
		const cUser* user = users_manager.GetCurrentUser();
		std::cout << "\n\nHello " << user->GetFullName() << " | User View\n";

		std::vector<std::string> menu;
		menu.push_back("View Profile");
		menu.push_back("Make Transaction");
		menu.push_back("Change Account Password");
		menu.push_back("Get Cash");
		menu.push_back("Deposit in Account");
		menu.push_back("Back to previous Menu");
		menu.push_back("Logout");

		while (true) {
			int choice = ShowReadMenu(menu);
			switch(choice)
			{
				case 1:
					system("cls");
					ViewProfile() ;
						
					break;
				case 2:
					system("cls");
					makeTransaction();
					break;
				case 3:
					system("cls");
					changeAccountPassword();
					break;
				case 4:
					system("cls");
					getCASH();//user
					break;
					
				case 5:
					system("cls");
					Deposit();
					break;
					
				case 6:
					return;
				case 7:
					exit(1);
			}

		}
	
	}

	void ViewProfile() {
		cUser* user = users_manager.GetCurrentUser();

		std::cout << "\n" << user->ToString() << "\n";
		system("pause");
	}

	
	void DisplayAdmin() {
		system("CLS");
		cUser* user = users_manager.GetCurrentUser();

		std::cout << "\n\nHello " <<  user->GetFullName() << " | Admin View\n";
		std::vector<std::string> menu;
		menu.push_back("View Profile");
		menu.push_back("Open Existing Account");
		menu.push_back("Create New Account");
		menu.push_back("Make New Admin");
		menu.push_back("Change Account Status");
		menu.push_back("Show all account");
		menu.push_back("Logout");


		while (true) {
			int choice = ShowReadMenu(menu);
			switch(choice)
			{
				case 1:
					system("cls");
					ViewProfile() ;
					break;
				case 2:
					system("cls");
					DisplayUser();
					break;
				case 3:
					system("cls");
					users_manager.DoSignUp();
					break;
				case 4:
					system("cls");
					makeAdmin();
					break;
					
				case 5:
					system("cls");
					changeAccountStatus();
					break;
					
				case 6:
					users_manager.ShowAll();
					break;
				case 7:
					exit(1);
			}
		}
		
	}


#if 1//User	
	void makeTransaction() {
		cUser* user = users_manager.GetCurrentUser();
		
	
		std::string AccID;
		int bal;
		
		std::cout << "Enter user ID you want to send : ";
		std::cin >> AccID;
		cUser* rec =users_manager.GetAccount(AccID);
		std::cout << "Enter te Amount of money : ";
		std::cin >> bal;
		if(bal > user->GetBalance() )
		{
			std::cout << "Sorry you dont have enough money ";
			system("pause");
			return;
		}
		if (rec != nullptr) {
			rec = users_manager.GetAccount(AccID);
			rec->SetBalance(rec->GetBalance()+bal);
			user->SetBalance(user->GetBalance()-bal);
			system("pause");
			//return;
		}
	}

	void changeAccountPassword()
	{
		cUser* tmp = users_manager.GetCurrentUser();
		std::string oldPass;
		
		std::cout<<"please, Enter your OLD Password : "<<std::endl;
		std::cin>>oldPass;
		
		std::cout<<"\n----- Change Password -----\n ";
		if( tmp->GetPass() == oldPass )
		{
			std::string newPass;
			std::cout<<"please, Enter your new Password : \n";
			std::cin>>newPass;
			tmp->SetPass(newPass);
		}
		else{
			system("cls");
			std::cout<<"\nSorry!! You entered wrong password.\n ";
			system("pause");
			return;
		}
		std::cout<<"Password Change Successfully.";
		system("pause");
		return ;
	}

	void getCASH() {
		cUser* user = users_manager.GetCurrentUser();
		//const cUser* rec = nullptr;
	
		int bal;
		std::cout << "Enter te Amount of money : ";
		std::cin >> bal;
		if(bal > user->GetBalance())
		{
			std::cout << "Sorry you dont have enough money ";
			system("pause");
			return;
		}else {
			user->SetBalance(user->GetBalance() - bal);
			system("pause");
			return;
		}
	}
	
	void Deposit() {
		cUser* user = users_manager.GetCurrentUser();
		//const cUser* rec = nullptr;
	
		int bal;
		std::cout << "Enter the Amount of money : ";
		std::cin >> bal;
		user->SetBalance(user->GetBalance() + bal);
	}
#endif

#if 1//Admin
	void makeAdmin()
	{
		std::string AccID;
		std::cout<< "Enter user ID you want to make him an admin : ";
		std::cin >> AccID;
		if (users_manager.GetAccount(AccID) != nullptr) {
			users_manager.GetAccount(AccID)->makeAdmin(true);
		}
	}
	
	void changeAccountStatus()
	{
		std::string AccID;
		std::cout << "Enter user ID you want to change status : ";
		std::cin >> AccID;
		if (users_manager.GetAccount(AccID) != nullptr) {
			std::vector<std::string> menu;
			menu.push_back("Active");
			menu.push_back("Ristricted");
			menu.push_back("Closed");
			users_manager.GetAccount(AccID)->SetAccStatus(ShowReadMenu(menu));
		}
	}
	
	
	
#endif
	
};

class BankSystem {
	private:
		cManage<cUser> *userMng;
		cManage<cUser> *adminMng;///////cAdmin

		void LoadDatabase() {
			userMng->LoadDatabase();
			adminMng->LoadDatabase();
		}

	public:
		BankSystem() :userMng(new cManage<cUser>()) , adminMng(new cManage<cUser>()) 
		{}

		~BankSystem() {
			std::cout << "Destuctor: BankSystem\n";

			if (adminMng != nullptr) {
				delete adminMng;
				adminMng = nullptr;
			}
			if (userMng != nullptr) {
				delete userMng;
				userMng = nullptr;
			}
		}

		void Run() {	// only public one
			LoadDatabase();

			while (true) {
				int ch = ShowReadMenu( { "Admin : ", "User : " });
				
				switch(ch)
				{
					// Let's make for every user, its own viewer class: 
					case 1:{
						adminMng->AccessSystem();
						UserView view( *adminMng);
						view.DisplayAdmin();
					break;}
					case 2:
						userMng->AccessSystem();
						UserView view(*userMng);
						view.DisplayUser();
						break;
				//	default:std::cout << "Wrong INPUT!!! . ";
						//break;
				}
		
			}
		}
};








int main(void)
{
	BankSystem site;

	site.Run();

	return 0;
}


