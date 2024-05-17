#include <conio.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h> //Includes the coord fun, STD_output_handle

// Prototype of all the functions
void emp_menu();      //Line 75
void cust_menu();     //Line 122
void new_account();     //Line 204
void accUnderProcess();    //Line 259
void bankEmp();      //Line 266
void cust_login();    //Line 307
void add_del_acc();        //Line 346
void profile();         //Line 431
void transact_query();    //Line 465
void modify_cust();			//Line 486
void query();				//Line 581
void credit_money();	//Line 614
void debit_money();	    //Line 656
void transfer_money();   //Line 710

//Global Variable
int main_exit;

// Structure for customer details
struct customer{
	char fname[20];
    char lname[20];
    char fathname[20];
    char mothname[20];
    char address[50];
    char typeaccount[20];
    int date, month, year;
    long long pnumber;
    long long aadharnum;
    long long account_no;
}cust;

// Structure for Money Transfer
struct money {
	long long account_no;
	float initial_money;
    long long account_no_2;
    float initial_money_2;
}amount;

//Structure for username and password
struct userdetail {  //Done
	char username[10];         
    char password[20];
}usdt;

// Declaring gotoxy function for setting cursor position
void gotoxy(int x, int y){ //Done
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void fordelay(int j){   //Done
    int i;
    for(i=0;i<j;i+=2)
         i--;
}
   
void close_menu(){   //Done
	system("cls");
	gotoxy(30, 8);
    printf("!!!!!THANK YOU FOR YOUR TIME, PLEASE VISIT AGAIN!!!!!\n");
}
//Bank Clerk Menu
void emp_menu(){
    int choice;
    previous:
    system("cls");
    gotoxy(40, 2);
    printf("*****MAIN MENU*****\n");
    gotoxy(39, 3);
    printf("1. Add and Delete Customer account\n");
    gotoxy(39, 4);
    printf("2. Modify Customer account\n");
    gotoxy(39, 5);
	printf("3. Query Report\n");
	gotoxy(39, 6);
	printf("4. Credit Money\n");
	gotoxy(39, 7);
	printf("5. Debit Money\n");
	gotoxy(39, 8);
	printf("6. Exit");
	printf("\n\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
			add_del_acc();
        	break;
        case 2:
			modify_cust();
        	break;
        case 3:
			query();
        	break;
        case 4:
			credit_money();
        	break;
        case 5:
			debit_money();
        	break;
        case 6:
			close_menu();
			exit(0);
        	break;
        default:
        	printf("!!!PLEASE ENTER A VALID INPUT!!!");
        	fordelay(100000000);
        	goto previous;
	}
}
//Customer menu
void cust_menu(){
    int choice;
    previous:
    system("cls");
    gotoxy(40, 1);
    printf("*****MAIN MENU*****");
    gotoxy(39, 3);
    printf("1. Personal Profile");
    gotoxy(39, 4);
    printf("2. Transfer Money");
    gotoxy(39, 5);
	printf("3. Transaction Query");
	gotoxy(39, 6);
	printf("4. Exit");
	printf("\n\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
			profile();
        	break;
        case 2:
			transfer_money();
        	break;
        case 3:
			transact_query();
        	break;
        case 4:
			close_menu();
			exit(0);
        	break;
        default:
        	printf("!!!PLEASE ENTER A VALID INPUT!!!");
        	fordelay(100000000);
        	goto previous;
        }
}
//Driver code 
int main(){  //Done
    int choice, i;
    //For delay
    gotoxy(45,10);
    printf("LOADING");
    for(i=0;i<6;i++){
    	fordelay(10000000);
    	printf(".");
	}
	//Goto statement is sent here
    previous:
    system("cls");
    //Creating the homepage
    gotoxy(40, 2);
    printf("*********WELCOME TO KDAMBR BANK*********");
    gotoxy(40, 7);
    printf("1.... Official Login(For Bank Employee)");
    gotoxy(40, 8);
    printf("2.... Personal Login(For Customer)");
    gotoxy(40, 9);
    printf("3.... EXIT");
    
    gotoxy(20,12);
    printf("\nPLEASE ENTER YOUR PREFERENCE..");
    scanf("%d", &choice);

    switch (choice) {
	    case 1:
	        bankEmp();
	        break;
	    case 2:
	        cust_login();
	        break;
	    case 3:
	    	close_menu();
	        exit(0);
	        break;
	    default:
	    	printf("PLEASE ENTER A VALID CHOICE");
	    	fordelay(100000000);
	    	goto previous;
	}
    getch();
}
// Function to create new accounts of Customers
void new_account(){   //Done
	int i=0;
	char temp_pwd; 
    system("cls");
	gotoxy(40,2);
	printf("!!!!!CREATE ACCOUNT!!!!!");
	gotoxy(0,3);
	printf("\n\n*****Please fill your details correctly*****\n\t*****DO NOT USE SPACES*****");
	printf("\n\nFIRST NAME:\t");
	scanf("%s", cust.fname);
			    
	printf("LAST NAME:\t");
	scanf("%s", cust.lname);
			    
	printf("FATHER's NAME:\t");
	scanf("%s", cust.fathname);
			 
	printf("MOTHER's NAME:\t");
	scanf("%s",cust.mothname);
			 
	printf("ADDRESS:\t");
	scanf("%s", cust.address);
			 
	printf("ACCOUNT TYPE:\t");
	scanf("%s", cust.typeaccount);
			 
	printf("DATE OF BIRTH(DD/MM/YYYY):\n");
	printf("DATE- ");
	scanf("%d", &cust.date);
	printf("MONTH- ");
	scanf("%d", &cust.month);
	printf("YEAR- ");
	scanf("%d", &cust.year);
			 
	printf("AADHAR NUMBER:\t");
	scanf("%lld", &cust.aadharnum);
			 
	printf("PHONE NUMBER:\t");
	scanf("%lld", &cust.pnumber);
	
	printf("\n\t***FOR OFFICIALS ONLY***");
	printf("\nProvide an ACCOUNT NUMBER:\t");
	scanf("%lld", &cust.account_no);
	printf("Provide a USERNAME:\t");
	scanf("%s", usdt.username);
	printf("Provide a PASSWORD(Upto 20 characters):\t");
	// Taking password in the form of stars
	while((temp_pwd=_getch())!=13) {    //13 is the ascii value of \n 
	    usdt.password[i]=temp_pwd;
	    i++;
	    printf("*");
	}
	usdt.password[i]=NULL;
}
	
void accUnderProcess(){   //Done
    system("cls");
    printf("PLEASE WAIT.......");
    fordelay(1000000000);
    printf("\n\n***ACCOUNT HAS BEEN SUCCESSFULLY CREATED***...");
}

void bankEmp(){   //Done
	char username[20], password[20], temp_pwd;
	int i=0;
	FILE *ptr_check;
	ptr_check=fopen("bankempdatabase.txt","r");
	
	previous:
	system("cls");
	gotoxy(45, 2);
	printf("!!!!!!LOGIN PAGE!!!!!!");
	gotoxy(40,5);
	printf("Emp ID: ");
	scanf("%s",username);
	gotoxy(40,6);
	printf("Password: ");
	while((temp_pwd=_getch())!=13) {
        password[i]=temp_pwd;
        i++;
        printf("*");
        }
        //To overwrite the password array
        i=0;
	while(!feof(ptr_check)){
		fscanf(ptr_check,"%s %s",usdt.username, usdt.password);
		if(strcmp(usdt.username, username)==0 && strcmp(usdt.password, password)==0){
			emp_menu();
		}
		else{
			printf("\n\n!!!!!WRONG USERNAME OR PASSWORD!!!!!");
			printf("\nEnter 1 to reenter or press 0 to exit:");
    		scanf("%d", &main_exit);
			if(main_exit==1)
				goto previous;
			else
				close_menu();
			exit(0);
		}
	}
	fclose(ptr_check);
}

void cust_login(){   //Done
	FILE *ptr_check;
	char username[20], password[20], temp_pwd;
	int i=0;
	ptr_check=fopen("bankcustdatabase.txt","r");
	previous:
	system("cls");
	gotoxy(45, 2);
	printf("!!!!!!LOGIN PAGE!!!!!!");
	gotoxy(40,5);
	printf("UserID: ");
	scanf("%s",username);
	gotoxy(40,6);
	printf("Password: ");
	while((temp_pwd=_getch())!=13) {
            password[i]=temp_pwd;
            i++;
            printf("*");
        }
        i=0;
	while(!feof(ptr_check)){
		fscanf(ptr_check,"%s %s %lli",usdt.username, usdt.password, &cust.account_no);
		if(strcmp(usdt.username, username)==0 && strcmp(usdt.password, password)==0){
			cust_menu();
		}
		else{
			printf("\n\n!!!!!WRONG USERNAME OR PASSWORD!!!!!");
			printf("\nEnter 1 to REENTER or 0 to EXIT:");
    		scanf("%d", &main_exit);
			if(main_exit==1)
				goto previous;
			else
				close_menu();
			exit(0);
		}
	}
	fclose(ptr_check);
}

void add_del_acc(){   //Done
	FILE *ptr_temp, *ptr_idpwd, *ptr_pp;
	char store[200], ch;
	int approve, i=0, choice, line_no, ctr=0;
	char str[256], file_name[]="bankcustdatabase.txt", temp1[]="temp_userid.txt";

	previous:
	system("cls");
	if(ptr_pp==NULL || ptr_idpwd==NULL)
		printf("\n\t\t\t\t!!!FILE NOT FOUND!!!");
	else{
		gotoxy(39,5);
		printf("1. ADD ACCOUNT");
		gotoxy(39,6);
		printf("2. DELETE ACCOUNT:");
		printf("\nPlease select your preference...");
		scanf("%d", &approve);
		switch(approve){
			case 1:
				ptr_pp = fopen("bankppdatabase.txt", "a");
				ptr_idpwd=fopen("bankcustdatabase.txt", "a");
				new_account();
				fprintf(ptr_idpwd, "%s	%s	%lld\n", usdt.username, usdt.password, cust.account_no);
				fprintf(ptr_pp,"%lld   %s %s   %s   %s   %s   %s   %d %d %d   %lld   %lld\n", cust.account_no, cust.fname, cust.lname, cust.fathname, cust.mothname, cust.address, cust.typeaccount, cust.date, cust.month, cust.year, cust.aadharnum, cust.pnumber);
				accUnderProcess();
	    		printf("\nPress 1 to go to main menu or 0 to exit...");
	    		scanf("%d", &main_exit);
	    		if(main_exit)
	    			emp_menu();
	    		else{
	    			close_menu();
	    			exit(0);
				}
	    		fclose(ptr_idpwd);
	    		fclose(ptr_pp);
	    		break;
	    		
	    	case 2:
	    		//Open the file to read and display in console
	    		ptr_idpwd = fopen(file_name, "r");
	    		while(!feof(ptr_idpwd)){
					fgets(store,100,ptr_idpwd);
					printf("%s", store);
				}
				fclose(ptr_idpwd);
				//Reopen the file for copying, deleting and renaming
				ptr_idpwd = fopen(file_name, "r");
				ptr_temp = fopen(temp1, "w");
				if(!ptr_idpwd && !ptr_temp){
					printf("File not found!!\n");
				}
				printf("Enter the line you want to remove : ");
				scanf("%d", &line_no);
				while(!feof(ptr_idpwd)){
					strcpy(str, "\0");
					fgets(str, 256, ptr_idpwd);
					if(!feof(ptr_idpwd)){
						ctr++;
						if(ctr!=line_no)
							fprintf(ptr_temp, "%s", str);
					}
				}
				//Closing the file
				fclose(ptr_idpwd);
				fclose(ptr_temp);
				//Remove the original file
				remove(file_name);
				//Rename of the temp file to original file_name
				rename(temp1, file_name);
				printf("\n!!!ACCOUNT HAS BEEN SUCCESSFULLY DELETED FROM THE RECORDS!!!\n");
	    		printf("\n\nPress 1 MAIN MENU or 0 to EXIT: ");
				scanf("%d", &main_exit);
				if(main_exit)
	    			emp_menu();
	    		else
	    			exit(0);
	    		break;
	    	default:
	    		printf("PLEASE ENTER A VALID CHOICE");
	    		fordelay(100000000);
	    		goto previous;
		}
	}
}

void profile(){    //Done
	FILE *ptr_pp;
	long long int accno, flag=0, aadhar;
	char array[200];
	ptr_pp=fopen("bankppdatabase.txt","r");
	previous:
	system("cls");
	printf("Enter account number:\t");
	scanf("%lld", &accno);
	if(ptr_pp==NULL){
		printf("!!!FILE NOT FOUND!!!");
	}
	//fread(address of structure, size of structure, times to call struct, ptr)
	while(!feof(ptr_pp) && flag==0){ 
		fscanf(ptr_pp,"%lld	%s %s   %s   %s   %s   %s   %d %d %d   %lld   %lld",&cust.account_no, cust.fname, cust.lname, cust.fathname, cust.mothname, cust.address, cust.typeaccount, &cust.date, &cust.month, &cust.year, &cust.aadharnum, &cust.pnumber);
		if(cust.account_no==accno){
			flag=1;
			printf("%lld   %s_%s   %s   %s   %s   %s   %d/%d/%d   %lld   %lld\n", cust.account_no, cust.fname, cust.lname, cust.fathname, cust.mothname, cust.address, cust.typeaccount, cust.date, cust.month, cust.year, cust.aadharnum, cust.pnumber);
		}
	}
	if(flag==0){
		printf("\n!!!Data not found!!!");
	}
	printf("\nEnter 1 to REENTER or  0 to EXIT:");
    		scanf("%d", &main_exit);
			if(main_exit==1)
				goto previous;
			else{
				close_menu();
				exit(0);
			}
	fclose(ptr_pp);
}

void transact_query(){   //Done
	FILE *ptr_transact;
	char transact[1024];
	ptr_transact=fopen("transactionquery.txt","a");
	system("cls");
	if(ptr_transact==NULL)
		printf("!!!FILE NOT FOUND!!!");
	printf("Mention your query with transaction id(***no spacecs***):\t");
	scanf("%s", transact);
	fprintf(ptr_transact,"%s\n", transact);
	printf("\nEnter 1 for MAIN MENU or 0 to EXIT:");
    scanf("%d", &main_exit);
			if(main_exit==1)
				cust_menu();
			else{
				close_menu();
				exit(0);
			}
	fclose(ptr_transact);	
}

void modify_cust(){
	FILE *ptr_pp, *ptr_temp;
	char cust_add[50], file_name[]="bankppdatabase.txt", temp2[]="temp_modify.txt";
	int choice, approve, i=0, flag=0;
	long long cust_ph, account_no;
	previous:
	system("cls");
	printf("\nWhat do you want to modify: \n1. Phone Number \n2. Address \nPlease Enter your preference...");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			ptr_pp=fopen(file_name, "r");
			ptr_temp=fopen(temp2, "w");
			//if File do not exist
			if(ptr_pp==NULL){
				printf("!!!FILE NOT FOUND!!!");
				exit(0);
			}
			printf("\n\nEnter your account number:\t");
			scanf("%lld", &account_no);
			
			printf("\nEnter new Phone Number:\t");
			scanf("%lld", &cust_ph);
			
			while(!feof(ptr_pp)){
				fscanf(ptr_pp,"%lld %s %s %s %s %s %s %d %d %d %lld %lld", &cust.account_no, cust.fname, cust.lname, cust.fathname, cust.mothname, cust.address, cust.typeaccount, &cust.date, &cust.month, &cust.year, &cust.aadharnum, &cust.pnumber);
				if(cust.account_no==account_no){
					cust.pnumber=cust_ph;
					printf("%lld   %s_%s   %s   %s   %s   %s	%d/%d/%d  %lld	%lld\n", cust.account_no, cust.fname, cust.lname, cust.fathname, cust.mothname, cust.address, cust.typeaccount, cust.date, cust.month, cust.year, cust.aadharnum, cust.pnumber);
					//Store data in the file
					fprintf(ptr_temp,"%lld %s %s %s %s %s %s %d %d %d %lld %lld\n", cust.account_no, cust.fname, cust.lname, cust.fathname, cust.mothname, cust.address, cust.typeaccount, cust.date, cust.month, cust.year, cust.aadharnum, cust.pnumber);	
				}
				else
					fprintf(ptr_temp,"%lld %s %s %s %s %s %s %d %d %d %lld %lld\n", cust.account_no, cust.fname, cust.lname, cust.fathname, cust.mothname, cust.address, cust.typeaccount, cust.date, cust.month, cust.year, cust.aadharnum, cust.pnumber);
			}
			//File Close
			fclose(ptr_pp);
			fclose(ptr_temp);
			remove(file_name);
			rename(temp2,file_name);
			
			printf("\nPress 1 to go to main menu or 0 to exit...");
	    	scanf("%d", &main_exit);
	    	if(main_exit)
	    		emp_menu();
	    	else{
	    		close_menu();
	    		exit(0);
			}
			break;
		case 2:
			ptr_pp=fopen(file_name, "r"); 
			ptr_temp=fopen(temp2, "w");
			
			printf("\n\nEnter your account number:\t");
			scanf("%lld", &account_no);
			printf("\nEnter new Address:\t");
			scanf("%s", &cust_add);
			
			while(!feof(ptr_pp)){
				fscanf(ptr_pp,"%lld %s %s %s %s %s %s %d %d %d %lld %lld", &cust.account_no, cust.fname, cust.lname, cust.fathname, cust.mothname, cust.address, cust.typeaccount, &cust.date, &cust.month, &cust.year, &cust.aadharnum, &cust.pnumber);
				if(cust.account_no==account_no){
					//To add Address to the file
					for(i=0;i<sizeof(cust_add);i++)
						cust.address[i]=cust_add[i];
					printf("%lld   %s_%s   %s   %s   %s   %s	%d/%d/%d  %lld	%lld\n", cust.account_no, cust.fname, cust.lname, cust.fathname, cust.mothname, cust.address, cust.typeaccount, cust.date, cust.month, cust.year, cust.aadharnum, cust.pnumber);
					//Store data in the file
					fprintf(ptr_temp,"%lld %s %s %s %s %s %s %d %d %d %lld %lld\n", cust.account_no, cust.fname, cust.lname, cust.fathname, cust.mothname, cust.address, cust.typeaccount, cust.date, cust.month, cust.year, cust.aadharnum, cust.pnumber);	
				}
				else
					fprintf(ptr_temp,"%lld %s %s %s %s %s %s %d %d %d %lld %lld\n", cust.account_no, cust.fname, cust.lname, cust.fathname, cust.mothname, cust.address, cust.typeaccount, cust.date, cust.month, cust.year, cust.aadharnum, cust.pnumber);
			}
			//File Close
			fclose(ptr_pp);
			fclose(ptr_temp);
			remove(file_name);
			rename(temp2,file_name);
			
			printf("\nPress 1 to go to main menu or 0 to exit...");
	    	scanf("%d", &main_exit);
	    	if(main_exit)
	    		emp_menu();
	    	else{
	    		close_menu();
	    		exit(0);
			}
			break;
		default:
			printf("!!!PLEASE ENTER A VALID INPUT!!!");
			goto previous;
			
	}
	      
}
//Customer Query report
void query(){  //Done
	FILE *ptr_query;
	ptr_query=fopen("transactionquery.txt","r");
	
	char transaction_id[1024];
	system("cls");
	if(ptr_query==NULL){
		printf("!!!NO DATA FOUND!!!");
		exit(0);
	}
	while(!feof(ptr_query)){
		fscanf(ptr_query,"%s", &transaction_id);
		printf("%s\n",transaction_id);
	}
	fordelay(1000000000);
	system("cls");
	printf("\n*****YOUR QUERY IS UNDER REVIEW*****. \n   *****PLEASE BE PATIENT*****");
	fordelay(1000000000);
	system("cls");
	printf("\n*****YOUR QUERY HAS BEEN RESOLVED*****\n");
	fclose(ptr_query);
	remove("transactionquery.txt");
	
	printf("\nEnter 1 for MAIN MENU or 0 to EXIT:");
    scanf("%d", &main_exit);
			if(main_exit==1)
				cust_menu();
			else{
	    		close_menu();
	    		exit(0);
			}
}
//Add money to the account
void credit_money(){    	//Done
	FILE *ptr_money, *ptr_temp;
	char file_name[]="transaction.txt", temp3[]="temp_credit.txt";
	long long account_no;
	float deposit;
	ptr_money=fopen(file_name,"r");
	ptr_temp=fopen(temp3,"w");
	if(ptr_money==NULL)
		printf("!!!FILE NOT FOUND!!!");
		
	system("cls");
	printf("\n\nEnter your account number:\t");
	scanf("%lld", &account_no);
	
	printf("\nEnter Amount you want to deposit:\t");
	scanf("%f", &deposit);
	while(!feof(ptr_money)){
		fscanf(ptr_money,"%lld %f", &amount.account_no, &amount.initial_money);
		if(amount.account_no==account_no){
			amount.initial_money+=deposit;
			printf("Your account now contains amount:\t %.2f\n", amount.initial_money);
			//Store data in the file
			fprintf(ptr_temp,"%lld %.2f ", amount.account_no, amount.initial_money);	
		}
		else
			fprintf(ptr_temp,"%lld %.2f ", amount.account_no, amount.initial_money);
		}
		//File Close
		fclose(ptr_money);
		fclose(ptr_temp);
		remove(file_name);
		rename(temp3,file_name);
		printf("\nPress 1 to go to main menu or 0 to exit...");
	    scanf("%d", &main_exit);
	    if(main_exit)
	    	emp_menu();
	    else{
	    		close_menu();
	    		exit(0);
		}
}
//Debit money from the account
void debit_money(){		//Done
	FILE *ptr_money, *ptr_temp;
	char file_name[]="transaction.txt", temp4[]="temp_debit.txt";
	long long account_no;
	float withdraw;
	ptr_money=fopen(file_name,"r");
	ptr_temp=fopen(temp4,"w");
	if(ptr_money==NULL){
		printf("!!!FILE NOT FOUND!!!");
		exit(0);
	}
	
	system("cls");
	printf("\n\nEnter your account number:\t");
	scanf("%lld", &account_no);
	
	printf("\nEnter Amount you want to withdraw:\t");
	scanf("%f", &withdraw);
	
	while(!feof(ptr_money)){
		fscanf(ptr_money,"%lld %f", &amount.account_no, &amount.initial_money);
		//IF the amount is less than withdraw
		if(amount.initial_money<withdraw){
			printf("\n!!!YOU DO NOT HAVE SUFFICIENT BALANCE!!!");
			break;
		}
		else{
			if(amount.account_no==account_no){
				amount.initial_money-=withdraw;
				printf("Your account now contains amount:\t %.2f\n", amount.initial_money);
				//Store data in the file
				fprintf(ptr_temp,"%lld	%.2f\n", amount.account_no, amount.initial_money);	
			}
			else
				fprintf(ptr_temp,"%lld	%.2f\n", amount.account_no, amount.initial_money);
			}
		}
		
		//File Close
		fclose(ptr_money);
		fclose(ptr_temp);
		remove(file_name);
		rename(temp4,file_name);
		printf("\nPress 1 to go to main menu or 0 to exit...");
	    scanf("%d", &main_exit);
	    if(main_exit)
	    	emp_menu();
	    else{
	    	close_menu();
	  		exit(0);
		}
}

