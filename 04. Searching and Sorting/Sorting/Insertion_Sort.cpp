#include <bits/stdc++.h> 
using namespace std;
void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    int j;
    for(int i=1; i<n; i++){
        int temp = arr[i];
        for( j=i-1; j>=0; j--){
            if(temp< arr[j]){
                arr[j+1] = arr[j];
            }
            else 
                break;
        }
        arr[j+1]= temp;
    }
}

//using while loop
/*
#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    int i=1;
    int j;
    while(i<n){
        int temp = arr[i];
        j=i-1;
        while(j>=0){
            if(temp< arr[j]){
                arr[j+1] = arr[j];
            }
            else 
                break;
            j--;
        }
        arr[j+1]= temp;
        i++;
    }
}
*/