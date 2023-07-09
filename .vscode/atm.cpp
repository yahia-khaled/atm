#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int static number_of_accounts = 0;
class ATM //creat class to start the project
{
private:
	char Account_Name[101];// the name of any account
	char Card_Number[11];//card number of the account + place for null
	double Amount;  // the money in the account
public:
	ATM()//constructor to get intial value
	{
		char intial_card_number[11] = { "0000000000" };
		strcpy_s(Account_Name, "No Name");
		strcpy_s(Card_Number, intial_card_number);
		Amount = 0;
	}
	//creat functions
	void Creat_new_Account(char Name[], char card[]);                           // to creat a new account
	int Deposit(char card_number_of_the_account[], double integer_deposit);                             // to put money in the account
	int Withdrawal(char card_number[], double money_Withdrawal);                                         // to get money from the account
	int Transfer(char Card_number_found[], int action, double money);         //transfer money from account to another
	void Print_acc_data();                                                      //to print name- card number-money in the account
	int check_card_number(char card_number_of_account[]);
	double get_amount();                    //to check if the char array (test card number)was found or not
};
//complet functions out :
void ATM::Creat_new_Account(char Name[], char card[])                           // we copy the name to account name - and the card number too
{/*this function take the name and the card number from function in main*/
	strcpy_s(Account_Name, Name);
	strcpy_s(Card_Number, card);
	Print_acc_data();                                                            // to print the account information
}
int ATM::Withdrawal(char card_number_of_the_account[], double money_Withdrawal)
{/*this function let u to get money feom your account but if your amount is empty u cant ,or u enter more money than u have */

	if (Amount == 0)
	{
		cout << "Error, You dont have credit in the account\n"; return 3;
	}
	if (Amount < money_Withdrawal * 1.03)
	{
		cout << "No credit in your account\n";  return 2;
	}
	if (money_Withdrawal == 0)return 2;
	Amount -= money_Withdrawal * 1.03;
	Print_acc_data();
	return 1;
}
int ATM::Deposit(char card_number_of_the_account[], double integer_deposit)
{/*this function let u to put money in your account , we here using strcmp to know if this is your account or not , if yes u will continue and do your operation if not u will return to check other accounts*/
	int cmp;//(compare)

	cmp = strcmp(card_number_of_the_account, Card_Number);
	if (cmp == 0) // it is the account which is searched for
	{
		Amount += integer_deposit * 1.01;
		Print_acc_data();
		return 1;
	}
	else return 0;
}
void ATM::Print_acc_data() //print data
{/*this funcyion print your data only*/
	cout << "Name: " << Account_Name << endl;
	cout << "Card Number : ";
	cout << Card_Number << endl;
	cout << "Amount : " << Amount;
	cout << endl << endl;
}
int ATM::check_card_number(char card_number_of_account[]) //check if it this card number is here or used
/* this function check if this card number is exist or not and return 1 if it here and -1 if not */
{
	int cmp;
	cmp = strcmp(card_number_of_account, Card_Number);
	if (cmp == 0)
		return 1;
	else
		return -1;
}
int ATM::Transfer(char Card_number_found[], int action, double money) //to transfer money
/*transfer function , it let u to transfer money from account to another but if your sender account have money firstly and your receiver acount isnt the sender account (it doing in the main function)
but here we receive action if action equal 0 this mean operation of sending, if action equal 1 this mean operation of receiving*/
{//action=0 (sending) , action=1 (reciving)
	if (action == 0)//data transfer sending
	{
		if (Amount == 0) { cout << "Error , no credit in a sender account\n"; money = 0; return 3; }
		if (Amount < money * 1.015)
		{
			cout << "Error,you don't have this money in your account .\n"; return 0;
		}
		Amount -= money * 1.015;
		return 1;
	}
	else //data transfer reciving
	{

		Amount += (money) * 0.985;
		return 1;
	}
}
double ATM::get_amount()
/*get amount function let as to see the account money and returned it to the main  to check some condition*/
{
	return Amount;

}
int check_card_number_valid(char card_number_to_check[])// to check that this card number is only numbers
/*check card number valid function , to check if this card number is numbers between 0 and 9  and not the same number*/
{
	char check = card_number_to_check[0];
	int value_of_character;
	for (int i = 0; i < 10; i++)
	{
		value_of_character = card_number_to_check[i];
		int x = card_number_to_check[9];
		if (!((x >= 48) && (x <= 57)))  //char '0'--->equal 48 in interger, also '9' equal 57
		{
			cout << "  not valid , enter 10 numbers only \n"; return 0;

		}
		else if (!((value_of_character >= 48) && ((value_of_character <= 57))) || ((value_of_character == 0)))
		{
			cout << "Not valid card number \n";
			return 0;
		}
		else if (value_of_character == 0)
		{
			cout << "Not valid card number \n"; return 0;
		}
		else if (card_number_to_check[1] == check && card_number_to_check[2] == check && card_number_to_check[3] && card_number_to_check[4] == check && card_number_to_check[5] == check && card_number_to_check[6] == check && card_number_to_check[7] == check && card_number_to_check[8] == check && card_number_to_check[9] == check)
		{
			cout << "Not valid card number \n";
			return 0;
		}
	}
	return 1;
}

