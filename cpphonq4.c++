//Check if a given string is a palindrome without using built-in functions.
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1;
    cout<<"Enter the string: ";
    getline(cin,s1);
    int start=0;
    int end=s1.length()-1;
    bool isPalindrome=true;
    while(start<end){
        if(s1[start]!=s1[end]){
            bool isPalindrome=false;
            break;
        }

        start++;
        end--;
    }
    if(isPalindrome){
    printf("It is Palindrome");
    }
    else{
    printf("It is not Palindrome");
    }
    return 0;

}

