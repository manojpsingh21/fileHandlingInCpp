#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<ctime>
#include"fns.h"

void greatingsFunction()
{
    std::string message2 = "BHARAT KA RATNA STATE BANK OF INDIA";
    std::string message1 = "WELCOME TO SBI BANK ONLINE PORTAL(WAGLE ESTATE BRANCH)";
    
    for(int i=0 ; i<50 ;i++)
    {
        std::cout<<"--";
    }
    std::cout<<std::endl;

    for(int i=0 ; i<10 ;i++)
    {
        std::cout<<"|";
        for(int k=0 ;k<98 ;k++)
        {

            if(i==3 && k==20 )
            {
               std::cout<<message1;
               for(int c =1; c<79-message1.size(); c++)
               {
                   std::cout<<" ";
               }
               break;
            }


            if(i==5 && k==30 )
            {
               std::cout<<message2;
               for(int c =1; c<69-message2.size(); c++)
               {
                   std::cout<<" ";
               }
               break;
            }

            std::cout<<" ";
        }

        std::cout<<"|"<<std::endl;
    }

    for(int i=0 ; i<50 ;i++)
    {
        std::cout<<"--";
    }
    

}

int login()

{
    int option;
    std::cout<<"\t 1.Personal Banking\t 2.Bank Officer Login\t  3.New Account Opening\n\n";
    std::cout<<"Please Enter Number Respectively\n";
    std::cin>>option;
    if(option>0 && option<=3)
    {
        return option;
    }
    else
    {
        std::cout<<"Incorrect entry.Terminating Program ....";
         return 0;
    }
}

void cls()
{
    system("cls||clear");
}

personalBanking::personalBanking()
{
    std::cout<<"constructor evoked"<<std::endl;
    
    std::cout<<"----------------Personal Banking Portal----------------\n\n";

    std::cout<<"1.Login\t   2.Forgot Password\n\n";

}

accountOpening::accountOpening()
{
    int option;
   std::cout<<"----------------Account Opening Portal----------------\n";
   std::cout<<"1.Bank Officer\t 2.New Customer\n";
   std::cout<<"Option:";
   std::cin>>option;
    if(option !=1 && option !=2)
    {
        std::cout<<"Invalid Entry.Terminating Program....\n";
    }

    if(option == 1)
    {
        cls();
        std::cout<<"-------------------BANK OFFICER MODE-------------------\n";

    }

    if(option == 2)
    {
        cls();
        std::cout<<"-------------------NEW ONINE ACCOUNT CREATION MODE-------------------\n";
        accountOpening::createAccount();
    }

}


std::ostream& operator<<(std::ostream &os,  customerDetails & d )
{
    // os<<d.name<<"|"<<d.mobile<<"|"<<d.address<<"|"<<d.aadhaarNumber<<"|"<<d.pan<<"|"<<d.dob<<std::endl;

        os<<d.name;

         if(d.name.size() <=40 && d.name.size() > 0)
        {
            for(int i = 1; i<=39-d.name.size(); i++)
            {
                os<<" ";

            }
        }
        os<<" |";

        os<<d.mobile;
        if(d.mobile.size() <=10 && d.mobile.size() > 0)
        {
            for(int i = 1; i<=10-d.mobile.size(); i++)
            {
                os<<" ";

            }
        }
    os<<" ";
        os<<d.address;
         if(d.address.size() <=100 && d.address.size() > 0)
        {
            for(int i = 1; i<=98-d.address.size(); i++)
            {
                os<<" ";

            }
        }
        os<<" |";
        os<<d.aadhaarNumber;
        
        if(d.aadhaarNumber.size() <=12 && d.aadhaarNumber.size() > 0)
        {
            for(int i = 1; i<=12-d.aadhaarNumber.size(); i++)
            {
                os<<" ";

            }
        }

        os<<" ";
        os<<d.pan;
         if(d.pan.size() <=10 && d.pan.size() > 0)
        {
            for(int i = 1; i<=10-d.pan.size(); i++)
            {
                os<<" ";

            }
        }

        os<<" ";
        os<<d.dob;

         if(d.dob.size() <=10 && d.dob.size() > 0)
        {
            for(int i = 1; i<=10-d.dob.size(); i++)
            {
                os<<" ";

            }
        }
         os<<" ";
    return os;
}

