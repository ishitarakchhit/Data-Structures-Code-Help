/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
 

Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
*/


class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        int element = num;
        double median;
        //when both the heaps have equal sizes then push the element after comparing it to current median
        if(maxheap.size() == minheap.size()){
            if(maxheap.size() == 0){
                maxheap.push(num);
                return;
            }

            median = (double)(maxheap.top() + minheap.top())/2;
            if( element > median)
                minheap.push(element);
            else 
                maxheap.push(element);
        }

        else if(maxheap.size() +1 == minheap.size()){
            median = minheap.top();
            if(element > median){
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(element);
            }
            else{
                maxheap.push(element);
            }
        }
        else{
            median = maxheap.top();
            if(element > median)
                minheap.push(element);
            else{
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(element);
            }
        }
    }
    
    double findMedian() {
        double median;
        if(maxheap.size() == minheap.size()){
            median = (double)(maxheap.top() + minheap.top())/2;  
        }

        else if(maxheap.size() +1 == minheap.size()){
            median = minheap.top();
        }
        else{
            median = maxheap.top();
        }

        return median;
    }
};