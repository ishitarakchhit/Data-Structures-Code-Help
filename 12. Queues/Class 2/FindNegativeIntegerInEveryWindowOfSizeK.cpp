/*
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Approach1: nested loops

// Approach2: sliding window concept, processing the first window and pushing the negative elements in queue, and then processing the next windows, i represents the index of ending box of window, then inside the loop we check if the queue is empty or not, if it is empty that means that we have not encountered any negative integer in the previous windoe so we can print 0 if it is not empty then we can print the queue's first element. Now when we consider the current window we need to pop the indices whcih should not be in the current window, now we need to push the indixes which have to be in the current window and which have valus less than 0. Aftr moving out of the loop out program didn't process that latest window so we use if statement to 
void findNegative(vector<int> &arr, int k)
{
    if (k > arr.size())
    {
        return;
    }
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            q.push(i);
        }
    }

    for (int i = k; i < arr.size(); i++)
    {
        if (q.empty())
        {
            cout << "0 ";
        }
        else
        {
            cout << arr[q.front()]<<" ";
        }

        if (!q.empty() && (q.front() <= i - k))
        {

            q.pop();
        }
        if (arr[i] < 0)
        {
            q.push(i);
        }
    }

    if (q.empty())
        cout << "0 ";
    else
    {
        cout << arr[q.front()]<<" ";
    }
}

int main()
{
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    findNegative(arr, 3);
}