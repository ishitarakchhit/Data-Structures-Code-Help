#include<stdio.h>
/*
Print all the digits of a number
*/

#include<iostream>
#include<conio.h>
using namespace std;


//recursive function
void func(int num){
    //base case
    if(num==0)
        return;
    
    func(num/10);                       //recursive call

    //processing
    int digit = num % 10;
    cout<<endl<<digit;               //print the digit
}


int main(){
    int num;

    cout<<"\n\n"<<"Enter a number: ";
    cin>>num;
    cout<<endl;
    
    func(num);
    
} 