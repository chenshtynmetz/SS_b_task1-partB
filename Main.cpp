#include <iostream>
#include <string>
#include "mat.hpp"

using namespace std;

int main(){
    int col = 0;
    int row = 0;
    char a; //maybe add a intialize
    char b;
    string carpet = "";
    string ans = "";
    cout << "Welcome to our carpets store!\nPlease enter the size of the carpet that you want- the number of columns and rows" << endl;
    cin >> col;
    cin >> row; 
    cout << "Please enter 2 symbols to the pattern of the carpet:" << endl;
    cin >> a;
    cin >> b;
    carpet = ariel::mat(col, row, a, b);
    cout << "This is your carpet:" << endl << carpet << endl;
    while (1)
    {
        cout << "Do you want another carpet? write yes/no" << endl;
        cin >> ans;
        if(ans == "no"){
            break;
        }
        cout << "Please enter the size of the carpet that you want- the number of columns and rows" << endl;
        cin >> col;
        cin >> row; 
        cout << "Please enter 2 symbols to the pattern of the carpet:" << endl;
        cin >> a;
        cin >> b;
        carpet = ariel::mat(col, row, a, b);
        cout << "This is your carpet:" << endl << carpet << endl;
    }
    cout << "Thank you of visit in our store!\nhave a good day!" << endl;
    return 0;
}