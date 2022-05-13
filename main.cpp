#include<iostream>
#include"includes/fns.h"

int main()
{

greatingsFunction();
std::cout<<"\n\n";

int loginOption = login();

if(loginOption == 1)
{
    cls();
    personalBanking person;
    int personalBankingOption;
    std::cin>>personalBankingOption;
    if(personalBankingOption !=1 && personalBankingOption !=2)
    {
        std::cout<<"Invalid Entry.Terminating Program..."<<std::endl;
    }
    if(personalBankingOption == 1)
    {
        person.personalBankingOptions();
    }
    if(personalBankingOption == 2)
    {
        person.personForgotPassword();
        
    }

}

if(loginOption == 2)
{

    cls();
    std::cout<<"---------------- Bank Officer Portal----------------";



}

if(loginOption == 3)
{
    cls();
    accountOpening op;   

}





















return 0;














































}