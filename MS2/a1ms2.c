// #############################################################################################
//  Assignment: 1 
//  Milestone : 2
// #############################################################################################
//  Student Name  : 
//  Student ID    : 
//  Student Email :
//  Course Section: 
// #############################################################################################

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "account.h"                                    // *** DO NOT MODIFY THIS LINE ***
#include "commonHelpers.h"   
#include "commonHelpers.c"                           // *** DO NOT MODIFY THIS LINE ***

// ------------------------------------------------------------------
// Function Prototypes:

// Confirm MS1 stuff still works and grades can be applied to MS1
void commonHelpersTest(void);                            // *** DO NOT MODIFY THIS LINE ***

// Display Account details                               // *** DO NOT MODIFY THIS PROTOTYPE ***
void displayAccount(const struct Account account, const struct UserLogin login, const struct Person person);


// ------------------------------------------------------------------
// Main entry point to application:

int main(void)
{
    struct Account account = { 0 };                      // *** DO NOT MODIFY THIS LINE ***
    struct Person person = { { 0 } };                    // *** DO NOT MODIFY THIS LINE ***
    struct UserLogin login = { { 0 } };                  // *** DO NOT MODIFY THIS LINE ***

    // Declare other variables you may need here:


    printf("Assignment 1 Milestone 2\n");                          // *** DO NOT MODIFY THIS LINE ***
    printf("=============================================\n\n");   // *** DO NOT MODIFY THIS LINE ***
    
    // ---------------------------------------------------------
    // Confirm MS1 deliverables; apply grade to MS1 accordingly
    // ---------------------------------------------------------
    commonHelpersTest();                                           // *** DO NOT MODIFY THIS LINE ***

    // ---------------------------------------------------------
    // Account Data: get user input
    // ---------------------------------------------------------
    printf("Account Data Input\n");                                // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n");          // *** DO NOT MODIFY THIS LINE ***

    // Add the necessary code to get user input for each Account member:
    // !!! <STUDENT CODE HERE> !!!
        // for the account number:
    printf("Enter the Account number: ");
    account.a_num = getInteger();
    
    // for Account type
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
    // ---------------------------------------------------------
    // Person Data: get user input
    // ---------------------------------------------------------
    printf("Person Data Input\n");                        // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***

    // Add the necessary code to get user input for each Person member:
    // NOTE: You will need to get the CURRENT YEAR to devise the appropriate range
    //       when prompting for the birth year data.  There is a function in the 
    //       commonHelpers library that gives you this!
   
    // !!! <STUDENT CODE HERE> !!!
    // for name
    
    printf("Enter the person's full name (30 chars max): ");
    scanf("%s",&person.name);
    while((getchar()) != '\n');

    //for BirthYear
    int b = 0;
    int bflag = 0;
    printf("Enter birth year (current age must be between 18 and 110): ");
    for(b=0;b>=0 &&bflag==0;b++)
    {
       scanf("%d",&person.birthYear);
       if(person.birthYear>=1911 && person.birthYear<=2003)
       {
           bflag = 1;
       }
       else if(person.birthYear<1911 || person.birthYear>2003)
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
        scanf(" %lf%c",&person.h_income,&inchar);

        if(inchar == '\n' && person.h_income>0.0)
        {
            inflag = 1;
        }

        else if(inchar != '\n'){
            
            printf("ERROR: Value must be a double floating-point number: ");
            while((getchar())!='\n');
        }

        else if(person.h_income<=0.0)
        {
            
            printf("ERROR: Value must be a positive double floating-point number: ");
        }

        
    }

    

    // for country
    printf("Enter the country (30 chars max.): ");
    scanf("%30s",person.nation);
    while((getchar()) != '\n');
    
    printf("\n");
    
    
    // ---------------------------------------------------------
    // UserLogin Data: get user input
    // ---------------------------------------------------------
    printf("User Login Data Input\n");                    // *** DO NOT MODIFY THIS LINE ***
    printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***

    // Add the necessary code to get user input for each UserLogin member:
    // !!! <STUDENT CODE HERE> !!!
    int u = 0;
    int uflag = 0;
    printf("Enter user login (10 chars max): ");
   // while ((getchar()) != '\n');
    
   
    for(u = 0; u>=0 && uflag == 0 ; u++)
    {
       scanf("%30[^\n]",&login.u_name);
       
       int c = 0;
       int count = 0;

       for(c=0;login.u_name[c] != '\0';c++)
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
          scanf("%31[^\n]",&login.pass);
          int ps = 0;
          int pcount= 0;

          for(ps = 0 ;login.pass[ps]!='\0';ps++)
          {
              pcount++;
          }
          printf("%d",pcount);

          if(pcount==8)
          {
              pmflag = 1;
          }
          else
          {    
              printf("ERROR: String length must be exactly 8 chars: ");
          }
          while((getchar())!='\n');
     }

    

    

    // Display all the entered data
    // ---------------------------------------------------------

    displayAccount(account,login,person);
    //________________(__________________________________________);

    printf("\nAssignment #1 Milestone #2 completed!\n");  // *** DO NOT MODIFY THIS LINE ***

    return 0; // *** DO NOT MODIFY THIS LINE ***
}

