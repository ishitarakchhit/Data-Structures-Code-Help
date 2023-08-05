#include<bits/stdc++.h>
using namespace std;

void rec(string& a, string& b, string& c, int i, int j, int ans, int carry){
    if(i<0 && j<0 && carry<=0)
        return;

    if(i>=0 && j>=0){
        ans = carry+ a[i]-'0' + b[j]-'0';
        carry = ans/10;
        c.push_back(ans%10+'0');
        i--;
        j--;
    }

    else if(i<0 && j>=0){
        ans = carry+ b[j]-'0';
        carry = ans/10;
        c.push_back(ans%10+'0');
        j--;

    }
    else if(i>=0 && j<0){
        ans = carry+ a[i]-'0';
        carry = ans/10;
        c.push_back(ans%10+'0');
        i--;
    }
    else if(i<0 && j<0 && carry>0){
        c.push_back(carry%10+'0');
        carry/=10;
    }
    rec(a,b,c,i,j,ans,carry);
}

int main(){
    string a= "1234";
    string b= "9284";
    string c="";
    //cout<<(a[3]-'0' + b[3]-'0' +0);

    rec(a,b,c,a.length()-1, b.length()-1, 0, 0);
    
    
    reverse(c.begin(), c.end());
    cout<<c;
}