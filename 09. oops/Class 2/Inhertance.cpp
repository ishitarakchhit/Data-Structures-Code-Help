#include<iostream>
using namespace std;

//Multilevel Inheritance       parent<- child <- grandchild
class Fruit{
    public:
    string name;
};

class Mango: public Fruit{
    public:
    int weight;
};

class Alphanso: public Mango{
    public: 
    string colour;
};


//Multiple Inheritance           
//      A     B
//      ^     ^
//       \   /
//         C

class A{
    public:
    int physics;
    A(){
        physics= 10;
    }
};

class B{
    public:
    int physics;
    B(){
        physics= 20;
    }
};

class C: public A, public B{
    public:
    int math;
};



//hierarchical                                          //opposite of multiple            
//      A     
//     ^ ^     
//    /   \   
//   B      C

class Car{
     public:
     int weight;
     void speedup(){
        cout<<"speeding up";
     }
};

class Scorpio: public Car{

};

class Fortuner: public Car{

};


//main function
int main(){
    Alphanso obj;

    cout<<obj.name<<obj.weight<<obj.colour;

    C obj1;
    //          cout<<endl<<obj1.physics;              V.imp. This poses a problem of ambiguity, therefore we use scope resolution operator (::)    
    cout<<endl<<obj1.A::physics;                        // scope resolution operator specifies the exact class of which we are accessing the member
 
    Fortuner obj2;
    cout<<endl<<obj2.weight;


}