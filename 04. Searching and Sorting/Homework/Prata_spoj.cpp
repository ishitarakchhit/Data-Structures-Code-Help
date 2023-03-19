#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int mid, int k){
    
    int count=0;             //to keep the count of pratas cooked
    for (int i = 0; i < arr.size(); i++)
    {   int time=0;                               //to store the time taken to make pratas by each cook
        int rank= arr[i];                         //to store the rank of each cook
        int j =1;                                 //to store the time taken by the cook in each subsequent minute

        while (true)
        {
            if(time + rank*j <= mid){
                count++;
                time += rank*j;
                j++;
            }
            else{
                break;
            }
        }
        if( count>= k)
            return true;
        
    }
    return false;
}


int prata(vector<int> arr, int k){
    int s=0;
    int e=0;
    int maxi= *max_element(arr.begin(), arr.end());
    e= maxi * (arr.size()* (arr.size()+1)/2);

    int mid = s+ (e-s)/2;

    int ans=-1;

    while(s<=e){
        if(isPossible(arr, mid, k)){
            ans = mid;
            e= mid-1;
        }
        else{
            s= mid+1;
        }
        mid = s+ (e-s)/2;
    }
    return ans;

}
int main(){
    vector<int> arr;
    int T;
    cin>> T;
    while(T--){
        int n;
        int C;                        //number of pratas to be cooked
        cin>>n>>C;
        while(C--){
            int rank;
            cin>> rank;
            arr.push_back(rank);
        }
    cout<<endl<<prata(arr, n);
    }
    
    return 0;
}