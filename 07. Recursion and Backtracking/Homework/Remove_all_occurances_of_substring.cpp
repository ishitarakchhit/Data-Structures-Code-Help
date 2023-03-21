#include<bits/stdc++.h>
using namespace std;

string rec(string& str, string part){
    int pos = str.find(part);                    //find the position of substring in the main string 
    if(pos==string::npos ){             
        return str;
    }
    
    str.erase(pos, part.length());

    return rec(str, part);
}

int main(){
    string str="aaaabbbbcd";
    string part="ab";
    str = rec(str, part);
    cout<<str;
}