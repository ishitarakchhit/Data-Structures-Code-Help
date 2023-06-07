/*
//Approach: using recursion finding left and right parts and then rc for left+right
class Solution {
public:
    bool isValid(string s) {
        if(!s.size())
            return true;

        int found = s.find("abc");
        if(found != string::npos){
            //we have found the string "abc" in s
            string left = s.substr(0, found);
            string right = s.substr(found+3, s.size());

            return isValid(left+right);
        }
        return false;
    }
};
*/

//Approach: using recursion finding left and right parts and then rc for left+right
class Solution {
public:
    bool isValid(string s) {
        if(!s.size())
            return true;

        int found = s.find("abc");
        if(found != string::npos){
            //we have found the string "abc" in s
            string left = s.substr(0, found);
            string right = s.substr(found+3, s.size());

            return isValid(left+right);
        }
        return false;
    }
};

//Approach: stacks: if str[i] == 'c' then pop two elements and check if it is 'abc' or not, if not then push all three elements otherwise iterate to the next character in string.
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i = 0;
        char A, B, C;
        while(i< s.length()){
            if(i==0 && s[0]!='a')
                return false;
            if(s[i] == 'a' || s[i] == 'b'){
                st.push(s[i++]);
                continue;
            }
            if(st.size() > 1){
                B = st.top();
                cout<<"pop "<<st.top()<<endl;
                st.pop();
                
            }
            else{
                st.push(s[i]);
                i++;
                continue;
            }
            if(st.size() > 0){
                A = st.top(); 
                cout<<"pop "<<st.top()<<endl;
                st.pop();
                
            }
            else{
                cout<<"push "<<s[i]<<endl;
                st.push(s[i]);
                i++;
                continue;
            }
            C = s[i];
            if(A == 'a' && B=='b' && C=='c'){
                i++;
            }
            else{
                st.push(A);
                cout<<"push "<<A<<endl;
                st.push(B);
                cout<<"push "<<B<<endl;
                st.push(C);
                cout<<"push "<<C<<endl;
                i++;
            }
        }
        
        return(st.empty());
        
    }
};