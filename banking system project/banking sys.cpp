//start of the program
//preprocessor directives
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <string>
#define ll long long
#define MIN_BALANCE 500
//exception handling classes
class opt_error {};
class balance_errror {};
class security_error {};
//program main classes
class account
{
	//class properties
	private:
		ll	acc_num;				//account number (automatically set)
		std::string	acc_name;		//account name (user set)
		long double acc_balance;	//account palance (withdraw-->useer set<--deposit)
		std::string	account_pass;	//account password (user set)
		static	ll	next_acc_num;	//for automatically change the account number
	//class behaviors	
	public:
		//constructors
		account ();
		account	(ll acc_num, std::string acc_name, ll acc_balance, std::string account_pass);
		//accessors
		ll get_acc_num ();
		std::string	get_acc_name ();
		long double get_acc_balance ();
		std::string get_acc_pass ();
		static void set_last_acc_num (ll acc_num);
		//mutators
		static ll get_last_acc_num ();
		//facilitators
		void deposit (long double amount);
		void withdraw (long double amount);
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
		std::string bank_password = "mgbankcpp";
	//class behaviors
	public:
		//constructors
		bank ();
		//facilitators
		account open_acc (std::string acc_name, ll acc_balance, std::string account_pass);
		account view_acc (std::string account_pass);
		account deposit (std::string acc_name);
		account withdraw (std::string account_pass);
		void close_acc (std::string account_pass);
		int bank_id (std::string bank_password);
		void show_accs_list ();
		ll total_balance ();
		//destructor
		~bank ();
};
//static members
	ll account::next_acc_num = 0;
	void account::set_last_acc_num (ll last_acc_num)
	{
		next_acc_num = last_acc_num;
	}
	ll account::get_last_acc_num ()
	{
		return next_acc_num;
	}
//start of the main function
int main ()
{
	//an option button for choosing the category
	int option_0;
	//bank object for services calling
	bank b;
	std::string bank_password;
	//account object and its properties to store users inputs
	account acc;
	ll acc_num;
	std::string	acc_name;
	ll acc_balance;
	std::string	account_pass;

	//a do while function to cntroll the program working span
	do
	{
		//intial menu
		std::cout << "										Welcome to MG Banking System\n\n";
		std::cout << "						For Clients Services Enter (1).\n";
		std::cout << "						For Managers Services Ebter (2).\n";
		std::cout << "						For Exit The System Enter (3).\n";
		//option picker
		std::cout << "Enter Your Choice : ";
		std::cin >> option_0;
		//exception handling for choosing nonexisting number
		try
		{
			if (option_0 != 1 || option_0 != 2 || option_0 != 3)
				throw opt_error();
		}

		catch (opt_error r)
		{

		}
		//if-else loop for choices
		//for picking category (1) 
		if (option_0 == 1)
		{
			//clearing screen and starting the client program
			system ("CLS");
			std::cout << "										Welcome to Clients Service\n\n";
			//option button for clients
			int option_1;
			//clients menu
			std::cout << "For Creating an Account Enter (1).\n";
			std::cout << "For Viewing an Existing Account Enter (2).\n";
			std::cout << "For Making a Deposit into Your Account Enter (3).\n";
			std::cout << "For Withdrawing From Your Account Enter (4).\n";
			std::cout << "For Closing Your Account Enter (5).\n";
			std::cout << "For Going to The Previous Menu Enter (6).\n";
			//option picker
			std::cout << "Enter Your Choice : ";
			std::cin >> option_1;
			//exception handling for choosing nonexisting number
			try
			{
				if (option_1 != 1 || option_1 != 2 || option_1 != 3 || option_1 != 4 || option_1 != 5 || option_1 != 6)
					throw opt_error ();
			}
			catch (opt_error r)
			{

			}
			//switch case for client pick
			switch (option_1)
			{
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;				
			}
		}
		//Managers Menu
		else if (option_0 == 2)
		{
			//clearing screen and starting the managers program
			system ("CLS");
			std::cout << "										Welcome to Managers Service\n\n";
			//option button for managers
			int option_2;
			//managers menu
			std::cout << "For Viewing All Accounts Enter (1).\n";
			std::cout << "For Viewing The Bank's Total Budget Enter (2).\n";
			std::cout << "For Going to The Previous Menu Enter (3).\n";
			//option picker
			std::cout << "Enter Your Choice : ";
			std::cin >> option_2;

			try
			{
				if (option_2 != 1 || option_2 != 2 || option_2 != 3)
					throw opt_error();
			}

			catch (opt_error r)
			{

			}
			//switch case for manager pick
			switch (option_2)
			{
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;		
			}
		}	
	}
	while (option_0 != 3);
	//terminate program
	system ("CLS");
	std::cout << "\n\n\n\n\n\n 													Press any Button to Close...\n";
	{int x;std::cin>>x;}
}
//end of the main function
//implementation of account methods
	account::account ()
	{}
	account::account (ll acc_num, std::string acc_name, ll acc_balance, std::string account_pass)
	{
		++next_acc_num;

		this -> acc_num = acc_num;
		this -> acc_name = acc_name;
		this -> acc_balance = acc_balance;
		this -> account_pass = account_pass;
	}
	ll account::get_acc_num ()
	{
		return acc_num;
	}
	std::string	account::get_acc_name ()
	{
		return acc_name;
	}
	long double account::get_acc_balance ()
	{
		return acc_balance;
	}
	std::string account::get_acc_pass ()
	{
		return account_pass;
	}
	void account::deposit (long double amount)
	{
		acc_balance += amount;
	}
	void account::withdraw (long double amount)
	{
		if (acc_balance - amount < MIN_BALANCE)
			throw balance_errror ();
		acc_balance -= amount;
	}
//end of the program