#include<iostream>
using namespace std;


//declaring a class named Animal having data members and member functions
class Animal{
  private:                                                   //access modifier = private, to access private members of a class we use getters and setters
    int weight;

  public:                                                    //access mofifier= public 
    //state or properties
    int age;
    string name;

    //constructor
    Animal(){
        this->weight = 1;
        this->age = 20;
        this->name = "small";
        cout<<endl<<"Constructor called";
    }

    // parameterized constructor
    Animal(int age){
        this->weight = 1;
        this->age = age;
        this->name = "small";
        cout<<endl<<"Parameterized Constructor called";
    }



    //behaviour
    void eat(){
        cout<<"eating";
    }
    void sleep(){
        cout<<"sleeping";
    }
    void setweight(int weight ){                           //setter
        this->weight = weight;                             //this is pointer to current object, if we do not use this keyword then both weight(s) will refer the weight declacred in function
    }
    void getweight(){                                 //getter
        cout<<weight;
    }

};


int main(){

    //the size of empty class is 1
    cout<<sizeof(Animal);

    //to declare an object with instance of class Animal
    Animal obj;         

    //to access state of obj(or object)
    obj.name = "Lion";

    cout<<endl;
    //to access private member- weight
    obj.setweight(5);

    obj.getweight();


    //dynamic object creation
    Animal* a = new Animal;
    (*a).age= 19;
    //or 
    a->age= 20;

    //calling a parameterised constructor
    Animal* b = new Animal(100);
    

    





}