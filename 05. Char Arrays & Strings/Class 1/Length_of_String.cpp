//find the length of a string 

#include <iostream>
using namespace std;

// reverses a string 
void reverse(char name[], int length){
    for(int i=length -1; i>=0; i--)
     cout<<name[i];
}

//finds the length of a string
int getlength(char name[]){
    int count=0;
    for(int i=0; name[i]!='\0'; i++)
     count++;
    return count;
}

//main function
 int main(){
    char name[10];
    cout<<"Enter you name :";
    cin>>name;
    cout<<"Your name is :"<<name<<endl;
    cout<<"Its length is :"<<getlength(name)<<endl;
    cout<<"Your reverse name is :";
    reverse(name, getlength(name));
 }