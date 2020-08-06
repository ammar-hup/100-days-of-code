//start of the program
//preprocessor directives
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <map>
#define ll long long
#define MIN_BALANCE 500
//exception handling classes
class opt_error {};
class balance_errror {};
//program main classes
class account
{
	//class properties
	private:
		ll	acc_num;				//account number (automatically set)
		std::string	acc_name;		//account name (user set)
		ll	acc_balance;			//account palance (withdraw-->useer set<--deposit)
		std::string	account_pass;	//account password (user set)
		static	ll	next_acc_num;	//for automatically change the account number
	//class behaviors	
	public:
		//constructors
		account ();
		account	(ll acc_num, std::string acc_name, ll acc_balance, std::string account_pass);
		//mutators
		std::string	set_acc_name ();
		ll set_acc_balance ();
		std::string set_acc_pass ();
		static void set_last_acc_num (ll acc_num);
		//accessors
		static ll get_last_acc_num ();
		//operations overloading
		friend std::ofstream& operator<< (std::ofstream &ofs,account &acc);
		friend std::ifstream& operator>> (std::ifstream &ifs,account &acc);
		friend std::ostream& operator<< (std::ostream &os,account &acc);
};

class bank
{
	//properties
	private:
		std::map<ll, account> accs_list;	//map structure to list the bank accounts
	//class behaviors
	public:
		//constructors
		bank ();
		//facilitators
		account open_acc (std::string acc_name, ll acc_balance, std::string acc_pass);
		account view_acc (std::string acc_pass);
		account deposit (std::string acc_name);
		account withdraw (std::string acc_pass);
		void close_acc (std::string acc_pass);
		void show_accs_list ();
		ll total_balance ();
		//destructor
		~bank ();
};

//start of the main function
int main ()
{
	//an option button for choosing the category
	int option;
	//account object and its properties to store users inputs
	account acc;
	ll acc_num;
	std::string	acc_name;
	ll	acc_balance;
	std::string	account_pass;

	//a do while function to cntroll the program working span
	do
	{
		//intial menu
		std::cout << "			Welcome to MG Banking System			\n\n";
		std::cout << "For Clients Services Enter (1).\n";
		std::cout << "For Managers Services Ebter (2).\n";
		std::cout << "For Exit The System Enter (3).\n";
		//option picker
		std::cin >> option;
		//exception handling for choosing nonexisting number
		try
		{
			if (option != 1 || option != 2 || option != 3)
				throw opt_error();
		}
		catch (opt_error r)
		{
			
		}
		//if-else loop for choices
	}
	while (option != 3);
}
//end of the main function
//end of the program