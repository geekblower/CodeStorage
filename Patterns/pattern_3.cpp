#include <iostream>
using namespace std;

int main() {
    int units;
    float amount = 50;
    char name[50];

    cout << "Enter the name of the user: ";
    cin >> name;

    cout << "Enter the number of units consumed : ";
    cin >> units;

    if(units > 300) {
    
        amount = units * 0.9;

        if(amount > 300) {
            amount += amount * 0.15;
        }
    
    } else if(units > 100 && units <= 300) {
    
        amount = amount + (units - 100) * 0.8;
    
    }


    cout << "The name of the user is : " << name << endl;
    cout << "The total no. of units consumed : " << units << endl;
    cout << "The total amount charged : Rs " << amount << endl;
    
    return 0;
}