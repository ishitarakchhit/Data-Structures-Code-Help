#include<iostream>
using namespace std;

class A{
    public:

    //function overloading
    int sum(int a, int b){
        return a+b;
    }

    int sum(int a, int b, int c){
        return a+b+c;
    }

    int sum(int a, float b){
        return a+b+10;
    }
};

int main(){
    A obj;
    cout<<endl<<obj.sum(2,5);
    cout<<endl<<obj.sum(2,5,80);
    cout<<endl<<obj.sum(2,5.9f);
    
}