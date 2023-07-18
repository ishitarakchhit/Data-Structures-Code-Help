#include<iostream>
#include<queue>
using namespace std;


//function to print kth smallest element from an array using max heap with time O(N) and space O(K)
int Kthsmallest(int arr[], int n, int k){
    priority_queue<int> pq;
    int i =0;
    for(i =0; i<k; i++){
        pq.push(arr[i]);
    }

    for(i; i<n; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}


//function to print kth greatest element from an array
int Kthgreatest(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    int i =0;
    for(i =0; i<k; i++){
        pq.push(arr[i]);
    }

    for(i; i<n; i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main(){
    int arr[] = {3,11, 6, 9, 4, 12, 2, 8};
    int n = 8;
    int k;
    cout<<"Enter the value of K: ";
    cin>> k;

    cout<<"Kth smallest is: "<<Kthsmallest(arr, n, k)<<endl;
    cout<<"Kth greatest is: "<<Kthgreatest(arr, n, k);
}