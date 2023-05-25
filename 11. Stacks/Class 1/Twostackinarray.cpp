#include<iostream>
using namespace std;

class stack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    //constructor
    stack(int size){
        arr = new int[size];
        this->top1 = -1;
        this->top2 = size;
        this->size = size;
    }

    void push1(int data){
        if(top1+1 == top2){
            cout<<"Stack overflow"<<endl;
        }
        else{
            top1++;
            arr[top1] = data;
        }
    }

    void pop1(){
        if(top1 == -1){
            cout<<"Stack underflow"<<endl;
        }
        else{
            top1--;
        }
    }

    void push2(int data){
        if(top2-top1 == 1){
            cout<<"Stack overflow"<<endl;
        }

        else{
            top2--;
            arr[top2] = data;
        }
    }

    void pop2(){
        if(top2 == size){
            cout<<"Stack underflow"<<endl;
        }
        else{
            top2++;
        }
    }
};


//main function
int main(){
    stack s(5);

    s.push1(10);
    s.push1(20);
    s.push1(30);

    s.push2(100);
    s.push2(90);
    s.push1(40);

    return 0;
}