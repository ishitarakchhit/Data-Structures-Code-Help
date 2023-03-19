#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

//recursive function
int pow_rec(int n){
    if(n==0)                             //base condition
        return 1;

    else{
        return 2 * pow_rec(n-1);         //recursive relation
    }
}

int main(){
    int n;

    cout<<"Enter the exponent value: ";
    cin>>n;

    cout<<endl<<"2^"<<n<<" is: "<<pow_rec(n);                      //function call
} 