#include<iostream>
using namespace std;

class Cirqueue{
    public:
    int front ;
    int rear ;
    int size;
    int *arr;
    
    Cirqueue(int size){
        arr = new int[size];
        this->size = size;
        front =-1;
        rear = -1;
    }

    void push(int data){
        if((rear == size-1 && front==0) || (front == rear + 1 )){
            cout<<endl<<"Queue Overflow";
        }
        else if(front == rear && rear == -1){
            front = rear = 0;
            arr[front] = data;
        }
        else{
            if(rear < size-1){
                arr[++rear] = data;
            }
            else{
                rear = 0;
                arr[rear]= data;
            }
        }
    }
    void pop(){

        if(front == rear &&  rear == -1){
            cout<<endl<<"Queue Underflow";
            return;
        }
        else if(front == rear){
            front = rear = -1;
            
        }
        else if( front == size-1 ){
            front = 0;
        }
        else{
            front++;
        }
    }
    int getFront(){
        if(front == rear == -1){
            cout<<endl<<"Queue is empty";
            return -1;
        }
        else{
            return arr[front];
        }
    }
    bool isEmpty(){
        if((rear == front == -1)){
            return 1;
        }
        else 
            return 0;
    }
    int getSize(){
        if( front <= rear){
            return rear-front+1;
        }
        else{
            return size+1-front + rear + 1;
        }
    }
};

int main(){
    Cirqueue q(10);

    q.pop();                           //queue underflow
    q.push(10);
    cout<<endl<<"The front element is: "<<q.getFront();
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    q.push(110);                     //queue overflow
    cout<<"\nThe size of the queue is: "<<q.getSize();
    q.pop();
    q.pop();
    q.pop();
    cout<<endl<<"The front element is: "<<q.getFront();
    q.push(110);
    q.push(110);
    q.push(110);
    q.push(110);


    return 0;
}