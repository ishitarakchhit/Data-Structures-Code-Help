#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

//TAIL RECURSION 
//recursive function to print numbers till n
int printcount(int n){
    if(n==0)                             //base condition
        return 0;
     
        cout<<endl<<n;                  //processing code
        return printcount(n-1);         //recursive relation

    
    
}

int main(){
    int n;

    cout<<"Enter the number: ";
    cin>>n;

    printcount(n);                      //function call
} 





//*****OR*****


#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

//TAIL RECURSION 
//recursive function to print numbers till n
void printcount(int n){
    if(n==0)                             //base condition
        return ;
     
        cout<<endl<<n;                  //processing code
        printcount(n-1);         //recursive relation

    
    
}

int main(){
    int n;

    cout<<"Enter the number: ";
    cin>>n;

    printcount(n);                      //function call
} 