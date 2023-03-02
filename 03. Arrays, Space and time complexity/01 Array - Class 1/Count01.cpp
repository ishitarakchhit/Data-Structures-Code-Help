#include<iostream>
#include<vector>
using namespace std;

void count01(vector<int> arr){
    int count0=0, count1=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]==0)
            count0++;
        else
            count1++;
    }
    cout<<"No. of zeroes: "<<count0;
    cout<<endl<<"No. of 1's: "<<count1;
    
}
void funccount01(int arr[], int size){
    int count0=0, count1=0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==0)
            count0++;
        else
            count1++;
    }
    cout<<endl;
    cout<<"No. of zeroes: "<<count0;
    cout<<endl<<"No. of 1's: "<<count1;
    
}



int main(){
    vector<int> arr={0,0,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,0,0,0,0,1,0,1,1};                        //dynamic array
    
    int a[5]={ 1,1,1,1,0};                                                                      //static array

    count01(arr);
    funccount01(a, 5);
}