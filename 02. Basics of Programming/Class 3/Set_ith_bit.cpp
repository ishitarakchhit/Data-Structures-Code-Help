
#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
#define R 3
#define C 3

int func(int num){
	int a= 1;
	num = num| a;
	return num;
}


int main(){
    int num;
	cin>>num;

	cout<<func(num);

}
