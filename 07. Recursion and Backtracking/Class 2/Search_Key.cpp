#include<bits/stdc++.h>
using namespace std;

bool rec(string s, int i, int& n, char key){
    if(i>= n)
        return false;

    if(key == s[i])
        return true;
    
        
        return rec(s, i+1, n, key);
}

void checkkey(string s, int i, int n, char key, vector<int> & ans){
    if(i>=n){
        return;
    
    }
    if(key == s[i])
        ans.push_back(i);

    checkkey(s, i+1, n, key, ans);
}

int main(){
    string s="Ishita Rakchhit";
    char key= 'a';
    vector<int> ans;
    int n = s.length();

    cout<<rec(s, 0, n, key)<<endl;

    checkkey(s, 0, n, key, ans);
 
    for(auto val: ans){
        cout<<val<<" ";
    }
    
    

}