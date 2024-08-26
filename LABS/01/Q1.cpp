#include<iostream>
using namespace std;

class Account{
    private:
        int *balance;
    public:

        Account(){
            balance = new int(0);
        }
        Account(int bal){
            balance = new int(bal);
        }
        Account(const Account &other){
            balance = new int(*other.balance);
        }

        Account &operator=(const Account& other){
            if(this != &other){
                delete balance;
                balance = new int(*other.balance);
            }
            return *this;
        }

        int get_balance(){
            return *balance;
        }
        void deduct_balance(int amount){
            *balance -= amount;
        }

        ~Account(){
            delete balance;
        }
};

int main(){
    Account acc1;
    Account acc2(1000);
    Account acc3(acc2);

    cout << "Account 1 Balance: " << acc1.get_balance() << endl;
    cout << "Account 2 Balance: " << acc2.get_balance() << endl;

    acc3.deduct_balance(200);
    cout << "Account 3 Balance: " << acc3.get_balance() << endl;
    cout << "Account 2 Balance: " << acc2.get_balance() << endl;
}
