
/*
To find the floating part of the integer we use brute force approach.
in which we increment the floating part of the number by 1 and check if the square of final number is less than the original number or not.
*/

#include <iostream>
using namespace std;

long long int squareroot(int n){
 int s=0;
 int e=n;
 long long int mid=s+(e-s)/2;
 long long int ans=-1;

 while(s<=e){
    long long int sq=mid*mid;
    if(sq== n){
        return mid;
    }
    else if(sq<n){
      ans=mid;
      s=mid+1;
    }
    else
      e=mid-1;
    mid=s+(e-s)/2;
 }

 return ans;
}



double precise(double n, int points, int temp){
    double num=temp;
    double factor=1;

    for(int i=0; i<points; i++){
        factor = factor/10;
        for(double j=num; j*j<n; j=j+factor){
            num=j;
        }
    }
    return num;

}



int main()
{
    int num=37;

    
    int integer = squareroot(num);
    cout<<"answer is: "<<precise(37, 3, integer);

    
   
}