#include<iostream>
using namespace std;

//recursive function to print array
void func(int arr[], int n, int &maxi){
    if(n<0)
        return;
    
    if(arr[n] > maxi)
        maxi=arr[n];
    func(arr, n-1, maxi);

}


int main(){
    int arr[] = {10,15,2,3,5,6,3,49};
    int maxi = -10;
    func(arr, 7, maxi);
    cout<<maxi;
}