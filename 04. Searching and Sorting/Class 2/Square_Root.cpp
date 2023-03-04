
/*
([https://www.codingninjas.com/codestudio/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2])
Find the square root of a given number
*/

#include <bits/stdc++.h> 
using namespace std;

int bsearch(long long int N){
    int s=0, e= N;
    long long int mid=e+(s-e)/2;
    long long int ans=-1;
    
    while(s<=e){
        long long int square = mid*mid;
        if(square==N)
            return mid;
        else if(square<N){
            ans = mid;
            s=mid+1;
        }
        else
            e=mid-1;
         
        mid=e+(s-e)/2;
    }    
    return ans;
}
int sqrtN(long long int N)
{
    // Write your code here.
    return bsearch(N);
}