#include<iostream>
#include<stack>
using namespace std;

//recursive function to push target at bottom
void solve(stack<int> &st, int target){
    if(st.empty()){
        st.push(target);
        return;
    }

    int temp = st.top();
    st.pop();
    solve(st, target);

    //backtrack
    st.push(temp);

}

//function to take out the top element and call solve function so that it pushes it to the bottom
void insertAtBottom(stack<int> &s){
    if(s.empty()){
        cout<<"Stack is empty"<<endl;
        return;
    }

    // to take out the top most element 
    int target = s.top();
    s.pop();

    //function call to push at bottom
    solve(s, target);
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    //so the stack becomes 10 20 30 40 50 

    insertAtBottom(st);

    //loop to print stack
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }

}