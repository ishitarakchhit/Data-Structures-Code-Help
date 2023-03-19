#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<long long int> arr,long long int n, long long int k, long long int mid){
	long long int sum=0;
	for(long long int i=0; i<n; i++){
		if(arr[i]-mid < 0)
		 continue;
		else 
		 sum= (arr[i]- mid) + sum;
	}
	
	if( sum>= k)
	 return true;
	else
	 return false;
}

long long int eko(vector<long long int> arr, long long int n, int k){
	long long int s=0; 
	long long int e=*max_element(arr.begin(), arr.end());
	 
	
	long long int mid= s+ (e-s)/2;
	long long int ans=-1;
	
	while(s<=e){
		if(isPossible(arr, n, k, mid)){
			ans= mid;
			s=mid+1;
		}
		else
		 e= mid-1;
		mid= s+ (e-s)/2;
	}
	return ans;
}


int main() {
	
	// your code here
    
    long long int k, n;

    //enter the number of trees to be cut and amount of wood required
    cin>>n>>k;

    vector<long long int> arr;
    long long int size;
    
    //Enter the size of trees
    for(int i=0; i<n; i++){
    	cin>>size;
    	arr.push_back(size);
    }

    
    cout<<eko(arr, n, k);


	  return 0;
}