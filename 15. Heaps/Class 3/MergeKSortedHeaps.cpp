#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class info{
    public:
    int data;
    int row;
    int col;

    info(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
   
};
class compare{
    public:
    bool operator()(info* a, info* b){
        return a->data > b->data;
    }
};


vector<int> mergeKSorted(int arr[][4], int k, int n){
    priority_queue<info*, vector<info*>, compare> heap;                 //declaring a min heap with type info and data to be arranged with respect to info->data
    for (int i = 0; i < k; i++)
    {
        info* temp = new info(arr[i][0], i, 0);
        heap.push(temp);
    }

    vector<int> ans;
    while(!heap.empty()){
        info* temp = heap.top();
        int element = temp->data;
        int toprow = temp->row;
        int topcol = temp->col;

        heap.pop();                                                    //removing the minimum element from heap
        ans.push_back(element);
        
        if(topcol +1 < n){
            info* newInfo = new info(arr[toprow][topcol+1], toprow, topcol+1);
            heap.push(newInfo);                                           //pushing a new element into the heap

        }
    }
    return ans;
    
}


int main(){
    int arr[][4]= {{2,4,6,8}, 
                   {1,3,5,7},
                   {0,9,10,11}};
    int n = 4;
    int K = 3;
    vector<int> ans;
    ans = mergeKSorted(arr, K, 4);
    
    for(auto i: ans)
        cout<<i<<" ";

    return 0;
}