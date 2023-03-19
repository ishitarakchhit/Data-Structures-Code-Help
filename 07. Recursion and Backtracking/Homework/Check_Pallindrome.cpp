#include<bits/stdc++.h>
using namespace std;

bool check(string& str, int i, int j){
    if(i>=j)
        return true;

    if(str[i]!= str[j])
        return false;

    return check(str, i+1, j-1);
}

int main(){
    string str = "mom";

    cout<<check(str, 0, str.length()-1);
}