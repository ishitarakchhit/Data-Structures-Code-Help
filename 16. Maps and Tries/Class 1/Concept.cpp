#include<unordered_map>
#include<iostream>
using namespace std;

int main(){
    unordered_map<string, int> map;

    //to insert values in the map
    pair<string, int> p = make_pair("Alto", 0);
    map.insert(p);

    map.insert(make_pair("Baleno", 1));

    map["Fortuner"] = 2;

    //to access values via key
    cout<<"value of fortuner: "<<map.at("Fortuner")<<endl;
    cout<<"value of honda: "<<map["honda"]<<endl;                          //code map[] also creates a new key- value set with value 0 though it doesn't existed before

    //to search for a key
    cout<<"To search for innova: "<<map.count("Innova")<<endl;

    if(map.find("Alto") != map.end()){
        cout<<"alto found"<<endl;
    }
    else        
        cout<<"alto not found"<<endl;
    
    //to find the size of map
    cout<<"size of map is: "<<map.size()<<endl;

    //to check if map is empty or not
    cout<<"to check if map is empty or not: "<<map.empty()<<endl;

    //to traverse the map
    cout<<endl<<"Traversing the map"<<endl;
    for(auto i = map.begin(); i!= map.end(); i++){
        cout<<i->first<<"->"<<i->second<<endl;
    }
    return 0;
}