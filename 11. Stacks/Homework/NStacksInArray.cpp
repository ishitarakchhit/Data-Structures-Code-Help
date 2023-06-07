#include<iostream>
using namespace std;

class NStack{
    int *arr, *next, *top;           // top reprents the index of top elements in every stacsk and next represents the next free spot after every index or 2nd top element for stack
    int n;                         //no. of stacks
    int size; 
    int freespot;                  //index of next free spot in the array

    public:
    NStack (int _n, int _s): n(_n), size(_s) {
        freespot = 0;
        arr = new int(size);
        top = new int(n);
        next = new int(size);
        for (int i = 0; i < size; i++)
        {
            top[i] = -1 ;
        }
        for (int i = 0; i < size-1; i++)
        {
            next[i] = i+1;
        }
        next[size-1] = -1;
        
    }

    //pushing data into mth stack in array a
    bool push(int data, int m){
        if(freespot == -1){
            return false;
        }

        //storing the index of current freespot from 'freespot' to 'index'
        int index = freespot;

        //now storing the next freespot fromt next[index] to 'freespot'
        freespot = next[index];

        //now storing data into the array
        arr[index] = data;

        //now store the previous top element of particular stack into next[index];
        next[index] = top[m-1];

        //now update top[m-1] with the index of current top element in particular stack
        top[m-1] = index;

        cout<<endl;
        return true;
    }

    //to push element from mth stack
    int pop(int m){
        if( top[m-1] == -1){
            cout<<endl<<"Stack Underflow";
            return -1;
        }

        int index = top[m-1];
        top[m-1] = next[index];
        int popped = arr[index];
        next[index] = freespot;
        freespot = index;

        cout<<endl;
        return popped;
    }

    ~NStack(){
        delete []arr;
        delete []next;
        delete []top;
    }
};

int main(){
    NStack s(3, 6);
    cout<<s.push(10, 1);
    cout<<s.pop(1);
    cout<<s.push(11, 1);
    cout<<s.push(12, 2);
    cout<<s.push(13, 3);
    cout<<s.push(14, 2);
    cout<<s.pop(2);
    cout<<s.pop(3);
}