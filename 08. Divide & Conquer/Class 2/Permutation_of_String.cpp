#include<bits/stdc++.h>
using namespace std;


void permutation(string& str, int i){
    //base case
    if(i>= str.length()){
        cout<<str<<" ";
        return;
    }

    for (int j = i; j < str.length(); j++)
    {
        //swap two characters
        swap(str[i], str[j]);

        //recursive call
        permutation(str, i+1);

        //backtracking- to return to the original string
        swap(str[i], str[j]);
    }
    
    
}
int main(){
    string str= "abcd";

    permutation(str, 0);
}