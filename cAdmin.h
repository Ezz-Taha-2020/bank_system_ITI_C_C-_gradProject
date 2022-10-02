//admin.h


#ifndef ADMIN_H_
#define ADMIN_H_


#include "repo.h"

class admin : public user
{
	private:
		
	
	public:
		void getTotalNum(sAccBuffer_t * accList );//admin
		void changeAccStatus(sAccBuffer_t * accList);//admin
		void makeAdmin(sAccBuffer_t * accList, sAcount_t * curr);//admin
	//	void CreateAccount() {bankServices::CreateAccount();}

};



#endif /* ADMIN_H_ */