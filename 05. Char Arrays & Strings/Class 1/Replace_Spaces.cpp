#include<iostream>
using namespace std;

void replaceSpaces(char str[]){
    for (int  i = 0; str[i]!='\0'; i++)
    {
        if(str[i]==' ')
            str[i]= '@';
    }
    
}

int main(){
    char str[100]= "ishita rakchhit";
    replaceSpaces(str);
    cout<<str;
}