#include<bits/stdc++.h>
using namespace std;

//using recursive method
void rec(string& str, int i, int j){
    if(i>j)
        return;
    
    else
        swap(str[i], str[j]);
    
    rec(str, i+1, j-1);
}

int main(){
    string str = "IshitaRakchhit";

    rec(str, 0, str.length()-1);              //function call to reverse the string str
    cout<<str;                              
}