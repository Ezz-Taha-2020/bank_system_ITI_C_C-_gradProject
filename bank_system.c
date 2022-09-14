// Graduation project ------------IMT Bank system--------------
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//structs ,strings,swtich,while,file I/O not used pointers,linked lists

//problems with scanf,structs size,

struct user{
	
	//if we choose name[100] the number is problem with details in client mode
	char name[50];
	char address[50];
	char natID[50];
	char guardian[50];
	char gaurdID[50];
	
	char bankID[50];
	char password[50];
	char status[50];
	
	// int bankID; 
	// int password;
	// char* status; // I don't know why use pointer ,it works but char status[50] = "active" not work
	

	float balance;
	int age;

};
struct user usr,usr1;
FILE *fp;
char filename[50],pword[50],oldpword[50];
char bankID[50];
int opt,admin,client,exist,x,i=0;
char cont = 'y';
float amount;

//functions used 
void createAccount(void);
int clientMode(void);
void transaction(void);
void Password(void);
void status(void);
void GetCash(void);
void Deposite(void);
void balance(void);
char returnMenu(void);

int main(void){
	

	
	do{
		system("cls");
		printf("\nWelcome to IMT Bank system");
		printf("\n what do you want to do?");
		printf("\n\n1. enter admin window"); //admin mode
		printf("\n2. enter client window");   //client  mode
		printf("\n\nYour choice:\t");
		scanf("%d",&opt);
		
		if(opt == 1){ //admin mode
			//function admin mode
			cont = 'y';
			while(cont == 'y'){
				system("cls");
				printf("\nPress 1 to create new account");
				printf("\nPress 2 to open existing account");
				printf("\nPress 3 to Exist system");
				printf("\nYour choice:\t");
				scanf("%d",&admin);
				switch(admin){
					case 1: // create account
						createAccount();
						break;
								
					
					case 2: //open existing account
						system("cls");
						printf("\nPlease Enter Bank account Id:\t");
						scanf("%s",bankID);
						printf("\nPassword:\t");
						scanf("%s",pword);
						
						strcpy(filename,bankID);
						fp = fopen(strcat(filename, ".dat" ),"r");
						if(fp == NULL)
							printf("\nAccount ID not registered");
						else{
							fread(&usr,sizeof(struct user),1,fp);
							fclose(fp);
							
							if(!(strcmp(pword,usr.password))) //gives 0 when it's equal
							{
								printf("\nPassword matched");
								cont = 'y';
								while(cont == 'y'){

									client= clientMode();
									switch(client){
										case 1:
											transaction(); //function transcation;
											break;
										
										case 2:
											status();
											break;
										
										case 3:
											GetCash();
											break;
										
										case 4:
											Deposite();
											break;
										
										case 5:
											balance();
											break;
										
										case 6:
											returnMenu();
											break;
										default:
											printf("\nPlease enter a valid number from 1 to 6");
											break;
										
									}
									if(client != 6){
										printf("\nDo you want to continue in admin mode[y/n]:\t");
										scanf("%s",&cont); 
									}
											
								}
										
							} //for invalid password
							else{
										printf("\nInvalid password");
							}
						}
							
						break;
					
					case 3: //exist system
						returnMenu();
						break;
					
					default:
						printf("\nPlease enter valid number from 1 to 3");
						break;
				}
				
				if(admin != 3){
					printf("\n\nDo you want to continue in admin mode:[y/n]\t");
					scanf("%s",&cont);
				}

			}
			
		}

		
		if(opt == 2){ //client mode
			system("cls");
			printf("\nPlease Enter Bank account Id:\t");
			scanf("%s",bankID);
			printf("\nPassword:\t");
			scanf("%s",pword);
			
			strcpy(filename,bankID);
			fp = fopen(strcat(filename, ".dat" ),"r");
			if(fp == NULL)
				printf("\nAccount ID not registered");
			else{
				fread(&usr,sizeof(struct user),1,fp);
				fclose(fp);
				

				if(!(strcmp(pword,usr.password))) //gives 0 when it's equal
				{
					printf("\nPassword matched");
					cont = 'y';
					while(cont == 'y'){
						client= clientMode();

						
						switch(client){
							case 1: //make transaction and restricted
								transaction();
								break;
									
							case 2: // password changing ******
								Password();
								break;
													
							case 3: // get cash
								GetCash();
								break;
							case 4: //Deposite cash
								Deposite();
								break;
								
							case 5: //balance inquiry
								balance();
								break;
								
							case 6: //return to main menu
								returnMenu();
								break;
													
							default:
								system("cls");
								printf("\nplease enter valid number from 1 to 6");
								break;
						}
						if(client != 6){
							printf("\nDo you want to continue in client mode[y/n]:\t");
							scanf("%s",&cont); 
						}
						
					}
					
				} //for invalid password
				else{
					printf("\nInvalid password");
				}
			}
		}
		
		printf("\n\npress any number to return main menu or 1 to exist:\t");
		scanf("%d",&i);
	}while(i!=1);
	
	return 0;
}

