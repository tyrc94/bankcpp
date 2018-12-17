#include <iostream>
#include <string>
#include <map>

using namespace std;

struct AccountInfo
{
    string holder_name;
    float acc_balance;
};

map<int, AccountInfo> accounts; // @@TODO: Replace account number with UUID

void enter_continue();
void main_menu();
void create_account();
void view_account();
void close_account();


int main()
{   
    system("clear");
    char option;

    while (true)
    {
        system("clear");
        cout << "Welcome to the bank" << "\n";
        main_menu();
        cin >> option;

        switch(option)
        {
            case '1': create_account();
                        break;
            case '2': view_account();
                        break;
            case '3': close_account();
                        break;
            case '4': cout << "Bye.\n"; return 0;
            default: system("clear");
        }
    }
    
    return 0;
}

void main_menu()
{
    cout << "=== Main Menu ===" << "\n";
    cout << "--- Options ---\n";
    cout << "1. Create Account\n";
    cout << "2. View Account\n";
    cout << "3. Delete Account\n";
    cout << "4. Exit\n\n";
    cout << "Your option: ";
}

void create_account()
{   
    AccountInfo acc;
    string holder_name;
    string acc_num_input;
    int acc_number;

    system("clear");

    cout << "--- Create account ---\n";
    cout << "Account holder's name: ";
    cin >> holder_name;
    cout << "Account number: ";
    cin >> acc_num_input;
    for(const auto &c: acc_num_input)
    {
        if(isdigit(c)){
            continue;
        } else {
            cout << "Invalid input.\n";
            enter_continue();
            create_account();
        }
    }

    acc_number = stoi(acc_num_input);

    if (accounts.count(acc_number)!=0){
        cout << "Number already in use.\n";
        enter_continue();
        create_account();
    }

    acc.holder_name = holder_name;
    acc.acc_balance = 0;

    accounts[acc_number]=acc;
    cout << "\nAccount created successfully.\n\n";

    enter_continue();
}

void view_account()
{   
    system("clear");
    string acc_num_input;
    int acc_number;
    cout << "--- View account information ---\n";
    cout << "Input account number: ";
    cin >> acc_num_input;
    for(const auto &c: acc_num_input)
    {
        if(isdigit(c)){
            continue;
        } else {
            cout << "Account does not exist.\n";
            enter_continue();
            view_account();
        }
    }

    acc_number = stoi(acc_num_input);
    if (accounts.count(stoi(acc_num_input))==0){
        cout << "Account does not exist.\n";
        enter_continue();
        view_account();
    } else {
        cout << "\nAccount holder:   " << accounts[acc_number].holder_name << "\n";
        cout << "Account balance:  " << accounts[acc_number].acc_balance << "\n";
    }

    enter_continue();

}

void close_account()
{
    cout << "Close account\n";
    system("clear");
}

void enter_continue()
{
    cout << "\nPress Enter to Continue\n";
    string temp;
    temp = cin.get();
    getline(cin, temp);
}