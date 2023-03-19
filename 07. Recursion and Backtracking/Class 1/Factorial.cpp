#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;


int factorial(int i){                          //recursive function for factorial
   if(i==0){                                   //base condition
        return 1;
    }
    else{
        return i*factorial(i-1);              //recursive relation
    }
}

//main function
int main(){ 

    int i;

    cin>>i;

    cout<<factorial(i);
}