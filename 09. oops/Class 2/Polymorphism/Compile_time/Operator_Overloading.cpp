#include<iostream>
using namespace std;


class P{
    public:
    int val;

    //operator overloading
    void operator+(P& obj2){
        int value1= this-> val;
        int value2= obj2.val;
        cout<<(value2- value1);
    }
};

int main(){
    P obj1, obj2;
    obj1.val = 7;
    obj2.val = 2;

    obj1 + obj2;
}
