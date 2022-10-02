//bankServices.h


#ifndef BANKSERVICES_H_
#define BANKSERVICES_H_


#include "repo.h"


class bankServices
{
	protected:
		
	public:
	//	listStatus_t AccountList_init(sAccBuffer_t * accList , sAcount_t * account, u32 length);
	
		listStatus_t List_isFull(sAccBuffer_t * accList );
		sAcount_t * getByAccountID(sAccBuffer_t * accList);
		char checkByNationalID(sAccBuffer_t * accList , char* id);
		sAcount_t * login(sAccBuffer_t * accList);
		void ShowAll(sAccBuffer_t * fifo);
		void printAccount(sAcount_t *current);
		listStatus_t CreateAccount(sAccBuffer_t * accList); 
};




#endif /* BANKSERVICES_H_ */