//Money Transaction between each other
void transfer_money(){      //Done
	FILE *ptr_money, *ptr_temp;
	char file_name[]="transaction.txt", temp5[]="temp_transaction.txt";
	long long account_to, account_from;
	float deposit;
	
	ptr_money=fopen(file_name,"r");
	ptr_temp=fopen(temp5,"w");
	if(ptr_money==NULL)
		printf("!!!FILE NOT FOUND!!!");
		
	system("cls");
	printf("\n\nEnter your account number:\t");
	scanf("%lld", &account_from);
	
	printf("\n\nEnter account number you want to transfer money:\t");
	scanf("%lld", &account_to);
	
	printf("\nEnter Amount you want to send:\t");
	scanf("%f", &deposit);
	while(!feof(ptr_money)){
		fscanf(ptr_money,"%lld %f %lld %f", &amount.account_no, &amount.initial_money, &amount.account_no_2, &amount.initial_money_2);
		if(amount.initial_money<deposit){
			printf("\n!!!YOU DO NOT HAVE SUFFICIENT BALANCE!!!");
			break;
		}
		if(amount.account_no_2==account_to && amount.account_no==account_from){
			amount.initial_money_2+=deposit;
			amount.initial_money-=deposit;
			printf("1st account amount:\t %.2f \n2nd account amount:\t %.2f\n", amount.initial_money, amount.initial_money_2);
			//Store data in the file
			fprintf(ptr_temp,"%lld %.2f %lld %.2f\n", amount.account_no, amount.initial_money, amount.account_no_2, amount.initial_money_2);	
		}
		else
			fprintf(ptr_temp,"%lld %.2f %lld %.2f\n", amount.account_no, amount.initial_money, amount.account_no_2, amount.initial_money_2);
		}
		//File Close
		fclose(ptr_money);
		fclose(ptr_temp);
		remove(file_name);
		rename(temp5,file_name);
		printf("\nPress 1 to go to main menu or 0 to exit...");
	    scanf("%d", &main_exit);
	    if(main_exit)
	    	cust_menu();
	    else{
	    	close_menu();
	    	exit(0);
		}
	
}

