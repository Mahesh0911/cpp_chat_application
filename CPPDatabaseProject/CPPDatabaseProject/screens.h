#pragma once
#include"createAccount.h"
#include "DatabaseCommands.h"

int mainScreen();
int createAccountScreen();
int loginAccountScreen();
int friendListScreen();
//int chatScreen();

User* temp1=NULL;

int choice() {
	int ch;
	std::cout << "\n*Enter : ";
	std::cin >> ch;

	return ch;
}

int mainScreen() {
	system("cls");
	std::cout << "\n-----------------------------WELCOME TO MY CHAT APPLICATION----------------------------------\n\n";
	std::cout << "1. Create Account\n";
	std::cout << "2. Login to your Account\n";
	std::cout << "3. Exit\n";

	return choice();
}

int createAccountScreen() {

	system("cls");
	std::cout << "\n-----------------------------WELCOME TO MY CHAT APPLICATION----------------------------------\n\n";	

	temp1 = new User();
	createAccountintoDB(temp1->getusername(), temp1->getpassword());

	delete temp1;
	std::cout << "\n\n1. Login to Account\n";
	std::cout << "2. Back\n";
	std::cout << "3. Exit\n";
	return choice();
}

int loginAccountScreen() {
	system("cls");
	std::cout << "\n-----------------------------WELCOME TO MY CHAT APPLICATION----------------------------------\n\n";
	std::cout << "\n---------------------------------------Login Page----------------------------------\n\n";
	int successfulLogin;
	std::string userinput,pswrd;
	std::cout << "\nEnter Username :";
	std::cin >> userinput;
	std::cout << "\nEnter password :";
	std::cin >> pswrd;
	successfulLogin=checkLoginCredentials(userinput,pswrd);
	if (successfulLogin == 1) {
		temp1 = new User(userinput, pswrd);
		return 1;
	}
	else {
		std::cout << "Wrong User Name or Password .";
	}
	std::cout << "\nEnter any num key : " << std::endl;
	choice();
	return 2;
}

int friendListScreen(){
	system("cls");
	std::cout << "\n-----------------------------WELCOME TO MY CHAT APPLICATION----------------------------------\n\n";
	std::cout << "\n------------------------------"<<temp1->getusername()<<": Your Friend List----------------------------------\n\n";

	friendList();

	char input[20];
	std::cout << "\n\nPress '2' to Log Out";
	std::cout << "\nOr enter User Name to Chat With\nEnter :";
	std::cin >> input;

	if (strcmp(input,"1")==0) {
		return 1;
	}
	if (strcmp(input, "2") == 0) {
		return 2;
	}
	int ch = 0;
	while (ch == 0) {
		ch=displaychat(input);
	}
	return ch;;
}

/*
int chatScreen() {
	system("cls");
	std::cout << "\n-----------------------------WELCOME TO MY CHAT APPLICATION----------------------------------\n\n";
	
	char input[30];
	std::cout << "\n\nPress '1' to Back";
	std::cout << "\nOr enter User Name to Chat With\nEnter :";
	std::cin >> input;

	if (strcmp(input, "1") == 0) {
		return 1;
	}
	else {
		displaychat(input);
	}
}
*/