std::istream& operator>>(std::istream &is, customerDetails &data)
{
        std::cout<<"Name: ";
        getline(is, data.name, '\n');

        std::cout<<"Mobile: ";
        is>>data.mobile;
        getchar();
        std::cout<<"Address: ";
        getline(is, data.address, '\n');
        std::cout<<"Aadhaar Number: ";
        is>>data.aadhaarNumber;
        is.ignore();
        std::cout<<"PAN Number: ";
        is>>data.pan;
        is.ignore();
        std::cout<<"Date Of Birth(DDMMYYYY): ";
        is>>data.dob;
        return is;

}

 void accountOpening::createAccount()
    {
        std::cout<<"IN ACCOUNT CREATION MODE"<<std::endl;

        std::fstream file;
        file.open("abc.txt", std::ios::app|std::ios::in|std::ios::out);
       
        std::getchar();
        customerDetails data;
        std::string password = generatePassword();
        std::cin>>data;

        file<<data;
        int serialNumber = generateAccountNumber();
        file<<serialNumber<<" 0.000000"<<" ";
        file<<password<<std::endl;

        std::string fileName = std::to_string(serialNumber);
        fileName = fileName + ".txt";
        makeTransactionFile(fileName);
        // std::string test;
        // std::getline(std::cin, test, '\n' );
        // file<<test;



    }

void accountOpening::makeTransactionFile(std::string &fileName)
{
    std::fstream file;

    file.open(fileName, std::ios::app);

    time_t t = time(0);
    char *dt = ctime(&t); 
    
    file.seekg(0, std::ios::beg);
    int begin = file.tellg();
    file.seekg(0, std::ios::end);
    int end = file.tellg();
   
    if(begin == end)
    {

        char ch;
        int i=0;
        std::string s;
        while(1)
        {
            ch=dt[i++];
            if(ch=='\n')
            {
                break;
            }
            s.push_back(ch);

        }
         file<<s<<" "<<"SBI OPEN|SBI BANK OPENING LOG          |0.000000000 0.000000000"<<std::endl;;

        file.close();
    }  

    //   if(begin != end)
    // {
        
    // file<<dt<<" "<<
    
    
    
    
    // }



    
    // tm *gtm = gmtime(&t);
    // dt = asctime(gtm);
    // std::cout<<"local2 Date and Time :"<<dt<<std::endl;
    

}

    std::string accountOpening::generatePassword()
    {
        std::string password1,password2;
        std::cout<<"Please Enter Password For Account Login :";
        std::cin>>password1;
        std::cout<<"\nConfirm Password: ";
        std::cin>>password2;

        getchar();
        if(password1 != password2)
        {
            std::cout<<"Different passwords.Try again later.";
            std::exit(0);
        }
        
        if(password1.size() <15 && password1.size()>0)
        {
            if(password1 == password2)
            {   

                for(int i =1; i<=15-password2.size(); i++)
                {
                        password1 = password1 + " ";
                }
                std::cout<<"password1.size()="<<password1.size()<<std::endl;
                return password1;
            }

        }
        else
        {
            std::cout<<"Password must be less than 15 characters and greater than 5 characters";
            exit(0);
        }
    }


int accountOpening:: generateAccountNumber()
        {
           std::fstream file;
           file.open("accountNumbersFile.txt", std::ios::app|std::ios::in|std::ios::out);
    file.seekg(0, std::ios::beg);
    int begin = file.tellg();
    file.seekg(0, std::ios::end);
    int end = file.tellg();
    std::string initialSerialNumber, serialNumber;
    if(begin == end)
    {
        std::cout<<"Please enter the initial serial number to start generating account number from here:";
        std::cin>>initialSerialNumber;
        file<<initialSerialNumber<<"\n";
        return std::stoi(initialSerialNumber);
    }
 
        if(begin != end)
    {
        file.seekg(-10, std::ios::end);
        std::getline(file, serialNumber, '\n' );
        int nextSerialNumber = std::stoi(serialNumber) +1;
        file<<nextSerialNumber<<"\n";
        std::cout<<"Account Number Generated : "<<nextSerialNumber<<std::endl;
        std::cout<<"WELCOME, Thank You For choosing SBI BANK.";
        return nextSerialNumber;
    }
    file.close();
           
        }

        void accountOpening ::showFile()
        {

            char ch;
            std::fstream file("abc.txt", std::ios::in|std::ios::out);
            file.seekg(188, std::ios::beg);
            file.get(ch);
            std::cout<<"at 40="<<ch<<std::endl;
        }
    void showF()
    {
                 {

            char ch;
            std::string str;
            std::fstream file("abc.txt", std::ios::in|std::ios::out);
            file.seekg(187, std::ios::beg);
            // file.get(ch);
            getline(file, str, '\n');
            std::cout<<"at 40="<<str<<std::endl;
        }
    }








