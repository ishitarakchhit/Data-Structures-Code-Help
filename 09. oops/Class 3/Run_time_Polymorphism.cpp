#include<iostream>
using namespace std;


//class
class Animal{
    public:
    void speak(){
        cout<<"Speaking";
    }
};


class Dog: public Animal{
    public:
    //Overriding
    void speak(){
        cout<<"Barking";
    }
};

int main(){
    Animal a;
    Dog d;

    a.speak();
    cout<<endl;
    d.speak();
}