int check_name_valid(char name_to_check[]) // check valid name for the account
/*this function check if this name is valid or not (start with character and dont be all space )and character from A to Z capital and small*/
{
	int value_of_character;
	for (int i = 0; i < 100; i++)  //'A'=65,'Z'=90 and 'a'=97,'z'=122
	{
		value_of_character = name_to_check[i];
		if (value_of_character == 0)
			break;
		if (!(((value_of_character >= 65) && (value_of_character <= 90)) || ((value_of_character >= 97) && (value_of_character <= 122)) || (value_of_character == 32) || (value_of_character == 0) || (value_of_character == -52)))
		{
			cout << "Not valid Name \n"; return 0;
		}
	}
	return 1;

}
int get_int_value(char any_selection[], int range = 2)
/*we used this function to change character array to integer by using some operation , and we send range =1 only in selection operation in main function
and checked if money must be > 0*/
{
	int  Number_of_digits = strlen(any_selection);
	int power = Number_of_digits - 1;
	int value = 1;
	int value_of_character[50];
	int value_retrun = 0;
	for (int start = 0; value != 0; start++, power--)
	{
		value = any_selection[start];
		if (value == 0)return value_retrun;
		if (Number_of_digits == 1 && value != 48 && value <= 53 && range == 1) return value - 48;
		else if (Number_of_digits == 1 && (value == 48 || value > 53) && range == 1)
		{
			return 0;
		}
		else if (!((value >= 48) && (value <= 57)))
		{
			cout << "not valid input\n";
			return 0;
		}

		value_of_character[start] = value - 48;
		value_retrun += (value_of_character[start] * pow(10, power));
	}
	return value_retrun;

}