// Personal Information

void personalBanking::personalBankingOptions()
{
    customerDetails data;
    int currentLocationAcc,currentLocationPass,backtrack;
    std::string name,mobile,aadhar,pan,dob,address,balance,account;
    std::cout<<"     Account Number:";
    std::cin>>data.accountNumber;
    std::cout<<"     Password:";
    std::cin>>data.password;

    std::fstream file;
    file.open("abc.txt", std::ios::app|std::ios::in|std::ios::out);

    file.seekg(0, std::ios::beg);
    file.seekg(187, std::ios::beg);
     currentLocationAcc = file.tellg();
    std::cout<<"current="<<file.tellg()<<std::endl;
    std::string readedAccountNumber, readedPassword;
    getline(file, readedAccountNumber, ' ');
    file.seekg(currentLocationAcc, std::ios::beg);
    file.seekg(18, std::ios::cur); //this location 
    currentLocationPass = file.tellg();
    getline(file, readedPassword, ' '); 
    file.seekg(currentLocationPass, std::ios::beg);
     std::cout<<"Account1="<<readedAccountNumber<<"  Password1="<<readedPassword<<std::endl;

      if(readedAccountNumber == data.accountNumber && readedPassword == data.password)
      { 

            file.seekg(0, std::ios::beg);
            getline(file, name, '|' );
            std::cout<<"Name: "<<name<<std::endl;

            file.seekg(0, std::ios::beg);
            file.seekg(41, std::ios::beg);
            getline(file, mobile , ' ' );
            std::cout<<"Mobile: "<<mobile<<std::endl;

            file.seekg(0, std::ios::beg);
            file.seekg(52, std::ios::beg);
            getline(file, address , '|' );
            std::cout<<"Address: "<<address<<std::endl;

            file.seekg(0, std::ios::beg);
            file.seekg(152, std::ios::beg);
            getline(file, aadhar , ' ' );
            std::cout<<"Aadhar: "<<aadhar<<std::endl;


            file.seekg(0, std::ios::beg);
            file.seekg(165, std::ios::beg);
            getline(file, pan , ' ' );
            std::cout<<"PAN: "<<pan<<std::endl;

            file.seekg(0, std::ios::beg);
            file.seekg(176, std::ios::beg);
            getline(file, dob , ' ' );
            std::cout<<"Date Of Birth: "<<dob<<std::endl;

            file.seekg(0, std::ios::beg);
            file.seekg(187, std::ios::beg);
            getline(file, account , ' ' );
            std::cout<<"Account: "<<account<<std::endl;

            file.seekg(0, std::ios::beg);
            file.seekg(196, std::ios::beg);
            getline(file, balance , ' ' );
            std::cout<<"Current Balance: "<<balance<<std::endl;

            file.seekg(currentLocationPass, std::ios::beg);  
            
            file.close();
            personTransaction(account, name); 
          }
          else
          {

              while(file.good())
    {  
                   std::cout<<"In loop :"<<std::endl;

        file.seekg(222, std::ios::cur);
        currentLocationPass = file.tellg();
        getline(file, readedPassword, ' '); 
        file.seekg(currentLocationPass, std::ios::beg);
        file.seekg(-18, std::ios::cur);
        currentLocationAcc = file.tellg();
        getline(file, readedAccountNumber , ' '); 
        file.seekg(currentLocationAcc, std::ios::beg);
        file.seekg(18, std::ios::cur);
        currentLocationPass = file.tellg();
        std::cout<<"tellGGG="<<file.tellg()<<std::endl;

        std::cout<<"Account111="<<readedAccountNumber<<"  Password111="<<readedPassword<<std::endl;
       if(readedAccountNumber == data.accountNumber && readedPassword == data.password)
       { 
           file.seekg(currentLocationPass, std::ios::beg);
           std::cout<<"In if password correct :"<<std::endl;
           
            file.seekg(-205, std::ios::cur);
            backtrack = file.tellg();
            getline(file, name, '|' );
            file.seekg(backtrack, std::ios::beg);
            std::cout<<"Name: "<<name<<std::endl;

            file.seekg(41, std::ios::cur);
            backtrack = file.tellg();
            getline(file, mobile, ' ');
            file.seekg(backtrack, std::ios::beg);
            std::cout<<"Mobile="<<mobile<<std::endl;

            file.seekg(11, std::ios::cur);
            backtrack = file.tellg();
            getline(file, address, '|');
            std::cout<<"Address: "<<address<<std::endl;
            
            file.seekg(backtrack, std::ios::beg);
            file.seekg(100, std::ios::cur);
            backtrack = file.tellg();
            getline(file, aadhar, ' ');
            std::cout<<"Aadhar: "<<aadhar<<std::endl;

            file.seekg(backtrack, std::ios::beg);
            file.seekg(13, std::ios::cur);
            backtrack = file.tellg();
            getline(file, pan, ' ');
            std::cout<<"PAN Number: "<<pan<<std::endl;

            file.seekg(backtrack, std::ios::beg);
            file.seekg(11, std::ios::cur);
            backtrack = file.tellg();
            getline(file, dob, ' ');
            std::cout<<"Date Of Birth: "<<dob<<std::endl;

            file.seekg(backtrack, std::ios::beg);
            file.seekg(11, std::ios::cur);
            backtrack = file.tellg();

            getline(file, account, ' ');
            std::cout<<"Account: "<<account<<std::endl;

            file.seekg(backtrack, std::ios::beg);
            file.seekg(9, std::ios::cur);
            backtrack = file.tellg();
            getline(file, balance, ' ');
            std::cout<<"Available Balance: "<<balance<<std::endl;

            file.seekg(backtrack, std::ios::beg);
            file.seekg(9, std::ios::cur);


std::cout<<"-----------------------------------------------------------------------------------------------"<<std::endl;
file.close();
personTransaction(account, name);
break;
       }
     
        //  displayDetails();
         if(file.good() ==0)
         {
             std::cout<<"No Customer with this credential found\n";
             std::cout<<"Try with valid credentials."<<std::endl;
         }
    }       

          }

}



