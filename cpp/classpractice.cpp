#include <cstdlib>
#include <iostream>
#include <string>
#include <typeinfo>
using std::string;

class BankAccount{
  public:
    BankAccount();
    BankAccount(const int acctNum, const string& firstName, const string& lastName, const int initialDeposit);
    BankAccount(BankAccount& account);

    ~BankAccount();

    BankAccount& operator=(BankAccount& account);

    float getBalance();
    void withdrawAmount(float amount);
    void depositAmount(float amount);
    void sendAmount(BankAccount& recipientAccount, float amount);

    string firstName;
    string lastName;
    int acctNum;

  private:
    int ledger[100];
    int transactions = 0;
    float balance;
};

//default constructor
BankAccount::BankAccount(){
  this->acctNum = 99;
  this->firstName = "None";
  this->lastName = "None";
  this->balance = 0;
}

//constructor w/ initializer list
BankAccount::BankAccount(const int acctNum, const string& firstName, const string& lastName, const int initialDeposit)
  : acctNum(acctNum), firstName(firstName), lastName(lastName), balance(initialDeposit) {

    std::cout << "Created account for " << lastName <<", " << firstName << ". Account Number: " << acctNum << " Balance: $" <<initialDeposit << std::endl;
  }
  
//copy constructor
BankAccount::BankAccount(BankAccount& account){
  this->acctNum = account.acctNum;
  this->firstName = account.firstName;
  this->lastName = account.lastName;
  
  // float transferBalance = account.getBalance();
  // this->balance = transferBalance;
  // account.withdrawAmount(transferBalance);

  std::cout << "using copy constructor" << std::endl;

}


//destructor
BankAccount::~BankAccount() {
  //delete [] //x dynamic
}

//overloading operator assignment
BankAccount& BankAccount::operator=(BankAccount& account) {
  if (this != &account){
    this->acctNum = account.acctNum;
    this->firstName = account.firstName;
    this->lastName = account.lastName;
  }

  std::cout << "using assign operator" << std::endl;

  return *this;
}


float BankAccount::getBalance() {
  float currentBalance = this->balance;
  std::cout << "current balance is: $" <<currentBalance << std::endl;
  return currentBalance;
}


void BankAccount::withdrawAmount(float amount){
  float afterWithdrawBalance = this->balance - amount;
  if (afterWithdrawBalance >= 0) {
    this->balance -= amount;
    std::cout << "withdrew $ "<< amount <<". current balance is: $" <<this->balance << std::endl;
  } else {
    std::cout << "failed to withdraw $ "<< amount <<". insufficient funds - current balance is: $" <<this->balance << std::endl;

  }
}


void BankAccount::depositAmount(float amount){
  this->balance += amount;
  std::cout << "deposited $ "<< amount <<". current balance is: $" <<this->balance << std::endl;

}

void BankAccount::sendAmount(BankAccount& recipientAccount, float amount){
  float afterSendBalance = this->balance - amount;
  if (afterSendBalance >= 0) {
    this->balance -= amount;
    recipientAccount.depositAmount(amount);
    std::cout << "sent "<< recipientAccount.firstName << " $ "<< amount <<". current balance is: $" <<this->balance << std::endl;
  } else {
    std::cout << "failed to send "<< recipientAccount.firstName << " $ "<< amount <<". insufficient funds - current balance is: $" <<this->balance << std::endl;

  }
}



int main() {
  BankAccount* acct = new BankAccount(0, "Michael", "Pham", 10);
  
  BankAccount* acct2 = new BankAccount(0, "Ipek", "Icten", 10);

  acct->sendAmount(*acct2, 8);
  float bal = acct->getBalance();
  float bal2 = acct2->getBalance();


  // float bal = acct->getBalance();
  // acct->depositAmount(3);
  // float bal2 = acct->getBalance();
  // acct->withdrawAmount(11);
  // float bal3 = acct->getBalance();


  // BankAccount acct2 = *acct;
  // BankAccount acct3;
  // acct3 = acct2;
  return 0;
}