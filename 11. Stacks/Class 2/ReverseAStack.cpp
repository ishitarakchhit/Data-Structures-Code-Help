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


//function to reverse the stack
void reverseStack(stack<int> &s){
    //b.c
    if(s.empty()){
        return;
    }

    //to take out the top most element
    int target = s.top();
    s.pop();

    //f.c to remove all the elements from stack - r.c.
    reverseStack(s);

    //f.c to insert target to bottom - b.t.
    solve(s, target);


}


//main function
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    //so the stack is 10 20 30 40 50 

    //function call to reverse the stack
    reverseStack(st);
    
    //loop to print stack
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}