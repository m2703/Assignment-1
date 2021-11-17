#include "account.h"
#include <stdio.h>


void getAccount(struct Account account)
{
  printf("Account Data: New Record\n");
  printf("----------------------------------------\n");
  // for account number
  printf("Enter the Account number: ");
  account.a_num = getInteger();
  //while((getchar())!='\n');

   // for account type
    char ac = 'x';
    int ch = 0;
    int chflag = 0;

    printf("Enter the account type (A=Agent | C=Customer): ");

    for(int ch = 0 ; chflag == 0; ch++)
    {
        scanf("%c%c",&account.a_type,&ac);

        if(ac == '\n' && (account.a_type == 'A'|| account.a_type == 'C'))
        {
            chflag = 1;
        }
        else if(ac =='\n' && (account.a_type!='A'|| account.a_type!='C'))
        {   
            
            printf("ERROR: Character must be one of [AC]: ");
        }   

        
    }
    printf("\n");
}


  
   

void getPerson(struct Account account)
{
    printf("Person Data Input\n");                        // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n");


    printf("Enter the person's full name (30 chars max): ");
    scanf("%s",&account.person.name);
    while((getchar()) != '\n');

    //for BirthYear
    int b = 0;
    int bflag = 0;
    printf("Enter birth year (current age must be between 18 and 110): ");
    for(b=0;b>=0 &&bflag==0;b++)
    {
       scanf("%d",&account.person.birthYear);
       if(account.person.birthYear>=1911 && account.person.birthYear<=2003)
       {
           bflag = 1;
       }
       else if(account.person.birthYear<1911 || account.person.birthYear>2003)
       {
           while((getchar()) != '\n');
           printf("ERROR: Value must be between 1911 and 2003 inclusive: ");
       }

    }
    while((getchar()) != '\n');

    // for household income
    printf("Enter the household income: $");
    
    int in = 0;
    int inflag = 0;
    char inchar = 'x';

    for(in = 0 ; inflag == 0 ; in++)
    {
        scanf(" %lf%c",&account.person.h_income,&inchar);

        if(inchar == '\n' && account.person.h_income>0.0)
        {
            inflag = 1;
        }

        else if(inchar != '\n'){
            
            printf("ERROR: Value must be a double floating-point number: ");
            while((getchar())!='\n');
        }

        else if(account.person.h_income<=0.0)
        {
            
            printf("ERROR: Value must be a positive double floating-point number: ");
        }

        
    }

    

    // for country
    printf("Enter the country (30 chars max.): ");
    scanf("%30s",account.person.nation);
    while((getchar()) != '\n');
    
    printf("\n");
}

void getUserLogin(struct Account account)
{
    printf("User Login Data Input\n");                    
    printf("----------------------------------------\n");

    int u = 0;
    int uflag = 0;
    printf("Enter user login (10 chars max): ");
   // while ((getchar()) != '\n');
    
   
    for(u = 0; u>=0 && uflag == 0 ; u++)
    {
       scanf("%30[^\n]",&account.login.u_name);
       
       int c = 0;
       int count = 0;

       for(c=0;account.login.u_name[c] != '\0';c++)
       {
           count++;
       }
       //printf("%d\n",count);

       if(count>10)
       {
           while ((getchar()) != '\n');
           printf("ERROR: String length must be no more than %d chars: ",10);
       }
       else{
           uflag = 1;
       }
    }

    // FOR PASSWORD
     while((getchar()) != '\n');

     printf("Enter the password (must be 8 chars in length): ");
     char this = 'x';
     int pm = 0;
     int pmflag = 0;

     for (pm = 0 ;pmflag==0;pm++)
     {
          scanf("%31[^\n]",&account.login.pass);
          int ps = 0;
          int pcount= 0;

          for(ps = 0 ;account.login.pass[ps]!='\0';ps++)
          {
              pcount++;
          }
          //printf("%d",pcount);

          if(pcount==8)
          {
              pmflag = 1;
          }
          else
          {    
              printf("ERROR: String length must be exactly 8 chars: ");
          }
          while((getchar())!='\n');
          printf("\n");
     }
}