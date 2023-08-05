#include<iostream>
#include<limits.h>
using namespace std;

int func(int n, int x, int y, int z){

    if(n<0)
        return INT_MIN;
    if(n==0)
        return 0;
    
    int maxi = INT_MIN;

    int ans = func(n-x, x,y,z);
    maxi = max(maxi, ans+1);

    ans = func(n-y, x,y,z);
    maxi = max(maxi, ans+1);

    ans = func(n-z, x,y,z);
    maxi = max(maxi, ans+1);
    
    return maxi;    
}

int main(){

    int N = 5;
    int x= 5; 
    int y= 2;
    int z = 2;

    cout<<func(N, x,y,z);
}