//function create account
void createAccount(void){
	system("cls");
	printf("\nEnter your name:\t");
	scanf("%s",usr.name);
	printf("Enter your address:\t");
	scanf(" %s",usr.address);				
	printf("Enter your age:\t");
	scanf("%d",&usr.age);
	if(usr.age < 25){
		printf("Enter your Gaurdian name:\t");
		scanf("%s",usr.guardian);
		printf("Enter your guardian national ID:\t");
		scanf("%s",usr.gaurdID);				
	}
	else{
		printf("Enter your national ID:\t");
		scanf("%s",usr.natID);
	}
	printf("Enter your balance:\t");
	scanf("%f",&usr.balance);					
	
	printf("Enter your bank ID:\t");
	scanf("%s",usr.bankID);
	printf("Enter your password:\t");
	scanf("%s",usr.password);
	printf("Enter your account status:\t");
	scanf("%s",usr.status);
	//error in 3 next lines
	// usr.bankID = rand();
	// usr.password = rand();
	// usr.status = "active"; //error
	
	strcpy(filename,usr.bankID);
	fp = fopen(strcat(filename,".dat"), "w" );
	fwrite(&usr,sizeof(struct user),1,fp);
	if(fwrite != 0){
		printf("\n\nAccount successfully registered");
	}
	else{
		printf("\n\nSomething went wrong, please try again");
	}
	fclose(fp);
}

//function client mode
int clientMode(void){
	system("cls");
	printf("\n\t Welcome %s",usr.name);
	printf("\n\nPress 1 to make transaction");
	printf("\nPress 2 to change account status");
	printf("\nPress 3 to get cash");
	printf("\nPress 4 to deposit in account");
	printf("\nPress 5 to balance inquiry");
	printf("\nPress 6 to return main menu");
	printf("\nYour Choice:\t");
	scanf("%d",&exist);
	return exist;
}

//function transaction
void transaction(void){
	system("cls");
	printf("\nPlease enter the bank account ID to transfer the amount:\t");
	scanf("%s",bankID);
	printf("\nPlease enter the amount to transfer:\t");
	scanf("%f",&amount);
	
	//check bankID number is registerd
	strcpy(filename,bankID);
	fp = fopen(strcat(filename,".dat"),"r");
	if(fp == NULL)
		printf("\nAccount ID not registered");
	else{
		fread(&usr1,sizeof(struct user),1,fp);
		fclose(fp);
		
		if( !(strcmp(usr.status,"active")) && !(strcmp(usr1.status,"active")) ){
			//can't equals 2 strings with using == operator ,I don't know
			//gives 0 when 2 strings are equals
			if(amount > usr.balance)
				printf("\nInsufficient balance");
			else{
				
				//reserve the amount for user 1
				fp = fopen(filename,"w");
				usr1.balance += amount ;
				fwrite(&usr1,sizeof(struct user),1,fp);
				fclose(fp);
				
				if(fwrite != NULL)
					printf("\nYou have succesfully transfered %.2f EGP to %s",amount,bankID);
				
					//minus the amount for origin user
					strcpy(filename,usr.bankID);
					fp = fopen(strcat(filename,".dat"),"w");
					usr.balance -= amount;
					fwrite(&usr,sizeof(struct user),1,fp);
					fclose(fp);
			}
		}
		else{
			printf("\nYou won't be able to perform this transaction as account is closed or restricted");
		}
			
	}
}

//function password 
void Password(void){
	system("cls");
	printf("\nPlease enter your old password:\t");
	scanf("%s",oldpword);
	if(!(strcmp(oldpword,usr.password))){
		printf("\nPlease enter the new password to change:\t");
		scanf("%s",pword);
		
		fp = fopen(filename,"w");
		strcpy(usr.password,pword);
		fwrite(&usr,sizeof(struct user),1,fp);
		if (fwrite != NULL)
			printf("\nPassword succesfully changed");
		// fclose(fp);
		
	}
	else{
		printf("\nPlease enter a valid password");
		
	}
}

//function change status
void status(void){
	printf("Hello\n");
}
//function getcash
void GetCash(void){
	system("cls");
	printf("\nplease enter the amount to withdrawl:\t");
	scanf("%f",&amount);
	if(amount > usr.balance){
		printf("\nInsuffuient balance");
	}
	else{
		usr.balance -= amount;
		
		//reserve the balance for file at all
		fp = fopen(filename,"w");
		fwrite(&usr,sizeof(struct user),1,fp);
		if (fwrite != NULL)
			printf("\nYou have withdrawn %0.2f EGP successfully",amount);
		fclose(fp);								
	}
}

//function deposite
void Deposite(void){
	
	system("cls");
	printf("\nEnter the amount to deposit:\t");
	scanf("%f",&amount);
	usr.balance += amount;
	
	
	//reserve the deposite for next compiling
	fp = fopen(filename,"w");
	fwrite(&usr,sizeof(struct user),1,fp);
	if(fwrite != NULL)
		printf("\nSuccessfully Deposite");
	fclose(fp);
}

//function balance inquiry
void balance(void){
	system("cls");
	printf("\nYour current balance is %.2f EGP",usr.balance);

}


//function return menu
char returnMenu(void){
	cont = 'n';
	return cont;
}