bool space_invalid(char name[])
/*to check valid space in name of the account*/
{
	int i = 0;
	if (int(name[i]) == 32) { cout << "invalid name\n"; return true; } // to check if a name start with spaces
	while (name[i]) {

		if (int(name[i]) == 32 && int(name[i + 1]) == 32) { cout << "invalid name\n"; return true; } // to check if there is two or more spaces in a name
		i++;
	}
	return false;
}
int main()
{

	int valid;
	ATM Account[100];
	char card_Num_of_the_sending[100];
	char Card_Num_of_the_receiving[100];
	double money;

	for (int i = 0; true; i++)
	{
		int integer_select = 0;
		//cout << "1----Create new account \n" << "2----Deposit\n" << "3----transfer to another account\n" << "4----withdrawal\n" << "5----exit\n";
		//cout << "Please enter the number of operation:   ";
		char select[10];
		do {
			cout << "1----Create new account \n" << "2----Deposit\n" << "3----transfer to another account\n" << "4----withdrawal\n" << "5----exit\n";
			cout << "\nPlease enter the number of operation:  ";
			cin.clear();
			cin.getline(select, 10);
			if (strlen(select) == 1)     
			{
				integer_select = get_int_value(select, 1);
			}
			else
			{
				cout << "Error Select Again\n"; continue;
			}
			if (integer_select < 1 || integer_select>5)
			{
				cout << "Error Select Again\n";

			}
		} while (integer_select < 1 || integer_select>5);

		if (integer_select == 1)
		{
			int value_of_character; int valid_guess = 0;
			char Account_Name[200]; char Card_Number[100];
			int used = 0;
			do {
				cout << "please enter the account name:   ";
				cin.clear();
				cin.getline(Account_Name, 200);
				if (strlen(Account_Name) > 100)
				{
					cout << "Not valid Name (Bigger than 100 character)\n"; valid = 0;
				}
				else
					valid = check_name_valid(Account_Name);
				if (strlen(Account_Name) == 0)cout << "invalid name\n";
			} while (!valid || space_invalid(Account_Name) || strlen(Account_Name) == 0);
			for (int selection = 0; true; selection++)// enter here
			{

				do {
					cout << "Please enter the Card_Number (10 numbers ):   ";
					cin.clear();
					// enter card number
					cin.getline(Card_Number, 100);
					if (strlen(Card_Number) > 10 || strlen(Card_Number) < 10)
					{
						cout << "Card number is not valid (not equal 10 numbers) \n" << "you have to try to enter 10 numbers.\n";
						valid = 0;
					}
					if (strlen(Card_Number) == 10)
					{
						valid = check_card_number_valid(Card_Number);  

					}
				} while (!valid);
				for (int sec_itration = 0; sec_itration < number_of_accounts; sec_itration++)
				{
					used = Account[sec_itration].check_card_number(Card_Number);
					if (used == 1)
					{
						cout << "this card number is used \n";
						break;
					}
				}
				if (used == -1 || used == 0) break;
			}
			Account[number_of_accounts].Creat_new_Account(Account_Name, Card_Number);
			number_of_accounts++;


		}
		else if (integer_select == 2)
		{
			int value_of_character; double integer_deposit = 0; char Deposit_money[100];
			if (number_of_accounts < 1)
			{
				cout << "Error , there isnt any account yet\n"; continue;
			}

			char Deposit_Card_number[100]; int found; int found_Deposit = 0;
			for (int itration = 0; !found_Deposit; itration++)

			{
				do {
					cout << "Please enter the Card_Number (10 numbers ):   ";
					cin.clear();
					cin.getline(Deposit_Card_number, 100);
					if (strlen(Deposit_Card_number) == 10)
						valid = check_card_number_valid(Deposit_Card_number);
					else {
						cout << "Card number is not valid (not equal 10 numbers) \n" << "you have to try to enter 10 numbers for Card_Number .\n"; valid = 0;
					}
				} while (!valid);
				for (int search = 0; search <= number_of_accounts; search++)
				{
					found_Deposit = Account[search].check_card_number(Deposit_Card_number);

					if (found_Deposit == 1)
					{
						do {
							cout << "Please enter the amount to be deposited:  ";
							cin.getline(Deposit_money, 100);

							if (strlen(Deposit_money) >= 1)
								integer_deposit = get_int_value(Deposit_money);
							if ((strlen(Deposit_money) <= 1) || integer_deposit <= 0) { cout << "Error Not valid \n"; continue; }

						} while (integer_deposit == 0);
						Account[search].Deposit(Deposit_Card_number, integer_deposit);
						break;
					}
				}
				if (found_Deposit == -1)
				{
					found_Deposit = 0;
					cout << "Card Number not exist\n";
				}

			}
		}
		else if (integer_select == 3)

		{
			if (number_of_accounts < 2)
			{
				cout << "Error , You don't have enough accounts to transfer \n "; continue;
			}// to check number of account condition

			char money_transfer[100]; double integer_money_transfer = 0; int if_all_accounts_are_empty = 1;
			int valid_sending_code = 0; int valid_receiving_code = 0;

			for (int i = 0; i < number_of_accounts; i++)
			{
				if (Account[i].get_amount() != 0) { if_all_accounts_are_empty = 0; break; }
			}
			if (if_all_accounts_are_empty) { cout << "there is no credit in any account to perform transfer operation\n"; continue; }
			int valid_transfer = 0; int sender_postion = -1, recivier_postion = -1; int corner_case;

			for (int itration = 0; !valid_transfer; itration++)
			{

				for (int sending_procces = 0; !valid_sending_code; sending_procces++)
				{
					sender_postion = -1; int No_money_in_sender = -1;
					cout << "please enter the number of the sending account(10 numbers) :   ";
					cin.clear();
					cin.getline(card_Num_of_the_sending, 100);//cin sending
					if (strlen(card_Num_of_the_sending) == 10)
					{

						valid = check_card_number_valid(card_Num_of_the_sending);

						if (valid == 1)
						{
							for (int find_postion = 0; find_postion <= number_of_accounts; find_postion++)
							{
								sender_postion = Account[find_postion].check_card_number(card_Num_of_the_sending);//(-1, 1)

								if (sender_postion == 1) // if postion[x]>0 then it's the right postion
													// if postion[x]<0 then not the correct postion
								{
									sender_postion = find_postion;
									if(Account[sender_postion].get_amount()==0)
									{
										cout << "Error ,No credit in this account\n";
										No_money_in_sender = 1;
										break;
									}
									else
										No_money_in_sender = 0;
									break;
								}
							}


							if (sender_postion < 0)
							{
								cout << "Not found this card number\n"; valid = 0;
							}
						}

					}
					else
					{
						cout << "Card number is not valid (not equal 10 numbers) \n" << "you have to enter 10 numbers For the card Number of the sending .\n";;
					}
					if (No_money_in_sender == 1)continue;
					if (sender_postion >= 0)break;
				}

				for (int receiving_procces = 0; !valid_receiving_code; receiving_procces++)
				{
					recivier_postion = -1;
					cout << "please enter the number of the receiving account(10 numbers) :   ";
					cin.clear();
					cin.getline(Card_Num_of_the_receiving, 100);//cin sending
					if (strlen(Card_Num_of_the_receiving) == 10)
					{
						valid = check_card_number_valid(Card_Num_of_the_receiving);

						if (valid == 1)
						{
							for (int find_postion = 0; find_postion <= number_of_accounts; find_postion++)
							{
								recivier_postion = Account[find_postion].check_card_number(Card_Num_of_the_receiving);//(-1, 1)

								if (recivier_postion == 1) // if postion[x]>0 then it's the right postion
													// if postion[x]<0 then not the correct postion
								{
									recivier_postion = find_postion;
									if(recivier_postion == sender_postion)
									{
										valid_receiving_code = 0;
										cout << "Error ,they are the same account\n";
										break;
									}
									valid_receiving_code = 1;
									break;
								}
							}
							if (recivier_postion < 0)
							{
								cout << "Not found this card number\n"; valid = 0;
							}
						}
					}

					else { cout << "Card number is not valid (not equal 10 numbers) \n" << "you have to enter 10 numbers For the card Number of the receivin .\n"; }

					if (recivier_postion >= 0&& valid_receiving_code == 1)break;


				}

				if (recivier_postion == sender_postion)
				{
					cout << "Error ,they are the same account\n";
					continue;
				}
				else
				{
					int x = 0; double money = 0; int found_both = 0;

					//to find postion of receiving and sending
						// searching =0 (for get the postion of sending)
						// searching =1 (for get the postion of receiving
					//But wait to check that we dont enter the same card num:


					for (int start_sending_money = 0; true; start_sending_money)
					{
						do {
							cout << "please enter the amount to be transferred : ";
							cin.getline(money_transfer, 100);
							if (strlen(money_transfer) >= 1)
								integer_money_transfer = get_int_value(money_transfer, 10);

							if (strlen(money_transfer) < 1 || integer_money_transfer == 0)
							{
								cout << "Not valid\n"; continue;
							}
							corner_case = Account[sender_postion].Transfer(card_Num_of_the_sending, 0, integer_money_transfer);
							if (corner_case == 1) { valid_transfer = 1; break; }
							if (corner_case == 0)// if enter more money than amount
								continue;
							if (corner_case == 3) // if amount equal 0
								break;
						} while (integer_money_transfer == 0);
						if (corner_case == 3)
						{
							valid_transfer = 0; break;
						}
						if (corner_case == 1) { valid_transfer = 1; break; }
					}
					if (corner_case == 1)
					{
						//Account[sender_postion].Transfer(card_Num_of_the_sending, 0, money_transfer);// to edit sending data and enter the money that was needed
						if (Account[recivier_postion].Transfer(Card_Num_of_the_receiving, 1, integer_money_transfer))// to edit the receiving data and get the money
					   // to show the final result in the data that we have
							cout << "Sending information :\n";
						Account[sender_postion].Print_acc_data(); // data of sending
						cout << "receiving information :\n";
						Account[recivier_postion].Print_acc_data(); //data of receiving
					}
				}

			}
		}

		else if (integer_select == 4)//Withdrwal operation
		{
			if (number_of_accounts == 0) { cout << "Error , You dont have any account now \n"; continue; }
			int if_all_accounts_are_empty = 1;
			for (int i = 0; i < number_of_accounts; i++)
			{
				if (Account[i].get_amount() != 0) { if_all_accounts_are_empty = 0; break; }
			}

			if (if_all_accounts_are_empty) { cout << "there is no credit in any account to perform withdrawal operation\n"; continue; }

			int found_Withdrawal = 1; char withdrawn_money[100]; double money_Withdrawal = 0;
			char Withdrawal_Card_number[100]; int value_of_character; 
			for (int itration = 0; found_Withdrawal; itration++)
			{
				do {//check valid the card number here
					cout << "Please enter the Card_Number (10 numbers ):   ";
					cin.clear();
					cin.getline(Withdrawal_Card_number, 100);
					if (strlen(Withdrawal_Card_number) == 10)
					{
						valid = check_card_number_valid(Withdrawal_Card_number);
						break;
					}
					else cout << "Card number is not valid (not equal 10 numbers) \n" << "you have to enter 10 numbers For the card Number .\n";
				} while (true);
				// here we now that this card number is valid but will will check if it exist
				int find_it;
				for (int get_postion_of_Withdrawal = 0; get_postion_of_Withdrawal <= number_of_accounts; get_postion_of_Withdrawal++)//for loop for get the postion of withdrwal account
				{

					find_it = Account[get_postion_of_Withdrawal].check_card_number(Withdrawal_Card_number);
					if (find_it == 1)
					{
						find_it = get_postion_of_Withdrawal;

						break;
					}
				}

				if (find_it == -1)
				{
					cout << "Card Number not exist\n"; continue;
				}
				//if continue here u have the correct card number
				money_Withdrawal = 0;
				if ((Account[find_it].Withdrawal(Withdrawal_Card_number, money_Withdrawal) == 3))continue;
				//here we have account which having money to do operation

				int valid_money = 1;
				int result_of_operation;
				do {
					cout << "Please enter the amount to be withdrawn:  ";
					cin.getline(withdrawn_money, 100);

					if (strlen(withdrawn_money) >= 1)
					{
						money_Withdrawal = get_int_value(withdrawn_money);
					}

					if ((strlen(withdrawn_money) < 1) || money_Withdrawal <= 0)
					{
						valid_money = 0;
						continue;
					}
					result_of_operation = Account[find_it].Withdrawal(Withdrawal_Card_number, money_Withdrawal);

					if (result_of_operation == 2)//mean this money > amount
						valid_money = 0;
					if (result_of_operation == 1)valid_money = 1;
				} while (valid_money == 0);
				if (result_of_operation == 1)//here is the right operation was done
					break;
			}
		}
		else  break;
	}

}

// name - card number - creat - Deposit- Withdrawal
