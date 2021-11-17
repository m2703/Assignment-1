
/*
   NAME: MANAS KULKARNI
   STUDENT ID:118779214
   EMAIL: mvkulkarni@myseneca.ca
   SECTION: NCC

*/

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "commonHelpers.c"
#include "commonHelpers.h"



struct UserLogin
{
 char u_name[100];
 char pass[100];
};

 struct Person
{
  char name[30];
  int birthYear;
  double h_income;
  char nation[30];
  };

struct Account
{
  int a_num;
  char a_type;
  struct UserLogin login;
  struct Person person;
 

   
};

 
//function definitions
void getAccount(struct Account account);
void getPerson(struct Account account);
void getUserLogin(struct Account account);



#endif