#include<iostream>
using namespace std;

class queue{
    public:
    int front ;
    int rear ;
    int size;
    int *arr;
    queue(int size){
        arr = new int[size];
        this->size = size;
        front =0;
        rear = 0;
    }

    void push(int data){
        if(rear == size){
            cout<<endl<<"Queue Overflow";
        }
        else {
            arr[rear] = data;
            rear ++;
        }
    }
    void pop(){
        if(front == rear){
            cout<<endl<<"Queue Underflow";
            return;
        }
        else{
            front ++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
        }
    }
    int getFront(){
        if(front == rear){
            cout<<endl<<"Queue is empty";
            return -1;
        }
        else{
            return arr[front];
        }
    }
    bool isEmpty(){
        if(rear == front){
            return 1;
        }
        else 
            return 0;
    }
    int getSize(){
        return rear-front;
    }
};

int main(){
    queue q(10);

    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.getFront();
    cout<<q.getSize();
    q.pop();

    q.pop();
    cout<<q.isEmpty();
    q.pop();
    q.pop();
    q.pop();
    q.push(30);
    q.push(30);
    q.push(30);
    q.push(30);
    q.push(30);
    q.push(30);
    q.push(30);
    q.push(30);
    q.push(30);
    q.push(30);
    q.push(30);


    return 0;
}