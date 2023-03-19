#include<bits/stdc++.h>
using namespace std;

//to find the length of string
int findLength(char str[]){
    int count=0;
    for(int i=0; str[i]!='\0'; i++){
        count++;
    }
    
    return count;
}


int main(){
    //to declare a char array
    char str[100];

    //to initialize a single character in the given string
    str[0] = 'a';
  
    //to take input; or you can use for loop to take input just like in int arrays
    cin>>str;      

    //to print the char array; \0 marks the end of string
    cout<<str<<endl;

    /*
    //exercise
    char name[20];

    //enter the full name
    cout<<endl<<"Enter the full name";
    cin>>name; 

    //prints only the first name because "cin" stopes reading when it encounters " ", "\t", "\n"
    cout<<name<<endl;
     
    char getname[19];
    //to read the full name 
    cout<<endl<<"Enter again";
    cin.getline(getname, 19);
    cout<<getname;
    */


    cout<<"Length of the string is: "<<findLength(str);

}