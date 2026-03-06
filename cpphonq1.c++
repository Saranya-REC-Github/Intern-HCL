//Program to accept a password and check if its length is greater than 8.
#include<iostream>
#include<string>
using namespace std;
int main(){
    string password;
    cout<<"Enter the password:";
    cin>>password;
    if(password.length()>8){
        cout<<"PASSWORD IS VALID";
    }
    else{
        cout<<"PASSWORD IS TOO SHORT";
    }
    return 0;
}
