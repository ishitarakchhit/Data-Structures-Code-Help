#include<iostream>
#include<unordered_map>
using namespace std;

void countOcc(string str){
    unordered_map<char, int> map;

    for(int i=0; i<str.length(); i++){
        map[str[i]]++;
    }

    //print the occurances
    for(auto i= map.begin(); i!=map.end(); i++){
        cout<<i->first<<" -> " <<i->second<<endl;
    }

    return;
}

int main(){
    string str = "Thiruvananthapuram";

    countOcc(str);
}