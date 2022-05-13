#include<iostream>

void greatingsFunction();
int login();
void cls();

struct customerDetails
{
std::string accountNumber,name,email,username,password,address,mobile,aadhaarNumber,pan,dob;
double balance;
};


class personalBanking
{
    customerDetails data;

public:
personalBanking();
void personalBankingOptions();
void personForgotPassword();
void personTransaction(std::string &accountNumber, std::string &);
void logEntry(std::string &, double &, std::string &, double &, int &);


};

class accountOpening
{
    customerDetails data;

    public:
    accountOpening();
    void createAccount();
    friend std::istream& operator>>(std::istream &is, customerDetails &d );
    friend std::ostream& operator<<(std::ostream &os, customerDetails &d );
    int generateAccountNumber();
    void showFile();
    std::string generatePassword();
    void makeTransactionFile(std::string &fileName);
};


std::ostream& operator<<(std::ostream &os, customerDetails &d );
std::istream& operator>>(std::istream &is, customerDetails &d );
void showF();
