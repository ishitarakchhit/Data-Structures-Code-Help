#include<iostream>
using namespace std;

class deque{
    public:
    int front ;
    int rear ;
    int size;
    int *arr;
    deque(int size){
        arr = new int[size];
        this->size = size;
        front =-1;
        rear = -1;
    }
    void pushFront(int data){
        if((front == 0 && rear == size-1) || (front == rear+1)){
            cout<<endl<<"Queue Overflow";
        }
        else if(front == 0 && rear<size-1 ){
            front = size-1;
            arr[front] = data;
        }
        else{
            arr[--front] = data;
        }
    }
    void pushBack(int data){
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
    void popFront(){
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

    void popBack(){
        if(rear == -1){
            cout<<endl<<"Queue Underflow";
            return;
        }
        else if(rear == front){
            rear = -1;
            front =-1;
        }
        else if(rear == 0){
            rear = size-1;
        }
        else{
            rear--;
        }

    }
    int getFront(){
        if(front == rear && front==-1){
            cout<<endl<<"Queue is empty";
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int getBack(){
        if(front == rear && front==-1){
            cout<<endl<<"Queue is empty";
            return -1;
        }
        else{
            return arr[rear];
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
        return rear-front+1;
    }
};

int main(){
    deque q(10);
    q.pushBack(10);
    q.pushBack(20);
    q.pushBack(30);
    q.pushBack(40);
    q.pushBack(50);
    q.pushBack(60);
    q.pushBack(70);  

    cout<<endl<<"Current front element is: "<<q.getFront();
    cout<<endl<<"Current Back element is: "<<q.getBack();

    q.pushFront(9);
    q.pushBack(80);
    q.pushBack(90);

    cout<<endl<<"Current front element is: "<<q.getFront();
    cout<<endl<<"Current Back element is: "<<q.getBack();

    q.pushFront(0);
    q.popFront();
    q.popFront();
    q.popFront();
    q.popFront();
    q.popBack();
    q.popBack();

    cout<<endl<<"Current front element is: "<<q.getFront();
    cout<<endl<<"Current Back element is: "<<q.getBack();
     
    q.popBack();
    q.popBack();
    q.popBack();
    q.popBack();
    q.popBack();

    return 0;
}