//time complexity: O(n*m) where n and m are the size of rows and columns

#include<iostream>

using namespace std;

bool ispresent(int arr[3][4], int key){
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(key== arr[i][j]){
                return 1;
            }
        }
    }
    return 0;
}


int main(){
    int key;

    int arr[3][4]={{1,11,111,1111}, {2,22,222,2222}, {3,33,333,3333}};

    cout<<"Enter the element to be searched: ";
    cin>>key;

    if(ispresent(arr, key)){
        cout<<"present";
    }
    else
        cout<<"not present";

}