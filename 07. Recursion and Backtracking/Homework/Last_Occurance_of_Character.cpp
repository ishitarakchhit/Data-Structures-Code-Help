#include<bits/stdc++.h>
using namespace std;


//recursive method
int rec(string str, char x, int i, int ans){
    
    if(i>= str.length()){
        return ans;
    }
    if(str[i]== x)
        ans = i;
    
    return rec(str, x, i+1, ans);
}

int main(){
    string str;
    char x;
    cout<<"Enter the string: ";
    cin>>str;
    cout<<endl<<"Enter the character: ";
    cin>>x;

    cout<<endl<<rec(str, x, 0, -1);
}