
#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

int findunique(vector<int> arr){
    int element=0;

	for (int i = 0; i < arr.size(); i++)
	{
		element = arr[i]^element;
	}
	return element;
}


int main(){
	vector<int> arr{1,1,2,3,3,4,4,5,2,6,6};

	cout<<findunique(arr);
}