void personalBanking::personForgotPassword()
{

    std::cout<<"In peronal banking forgot password section";
}
 void personalBanking::personTransaction(std::string &account, std::string &senderName)
 {

    std::fstream file;
    file.open("abc.txt", std::ios::in|std::ios::out);
    std::cout<<"1.Deposit\t 2.Withdrawl\t 3.Tranfer"<<std::endl;
    int option;
      std::cin>>option;
    std::string accountNumber,currentAmount,receiverAccountNumber;
    if(option>0 && option<4)
    {
       
            double withdrawlAmount,backtrack;
            
            if(option == 1 )
            {
                std::cout<<"Deposit Amount: ";
            }
            
            if(option == 2)
            {
                std::cout<<"Withdrawl Amount: ";
            }

            if(option == 3)
            {
                std::cout<<"Transfer Amount: ";
            }


            std::cin>>withdrawlAmount;

          
    

            if(withdrawlAmount>1000000)
            {
                std::cout<<"Amount cannot be greater than 1000000(10Lakhs)"<<std::endl;
                std::cout<<"Terminating program....";
                exit(0);
            }
            file.seekg(187, std::ios::beg);
            backtrack = file.tellg();   
            getline(file, accountNumber, ' ');
            file.seekg(backtrack, std::ios::beg);
            std::cout<<"Account Number found found: "<<accountNumber<<"\n";
            getchar();
            if(accountNumber == account)
            {
                file.seekg(9, std::ios::cur);
                backtrack = file.tellg();
                std::cout<<"tellg="<<backtrack<<std::endl;
                backtrack = file.tellp();

                std::cout<<"tellp="<<file.tellp()<<std::endl;
                getline(file, currentAmount, ' ');
                file.seekp(backtrack, std::ios::beg);
                std::cout<<"currentAmount:"<<currentAmount<<std::endl;
                double currentAmountDouble =  std::stod(currentAmount);
                 if(option == 1)
                {   
                     personalBanking:: logEntry(accountNumber, currentAmountDouble, senderName, withdrawlAmount, option);
                     currentAmountDouble = currentAmountDouble + withdrawlAmount;
                     std::cout<<"currentAmountDouble="<<currentAmountDouble<<std::endl;
                 currentAmount = std::to_string(currentAmountDouble);
                 std::cout<<"to string ="<<currentAmount<<"and size ="<<currentAmount.size()<<std::endl;

                int loop = currentAmount.size() - 8;

                    for(int i=1 ;i<=loop ;i++)
                     {
                        currentAmount.pop_back();
                     }

                 std::cout<<"to string ="<<currentAmount<<"and size ="<<currentAmount.size()<<std::endl;
                 
                 file<<currentAmount;
                file.close();
                

                }
                if(currentAmountDouble >= withdrawlAmount && option == 2 )
                {
                      logEntry(accountNumber, currentAmountDouble, senderName, withdrawlAmount, option);
                 currentAmountDouble = currentAmountDouble - withdrawlAmount;
                 std::cout<<"currentAmountDouble="<<currentAmountDouble<<std::endl;
                 currentAmount = std::to_string(currentAmountDouble);
                 std::cout<<"to string ="<<currentAmount<<"and size ="<<currentAmount.size()<<std::endl;
                 

                for(int i=1 ;i<=3 ;i++)
                {
                    currentAmount.pop_back();
                }

                  std::cout<<"to string ="<<currentAmount<<"and size ="<<currentAmount.size()<<std::endl;
                  file<<currentAmount;

                 file.close();
    
            }




             if(currentAmountDouble >= withdrawlAmount && option == 3)
                {
                    double d = currentAmountDouble;
                     std::cout<<"currentAmountDouble In OPTION 3="<<currentAmountDouble<<std::endl;
                   
                    currentAmountDouble = currentAmountDouble - withdrawlAmount;
                    std::cout<<"currentAmountDouble="<<currentAmountDouble<<std::endl;
                 currentAmount = std::to_string(currentAmountDouble);
                 std::cout<<"to string ="<<currentAmount<<"and size ="<<currentAmount.size()<<std::endl;

                int loop = currentAmount.size() - 8;

                    for(int i=1 ;i<=loop ;i++)
                     {
                        currentAmount.pop_back();
                     }

                 std::cout<<"to string33333 ="<<currentAmount<<"and size ="<<currentAmount.size()<<std::endl;
                  file.seekp(backtrack, std::ios::beg);
                 file<<currentAmount;
                    file.close();
                     logEntry(accountNumber, d, senderName, withdrawlAmount, option);
                }



            }
            else
            {
                while(file.good())
                {   
                    file.seekg(222, std::ios::cur);
                    backtrack = file.tellp();

                    getline(file, accountNumber, ' ');
                     file.seekg(backtrack, std::ios::beg);
                    if(accountNumber == account)
                    {
                        file.seekg(9, std::ios::cur);
                backtrack = file.tellg();
                std::cout<<"tellg="<<backtrack<<std::endl;
                backtrack = file.tellp();

                std::cout<<"tellp="<<file.tellp()<<std::endl;
                getline(file, currentAmount, ' ');
                file.seekp(backtrack, std::ios::beg);
                std::cout<<"currentAmount:"<<currentAmount<<std::endl;
                double currentAmountDouble =  std::stod(currentAmount);
                
                if(option == 1)
                {   
                      logEntry(accountNumber, currentAmountDouble, senderName, withdrawlAmount, option);
                     currentAmountDouble = currentAmountDouble + withdrawlAmount;
                     std::cout<<"currentAmountDouble="<<currentAmountDouble<<std::endl;
                 currentAmount = std::to_string(currentAmountDouble);
                 std::cout<<"to string ="<<currentAmount<<"and size ="<<currentAmount.size()<<std::endl;

                int loop = currentAmount.size() - 8;

                    for(int i=1 ;i<=loop ;i++)
                     {
                        currentAmount.pop_back();
                     }

                 std::cout<<"to string ="<<currentAmount<<"and size ="<<currentAmount.size()<<std::endl;
                 
                 file<<currentAmount;
                file.close();
                 break;

                }
                  if(currentAmountDouble <= withdrawlAmount && option == 2)
                {
                    std::cout<<"Insufficient Balance.";
                    exit(0);
                }
                if(currentAmountDouble >= withdrawlAmount && option == 2)
                {
                    logEntry(accountNumber, currentAmountDouble, senderName, withdrawlAmount, option);
                    currentAmountDouble = currentAmountDouble - withdrawlAmount;
                    std::cout<<"currentAmountDouble="<<currentAmountDouble<<std::endl;
                 currentAmount = std::to_string(currentAmountDouble);
                 std::cout<<"to string ="<<currentAmount<<"and size ="<<currentAmount.size()<<std::endl;

                int loop = currentAmount.size() - 8;

                    for(int i=1 ;i<=loop ;i++)
                     {
                        currentAmount.pop_back();
                     }

                 std::cout<<"to string ="<<currentAmount<<"and size ="<<currentAmount.size()<<std::endl;
                   
                 file<<currentAmount;
                file.close();
                 break;
                }

                if(currentAmountDouble >= withdrawlAmount && option == 3)
                {

                    std::cout<<"in loop option 3"<<std::endl;
                  double d = currentAmountDouble;
                    currentAmountDouble = currentAmountDouble - withdrawlAmount;
                    std::cout<<"currentAmountDouble="<<currentAmountDouble<<std::endl;
                 currentAmount = std::to_string(currentAmountDouble);
                 std::cout<<"to string ="<<currentAmount<<"and size ="<<currentAmount.size()<<std::endl;

                int loop = currentAmount.size() - 8;

                    for(int i=1 ;i<=loop ;i++)
                     {
                        currentAmount.pop_back();
                     }

                 std::cout<<"to string ="<<currentAmount<<"and size ="<<currentAmount.size()<<std::endl;
                 file<<currentAmount;
                  file.close();
                logEntry(accountNumber, d, senderName, withdrawlAmount, option);
                 break;
               





                }

                }
                if(file.good() ==0)
         {
             std::cout<<"No Customer with this credential found\n";
             std::cout<<"Try with valid credentials."<<std::endl;
         }
            }

                }
            }

    
    else
    {
        std::cout<<"Invalid Entry.Terminating Program...";
        exit(0);
    }
 }
        
