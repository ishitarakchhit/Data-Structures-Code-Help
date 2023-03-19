#include<bits/stdc++.h>
using namespace std;

void printsub(string str, string output, int i, vector<string> &v){
    if(i>= str.length()){
        v.push_back(output);
        return;
    }
    
    //to exclude
    printsub(str, output, i+1, v);                         //recursive call

    //to include
    output.push_back(str[i]);
    printsub(str, output, i+1, v);                          
}
int main(){
    string str="abc";
    string output="";
    vector<string> v;
    printsub(str, output, 0, v);
    for(string i: v){
        cout<<i<<endl;
    }
    
}