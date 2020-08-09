//start of code
#include <iostream>
#include <fstream>
#include <map>
#include <stdlib.h>
#define Min_BALANCE 500
using namespace std;
class Account
{
    //class properties
  private:
    long acc_no;
    string acc_name;
    float acc_balance;
    static long next_acc_no;
    //class behaviors
  public:
    //constructors
    Account();
    Account(string acc_name,float acc_balance);
    //Actions
    long get_acc_no();
    string get_acc_name();
    float get_acc_balance();
    float debosit(float amount);
    float withdraw(float amount);
    static void setLastAccountNumber(long accountnumber);
    static long getLastAccountNumber();
    friend ofstream & operator<<(ofstream &ofs,Account &acc);
    friend ifstream & operator>>(ifstream &ifs,Account &acc);
    friend ostream & operator<<(ostream &os,Account &acc);
};
class Bank
{
    //class properties
  private:
    map<long,Account> acc_list;  //a map structure to store the bank accounts on list

    //class behaviors
  public:

    //constructors
    Bank ();
    //Actions
    Account open_acc(string acc_name ,float balance);
    account show_acc (long acc_no);
    Account diposite(long acc_no ,float amount);
    Account withdraw(long acc_no ,float amount);
    float total_money ();
    void close_acc(long acc_no);
    void show_all_accs();
    bool is_acc_exist (long acc_no, string acc_name);
    //destructor
    ~Bank();
};
long Account::next_acc_no = 0;
int main()
{
    Bank b();
    Account acc;
    long choice,accnum;
    string name;
    float balance,amount;
try
{
    if (choice<1||choice>9)
        throw exception();
}
catch(exception e)
{
    cout<<"Error! choose number between 1:9"
}
    do
{
    //make a menu
cout<<"Banking System\n\n";
cout<<"         Select one Option below\n";
cout<<"         1.Create new Account\n";
cout<<"         2.Sign in Account and get Account Info \n";
cout<<"         3.Deposit Amount\n";
cout<<"         4.Withdraw Amount\n";
cout<<"         5.Show All Accounts\n";
cout<<"         6.close Account\n";
cout<<"         7.Exit\n";
cout<<"Enter your choice";
cin>>choice;
    switch(choice)
    {
case 1:
    cout<<"Enter your Account name and, Enter your Balance \n";
    b.open_acc(cin>>name,cin>>balance);
    cout<<"Congratulations, The Account is created \n";
    break;
case 2:
    cout<<"Enter your Account number \n" 
    b.show_acc(cin>>accnum);
    break;
case 3:
    cout<<"Enter your Account number and, the Balance you want to add \n";
    b.deposit(cin>>accnum,cin>>amount)
    break;
case 4:
    cout<<"Enter your Account number and, the Balance you want to get \n";
    b.withdraw(cin>>accnum,cin>>amount)
    break;
case 5:
    cout<<"All accounts in the bank \n"
    b.show_all_accs()
    break;
case 6:
    cout<<"Enter your Account number to remove it \n"
    b.close_acc(cin>>accnum)
    break;
case 7:
    cout<<"thank you for using my Bank,Goodbye \n"
    break;
    }
long Account::next_acc_no=0;


}
while(choice!=7);
}

//implementation of  Class account methods
Account::Account ()
{
}
Account::Account( string n,float bal)
{
    next_acc_no++;
    acc_no=next_acc_no;
    name=n;
    balance=bal;
}

long Account:: get_acc_no ()
{
    return accountnumber;
}
string Account::get_acc_name ()
{
    return acc_name;
}
float Account::get_acc_balance ()
	{
		return acc_balance;
	}
float Account::debosit (float amount)
{
    return  acc_balance+=amount;
}
float Account::withdraw (float amount)
{
    if(acc_balance - amount < Min_BALANCE
       )
    return acc_balance-=amount;
}
ofstream& operator<< (ofstream &ofs,account &acc)
	{
		ofs << "Account Number : " << acc.get_acc_no () << endl;
		ofs << "Account Name : " << acc.get_acc_name () << endl;
		ofs << "Account Balance : " << acc.get_acc_balance () <<endl;
		return ofs;
	}
ifstream& operator>> (ifstream &ifs,account &acc)
	{
		ifs >> acc.acc_no;
		getline (ifs, acc.acc_name) ;
		ifs >> acc.acc_balance;
		return ifs;
	}
ostream& operator<< (ostream &os,account &acc)
	{
		os << "Account Number : " << acc.get_acc_no () << endl;
		os << "Account Name : " << acc.get_acc_name () <<endl;
		os << "Account Balance : " << acc.get_acc_balance () << endl;
		return os;
	}
//implementation of  Class Bank methods
Bank::Bank ()
{
    Account acc;
}
Account Bank::open_acc (string acc_name, long acc_balance)
{
    Account acc(acc_name, acc_balance);
    accs_list.insert (pair<long, Account>(acc.get_acc_no(), acc));
    return acc;
}
Account Bank::show_acc (long acc_no)
{
    map<long, Account>::iterator itr = acc_list.find(acc_no);
    return itr -> second;
}
Account Bank::deposit (long acc_no, float amount)
{
    map<long, Account>::iterator itr = acc_list.find(acc_no);
    itr -> second.deposit(amount);
    return itr -> second;
}
Account Bank::withdraw (long acc_no, float amount)
{
    map<long, Account>::iterator itr = acc_list.find(acc_no);
    itr -> second.withdraw(amount);
    return itr -> second;
}
Account Bank::close_acc (long acc_no)
{
    map<long, Account>::iterator itr = acc_list.find(acc_no);
    acc_list.erase(acc_no)
}
float Bank::total_money ()//to show the sum of all account balance
{
    float sum=0.0;
    for(int x=acc_list.begin();x!=acc_list.end();x++)
    {
        sum += itr -> second.get_acc_balance ();
    }
    return sum;
}
void show_all_accs()
{
    for(x=acc_list.begin();x!=acc_list.end();x++)
    {
       cout<< itr -> second.show_acc(x)<<endl;
    }
}
bool is_acc_exist (long acc_no, string acc_name)
{
    map<long, Account>::iterator itr = acc_list.find(acc_no);
    if(itr -> second.get_acc_name () == acc_name )
            return true;
    else
    {
        cout<< "account is not exist \n";
        return false;
    }
}
Bank::~Bank ()
{

}



//End of my program