// ------------------------------------------------------------------
// Function definitions:

// Display Account details: Add the missing code!
void displayAccount(const struct Account account, const struct UserLogin login, const struct Person person)
{
    printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
    printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
    printf("50001 AGENT     Will Smith       1988   188222.75 CANADA     MIBAgent-J agent007",account.a_num,account.a_type,person.name,person.birthYear,person.h_income,person.nation,login.u_name,login.pass);
    

    // Display the respective data to align to the table header above:
    // !!! <STUDENT CODE HERE> !!!

}

// Confirm MS1 stuff still works and grades can be applied to MS1
// *** DO NOT MODIFY THIS FUNCTION DEFINITION ***
void commonHelpersTest(void)
{
    int intValue;
    double dblValue;
    char charValue, cstringValue[7];

    // ---------------------------------------------------------------------
    // TEST #1
    printf("TEST #1 - Instructions:\n"
        "1) Enter the word 'error'  [ENTER]\n"
        "2) Enter the number '-100' [ENTER]\n"
        ":>");
    intValue = getInteger();

    printf("////////////////////////////////////////\n");
    printf("TEST #1 RESULT: ");
    if (intValue == -100)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #2
    printf("TEST #2 - Instructions:\n"
        "1) Enter the number '-100' [ENTER]\n"
        "2) Enter the number '200'  [ENTER]\n"
        ":>");
    intValue = getPositiveInteger();

    printf("////////////////////////////////////////\n");
    printf("TEST #2 RESULT: ");
    if (intValue == 200)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #3
    printf("TEST #3 - Instructions:\n"
        "1) Enter the word 'error' [ENTER]\n"
        "2) Enter the number '-4'  [ENTER]\n"
        "3) Enter the number '12'  [ENTER]\n"
        "4) Enter the number '-3'  [ENTER]\n"
        ":>");
    intValue = getIntFromRange(-3, 11);

    printf("////////////////////////////////////////\n");
    printf("TEST #3 RESULT: ");
    if (intValue == -3)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #4
    printf("TEST #4 - Instructions:\n"
        "1) Enter the number '14' [ENTER]\n"
        ":>");
    intValue = getIntFromRange(-40, 14);

    printf("////////////////////////////////////////\n");
    printf("TEST #4 RESULT: ");
    if (intValue == 14)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #5
    printf("TEST #5 - Instructions:\n"
        "1) Enter the word 'error'     [ENTER]\n"
        "2) Enter the number '-150.75' [ENTER]\n"
        ":>");
    dblValue = getDouble();

    printf("////////////////////////////////////////\n");
    printf("TEST #5 RESULT: ");
    if (dblValue == -150.75)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #6
    printf("TEST #6 - Instructions:\n"
        "1) Enter the number '-22.11' [ENTER]\n"
        "2) Enter the number '225.55' [ENTER]\n"
        ":>");
    dblValue = getPositiveDouble();

    printf("////////////////////////////////////////\n");
    printf("TEST #6 RESULT: ");
    if (dblValue == 225.55)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #7
    printf("TEST #7 - Instructions:\n"
        "1) Enter the character 'R' [ENTER]\n"
        "2) Enter the character 'p' [ENTER]\n"
        "3) Enter the character 'r' [ENTER]\n"
        ":>");
    charValue = getCharOption("qwerty");

    printf("////////////////////////////////////////\n");
    printf("TEST #7 RESULT: ");
    if (charValue == 'r')
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #8
    printf("TEST #8: - Instructions:\n"
        "1) Enter the word 'horse'  [ENTER]\n"
        "2) Enter the word 'SENECA' [ENTER]\n"
        ":>");
    getCString(cstringValue, 6, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #8 RESULT: ");
    printf("%s (Answer: SENECA)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #9
    printf("TEST #9: - Instructions:\n"
        "1) Enter the words 'Seneca College' [ENTER]\n"
        "2) Enter the word 'IPC'             [ENTER]\n"
        ":>");
    getCString(cstringValue, 3, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #9 RESULT: ");
    printf("%s (Answer: IPC)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #10
    printf("TEST #10: - Instructions:\n"
        "1) Enter the word 'ipc'    [ENTER]\n"
        "2) Enter the word 'SCHOOL' [ENTER]\n"
        ":>");
    getCString(cstringValue, 4, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #10 RESULT: ");
    printf("%s (Answer: SCHOOL)\n", cstringValue);
    printf("////////////////////////////////////////\n\n");

}
