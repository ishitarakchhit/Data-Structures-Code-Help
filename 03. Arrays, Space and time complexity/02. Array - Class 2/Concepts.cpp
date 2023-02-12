#include<iostream>
#include<vector>
using namespace std;


void printarray(vector<int> a){
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    
}


int main(){
    //to create a dynamic array of size 10 and elements initialized with 0
    vector <int> arr(10);  

    //to create a dynamic array of size 10 and elements initialized with 1
    vector <int> brr(10,1);

    //to create a dynamic array of size 10 and elements are initialzed with different numbers
    vector <int> crr{1,2,3,4,4,5,6,7};

    printarray(arr);
    printarray(brr);
    printarray(crr);

    //to find the number of elements in an array
    cout<<endl<<arr.size();

    //to find the capacity of elements in an array
    cout<<endl<<arr.capacity();

    //to find whether an array is empty or not
    cout<<endl<<arr.empty();

    //to insert an element into an array
    arr.push_back(10);
    printarray(arr);

    //to remove the last element from the array
    crr.pop_back();
    printarray(crr);
    

    

}