void personalBanking::logEntry(std::string &accountNumber, double &currentAmount, std::string &senderName, double &transferAmount, int &option)
{

        int backtrack;
        
     
      std::fstream file,file1,file2;
     file.open("abc.txt", std::ios::in|std::ios::out);
 
           
      std::string currentAmount1,accountNumber1,transferAmountS;

      transferAmountS = std::to_string(transferAmount);
      if(transferAmountS.size()>8)
      {
          while(transferAmountS.size()>8)
        {
            transferAmountS.pop_back();
        }   
      }

         if(transferAmountS.size()<=8)
      {
          while(transferAmountS.size()<=8)
        {
            transferAmountS.push_back(' ');
        }   
      }
     std::string fileName2 = accountNumber + ".txt";
    
     time_t t1 = time(0);
     char *dt1 = ctime(&t1); 
        char ch;
        int i=0;
        std::string s;
        while(1)
        {
            ch=dt1[i++];
            if(ch=='\n')
             {
                break;
            }
            s.push_back(ch);
        }
         std::string name = senderName;

    for(int i=1 ; i<=10; i++)
    {
        name.pop_back();
    }

        if(option == 1)
        {
            double netAmmount = transferAmount + currentAmount;
            std::string netAmmountString = std::to_string(netAmmount);
            file1.open(fileName2, std::ios::app);
            file1<<s<<" "<<accountNumber<<" "<<"SELF DEPOSIT                 "<<" "<<transferAmountS<<" "<<currentAmount1<<std::endl;
            file1.close();  
        }    

        if(option == 2)
        {
            double netAmmount = transferAmount - currentAmount;
            std::string netAmmountString = std::to_string(netAmmount);
            transferAmountS = "-" + transferAmountS;
            file1.open(fileName2, std::ios::app);
            file1<<s<<" "<<accountNumber<<" "<<"SELF WITHDRAWL               "<<" "<<transferAmountS<<" "<<currentAmount1<<std::endl;
            file1.close();
        }  


          if(option == 3)
        {           
                std::string senderAccountNumber;
                std::cout<<"Enter the Account Number to whom you want to transfer: ";
                std::cin>>senderAccountNumber;
            std::string fileName = senderAccountNumber + ".txt";
    
            file1.open(fileName, std::ios::app);
            file2.open(fileName2, std::ios::app);

            file.seekg(187, std::ios::beg);
            backtrack = file.tellg();   
            getline(file, accountNumber1, ' ');
            file.seekg(backtrack, std::ios::beg);
            std::cout<<"Account Number found1111: "<<accountNumber1<<"\n";

             if(accountNumber1 == senderAccountNumber)
            {
                file.seekg(9, std::ios::cur);
                backtrack = file.tellg();
                std::cout<<"tellg="<<backtrack<<std::endl;
                backtrack = file.tellp();

                std::cout<<"tellp="<<file.tellp()<<std::endl;
                getline(file, currentAmount1, ' ');
                file.seekp(backtrack, std::ios::beg);
                std::cout<<"currentAmount1:"<<currentAmount1<<std::endl;
                 double currentAmountDouble =  std::stod(currentAmount1);


                currentAmountDouble = currentAmountDouble + transferAmount;
                std::cout<<"currentAmountDouble="<<currentAmountDouble<<std::endl;
                 currentAmount1 = std::to_string(currentAmountDouble);
                 std::cout<<"to string111212  currentAmountDouble="<<currentAmount1<<"and size ="<<currentAmount1.size()<<std::endl;

                int loop = currentAmount1.size() - 8;

                    for(int i=1 ;i<=loop ;i++)
                     {
                        currentAmount1.pop_back();
                     }
                 
                 file<<currentAmount1;
                 file.close();
           
                 file1<<s<<" "<<accountNumber<<" "<<name<<" "<<transferAmountS<<" "<<currentAmount1<<std::endl;
                 file1.close();
                 if(senderAccountNumber.size()<30)
                 {
                         for(int i = 1 ; i<=22 ;i++)
                         {
                             senderAccountNumber.push_back(' ');
                         }
                 }
               
                
                 file2<<s<<" "<<"TRANSFER"<<" "<<senderAccountNumber<<" "<<transferAmountS<<" "<<currentAmount1<<std::endl;
                 file2.close();
        }  
        else
            {
                while(file.good())
                {   

                    std::cout<<"In while loop"<<std::endl;
                    file.seekg(222, std::ios::cur);
                    backtrack = file.tellp();

                    getline(file, accountNumber1, ' ');
                     file.seekg(backtrack, std::ios::beg);
                    std::cout<<"account i while11111 ="<<accountNumber1<<" acc22="<<accountNumber1<<std::endl;
                   
                    if(accountNumber1 == senderAccountNumber)
                    {
                        file.seekg(9, std::ios::cur);
                backtrack = file.tellg();
                std::cout<<"tellg="<<backtrack<<std::endl;
                backtrack = file.tellp();

                std::cout<<"tellp="<<file.tellp()<<std::endl;
                getline(file, currentAmount1, ' ');
                file.seekp(backtrack, std::ios::beg);
                std::cout<<"currentAmount:"<<currentAmount<<std::endl;
                double currentAmountDouble =  std::stod(currentAmount1);

                currentAmountDouble = currentAmountDouble + transferAmount;

                 std::cout<<"currentAmountDouble="<<currentAmountDouble<<std::endl;
                 currentAmount1 = std::to_string(currentAmountDouble);
                 std::cout<<"to string  currentAmountDouble="<<currentAmount1<<"and size ="<<currentAmount1.size()<<std::endl;

                int loop = currentAmount1.size() - 8;

                    for(int i=1 ;i<=loop ;i++)
                     {
                        currentAmount1.pop_back();
                     }

                 std::cout<<"to string ="<<currentAmount<<"and size ="<<currentAmount1.size()<<std::endl;
                 
                  
                 file<<currentAmount1;
                 file.close();
                 file1<<s<<" "<<accountNumber<<" "<<name<<" "<<transferAmountS<<" "<<currentAmount1<<std::endl;
                 file1.close();
                     
                 if(senderAccountNumber.size()<30)
                 {
                         for(int i = 1 ; i<=22 ;i++)
                         {
                             senderAccountNumber.push_back(' ');
                         }
                 }

                 file2<<s<<" "<<accountNumber<<" "<<senderAccountNumber<<" "<<transferAmountS<<" "<<currentAmount1<<std::endl;
                 file2.close();
                 break;    

                    }
                }
            }

        }

}