#include<bits/stdc++.h>
using namespace std;

int bsearch(int divisor, int dividend){
    int s = abs(divisor);                                        //our search space is divisor to dividend
    int e = abs(dividend);
    int mid = s + (e-s)/2;
    int ans= -1;
    if(divisor ==0 && dividend ==0 || divisor ==0){

        cout<<"indefinite";
        return 0;
    }


    while(s <= e){
        if(divisor*mid == dividend){
            return mid;
        }
        else if( divisor*mid <dividend){
            ans= mid;
            s= mid +1;
        }
        else {
            e = mid-1;
        }
        mid = s+ (e-s)/2;
    }

    if(dividend >0 && divisor>0 || dividend<0 && divisor<0){
        return ans;
    }
    else{
        return ans*(-1);
    }
}

double precision(int divisor, int dividend,int q, int decimal){
    double st =0.1;
    double ans;
    for (int i = 0; i < decimal; i++)

    {
        for (double j = q; j*divisor<dividend; j= j+st)
        {   
            ans = j;
        }
            st/=10;
    }
    return ans;
}


int main(){
    int a, b;
    cout<<"Enter the divisor and dividend: ";
    cin>>a>>b;
    int integer = bsearch(a,b);
    cout<<precision(a, b, integer, 3);
}