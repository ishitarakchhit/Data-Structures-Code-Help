/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

Example 1:


Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 

Constraints:

1 <= k <= points.length <= 104
-104 < xi, yi < 104
*/

//class to create a customised heap
class compare{
    public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return (pow((double)a.first, 2) + pow((double)a.second,2) ) < (pow((double)b.first, 2) + pow((double)b.second,2) );
    }
};



class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, int>, vector<pair<int,int>>, compare> maxheap;

        //pushing k elements into the maxheap
        for(int i=0; i<k; i++){
            maxheap.push(make_pair(points[i][0], points[i][1]));
        }

        //pushing further n-k elements
        for(int i =k; i<points.size(); i++){

            //taking out the current vector from original vector and calc the distance
            vector<int> onepoint = points[i];
            double distance = (pow((double)onepoint[0], 2) + pow((double)onepoint[1],2) );

            //taking out the top most element from heap and calc the distance so that finally only minimum k elements are left in the heap
            pair<int, int> heaptop = maxheap.top();
            double topdistance = (pow((double)heaptop.first, 2) + pow((double)heaptop.second,2) );

            //if current distance is lesser than heap top then remove that element from heap and push current element
            if(topdistance > distance){
                maxheap.pop();
                maxheap.push(make_pair(onepoint[0], onepoint[1]));
            }

        }

        vector<vector<int>> ans;

        //popping all elements from heap to ans vector
        while(!maxheap.empty()){
            vector<int> temp;
            temp.push_back(maxheap.top().first);
            temp.push_back(maxheap.top().second);
            ans.push_back(temp);
            maxheap.pop();
        }

        return ans;
    }
};