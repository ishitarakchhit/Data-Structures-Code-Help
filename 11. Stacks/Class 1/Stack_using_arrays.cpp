#include<iostream>
using namespace std;

class stack{
    public:
    int *arr;
    int top;
    int size;

    stack(int size){
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    //behavior
    //function to push element into the stack
    void push(int data){
        if(size-top > 1){
            top++;
            arr[top] = data;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }

    //function to remove the latest element from the stack
    void pop(){
        if(top <0){
            cout<<"Stack underflow"<<endl;
        }
        else{
            top--;
        }
    }

    //function to peep to the top element in the stack
    int getTop(){
        if(top == -1){
            cout<<"Stack underflow"<<endl;
            return 0;
        }
        else{
            return arr[top];
        }
    }

    //function to get the no. of elements present in the stack
    int getSize(){
        return top+1;
    }

    //function to check whether the stack is empty or not
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else 
            return false;
    }

};

//main function
int main(){

    stack s(10);

    //to push elements in stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    //to print all elements 
    while(!s.isEmpty()){
        cout<<s.getTop()<<" ";
        s.pop();
    }

    //to check size of stack
    cout<<endl<<s.getSize();
    
    return 0;
}