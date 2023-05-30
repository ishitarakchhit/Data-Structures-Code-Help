#include<iostream>
#include<stack>
using namespace std;


//recursive functiion to insert value in sorted order, first start popping elements until top > target
void insertVal(stack<int> &st, int target){
    if(st.empty()){
        st.push(target);
        return;
    }
    int temp=0;
    if(target < st.top()){
        st.push(target);
        return;
    }
    else{
         temp = st.top();
    st.pop();

    }
    insertVal(st, target);

    //backtrack
    st.push(temp);

}

//functiont to sort the stack
void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int target = s.top();
    s.pop();

    sortStack(s);

    insertVal(s, target);
}


//main function
int main(){
    stack<int> st;
    st.push(40);
    st.push(35);
    st.push(10);
    st.push(0);
    st.push(20);
    st.push(20); 
    st.push(20);
    //so the stack is 10 20 30 40 50 

    //function call to reverse the stack
    sortStack(st);
    
    //loop to print stack
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}