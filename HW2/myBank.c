#include <stdio.h>
#include "myBank.h"
#define accountNumber 901
double Accounts[50][2] = {0};

//option O
void OpenAccount(double amount)
{
    if(amount > -0.009&&amount<0.009){
        printf(" \n");
    }else{
        int i = 0;
        while (Accounts[i][0])
        {
            i++;
        }
        if (i < 50 - 1)
        {
            Accounts[i][0] = 1;
            double rounded = ((int)(amount * 100 + .5) / 100.0);
            Accounts[i][1] = rounded;
            printf("%d \n", i + accountNumber);
        }
        else
        {
            printf("Couldn't store the new account, We are full now! \n");
        }
    }
}

//option B
void CheckBalance(int account)
{
    if(account > 950 || account < 901){
        printf("Not exist \n");
    }
    else if ((int)(Accounts[account - accountNumber][0]) == 1)
    {
        printf("%.2lf \n", Accounts[account - accountNumber][1]);
    }
    else
    {
        printf("account is closed..zzz... \n");
    }
}

//option D
void AddToBalance(int account)
{
        if(account > 950 || account < 901)
        {
            printf("not exist \n");
        }
        else if((int)(Accounts[account - accountNumber][0]) == 0)
        {
            printf("account is closed..zzz... \n"); 
        }
        else
        {
            printf("Insert amount to Draw- ");        
            double num;
	        scanf(" %lf",&num);
            double amount = ((int)(num * 100 + .5) / 100.0);
            Accounts[account - accountNumber][1] = Accounts[account - accountNumber][1] + amount;
            printf("%lf \n", Accounts[account - accountNumber][1]);
        }   
}

//option W
void drawFromBank(int account)
{
    if (account > 950 || account < 901)
    {
            printf("No such account \n");
    }
    else if ((int)(Accounts[account - accountNumber][0]) == 0)
    {
        printf("account is closed..zzz... \n");
    }else{  
        printf("Insert amount to Withdraw- ");  
        double num;
        scanf(" %lf",&num);
        double amount = ((int)(num * 100 + .5) / 100.0);
        if(amount > -0.009&&amount<0.009){
            printf(" \n");
        }else{
            if (Accounts[account - accountNumber][1] < amount)
            {
                printf("Too much \n");
            }
            else
            {
                Accounts[account - accountNumber][1] = Accounts[account - accountNumber][1] - amount;
                printf("%.2lf \n", Accounts[account - accountNumber][1]);
            }
        }
    }
}

//option C
void CloseAccount(int account)
{
    if (account > 950 || account < 901)
    {
        printf("No such account");
    }
    else if (Accounts[account - accountNumber][0] == 0)
    {
        printf("account is closed..zzz... \n");
    }
    else
    {
        Accounts[account - accountNumber][0] = 0;
        Accounts[account - accountNumber][1] = 0;
        printf("The account is closed now \n");
    }
}

//option I
void setInterest(int interest)
{
    if (interest < -100)
    {
        printf("Interest can't be - 100 and below\n");
    }
    else
    {
        for (int i = 0; i < sizeof(Accounts) / sizeof(Accounts[0]); i++)
        {
            double num = (Accounts[i][1] * (interest*0.01));
            double Inter = ((int)(num * 100 + .5) / 100.0);
            Accounts[i][1] = Inter + Accounts[i][1];
        }
    }
}

//option P
void printOpenAccounts()
{
    for (int i = 0; i < sizeof(Accounts) / sizeof(Accounts[0]); i++)
    {
        if (Accounts[i][0] == 1)
        {
            printf(" %d :", i + accountNumber);
            printf("%.2lf \n", Accounts[i][1]);
        }
    }
}

//little helper to prettify option E
void CloseAccountPretty(int account)
{
    Accounts[account - accountNumber][0] = 0;
    Accounts[account - accountNumber][1] = 0;
}

//option E
void Exit()
{
    for (int i = 0; i < sizeof(Accounts) / sizeof(Accounts[0]); i++)
    {
        CloseAccountPretty(i + accountNumber);
    }
    printf("bye \n");
}

char getOption()
{
    char operator;
    printf("Please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
    scanf(" %c", &operator);
    return operator;
}

int inBank()
{
    char operator= getOption();
    if (operator== 'O')
    {
        printf("Insert amount for the new account- ");
        double amount;
	    scanf("%lf",&amount);
	    if(amount!=0){
            OpenAccount(amount);
        }
        
        return 1;
    }
    else if (operator== 'B')
    {
        int account;
        printf("Insert account number to check balance- ");
        scanf(" %d",&account);
        CheckBalance(account);
        return 1;
    }
    else if (operator== 'D')
    {
        int account;
        printf("Insert account to Draw- ");
        scanf(" %d", &account);
        AddToBalance(account);
        return 1;
    }
    else if (operator== 'W')
    {
        int account;
        printf("Insert account to Withdraw- ");
        scanf(" %d", &account);
        drawFromBank(account);
        return 1;
    }
    else if (operator== 'C')
    {
        int account;
        printf("Insert account to close- ");
        scanf(" %d", &account);
        CloseAccount(account);
        return 1;
    }
    else if (operator== 'I')
    {
        int interest;
        printf("Set interest rate - \n");
        scanf(" %d", &interest);
        setInterest(interest);
        return 1;
    }
    else if (operator== 'P')
    {
        printOpenAccounts();
        return 1;
    }
    else if (operator== 'E')
    {
        Exit();
        return 0;
    }
    else
    {
        printf("Insert a value from the options- \n");
        return 1;
    }
}

//main loop
void mybank()
{
    int sit = 1;
    while (sit == 1)
    {
        sit = inBank();
    }
}


