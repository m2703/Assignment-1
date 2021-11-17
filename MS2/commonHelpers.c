#include<stdio.h>
#include<stdlib.h>
#include "commonHelpers.h"



int getInteger(void)
{  
    
    int num = 0;
    char newline = 'x';
    int mflag = 0;
    int i=0;
    

    for( i = 0;i>=0 && mflag == 0;i++)
    {
       scanf("%d%c",&num,&newline);
       if(newline == '\n')
       {
           
           return num;
           mflag = 1;
       }
       else{
           while ((getchar()) != '\n');
           printf("ERROR: Value must be an integer: ");
           //continue;
       }

       

    }
    return num;
}

int getPositiveInteger(void)
{
    int num = 0;
    char newline = 'x';
    int mflag = 0;
    int i=0;
    

    for( i = 0;i>=0 && mflag == 0;i++)

    {   
       scanf("%d%c",&num,&newline);
       if(newline == '\n' && num >=0)
       {
           
           return num;
           mflag = 1;
       }
       else if(num <= 0){
        //    while ((getchar()) != '\n');
           printf("ERROR: Value must be a positive integer greater than zero: ");
           
           
       }

       

    }
    return num;
}

int getIntFromRange(int min,int max)
{
    int num = 0;
    char nl = 'x';
    int flag = 0;
    int i = 0;
    
    for(i = 0; i>=0 && flag==0;i++)
    {
        scanf("%d%c",&num,&nl);

        if(nl == '\n' && (num>=min && num<=max))
        {
           return num;
           flag = 1;
        }

        else if(nl != '\n')
        {
           while ((getchar()) != '\n');
           printf("ERROR: Value must be an integer: "); 
        }

        else if(num<3 || num>11)
        {   
            
            printf("ERROR: Value must be between %d and %d inclusive: ",min,max);
        }
        
    }
    return num;
}

double getDouble(void)
{
    double num = 0.0;
    char nl = 'x';
    int i = 0;
    int flag = 0;

    for(i = 0; i>= 0 && flag==0;i++)
    {
        scanf("%lf%c",&num,&nl);
        if(nl == '\n')
        {
           return num;
           flag = 1;
        }
        else
        {
            while ((getchar()) != '\n');
            printf("ERROR: Value must be a double floating-point number: ");
        }
    }
    return num;

}
double getPositiveDouble(void)
{
    double num = 0.0;
    char nl = 'x';
    int i = 0;
    int flag = 0;

    for(i = 0; i>= 0 && flag==0;i++)
    {
        scanf("%lf%c",&num,&nl);
        if(nl == '\n' && num >= 0.0)
        {
           return num;
           flag = 1;
        }
        else if(num < 0.00)
        {
            
            printf("ERROR: Value must be a positive double floating-point number: ");
        }
    }
    return num;
}

char getCharOption (char myArr[7])
{
   char c = 'x';
   int flag = 0;
   int i = 0;

   for(i = 0;i>=0 && flag == 0; i++)
   {
       scanf("%c",&c);
       if(c == 'r' || c =='A')
       {
         return c;
         flag = 1;
       }
       else{
           while ((getchar()) != '\n');
           printf("ERROR: Character must be one of [%s]: ",myArr);
       }
   }
   return c;
   
}

void getCString(char myArr[100], int minchar, int maxchar)
{
    
    int i = 0;
    int flag = 0;
    while ((getchar()) != '\n');
    
    //printf("%d %d\n",minchar,maxchar);
    for(i = 0 ;i>=0 && flag == 0 ;i++)
    {
       //scanf("%[^\n]",myArr);
      
       scanf("%30[^\n]",myArr);
       int count = 0;
       int m = 0;
    // printf("%s\n",myArr);
  
    for(m = 0;myArr[m]!='\0';m++)
    {
        count++;
    }
    
    if(count>=minchar && count<=maxchar)
    {
        // printf("That is all correct\n");
        flag = 1;
    }
    else if(minchar == maxchar && (count != minchar))
    {  
       while ((getchar()) != '\n');
       printf("ERROR: String length must be exactly %d chars: ",minchar);
       
    }
    else if(count>maxchar)
    {  
       while ((getchar()) != '\n');
       printf("String length must be no more than %d chars: ",maxchar);
    }
    else if(count<minchar)
    {  
        while ((getchar()) != '\n');
        printf("ERROR: String length must be between %d and %d chars: ",minchar,maxchar);
    }
    
  }

 

    
    
}






