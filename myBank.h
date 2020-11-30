#ifndef myBank_H
#define myBank_H
void OpenAccount(double amount);
void CheckBalance(int account);
void AddToBalance(int account, double amount);
void drawFromBank(int account, double amount);
void CloseAccount(int account);
void setInterest(int interest);
void printOpenAccounts();
void CloseAccountPretty(int account);
void Exit();
int inBank();
void mybank();
#endif
