#include<stdio.h>
#include "accountTicketingUI.h"

void displayAccountDetailHeader()
{
    printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
    printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
}

void displayAccountDetailRecord(struct Account account)
{
    printf("50001 AGENT     Will Smith       1988   188222.75 CANADA     MIBAgent-J a*e*t*0*");
}