/*
[   https://leetcode.com/problems/best-time-to-buy-and-sell-stock/  ]

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

#include <bits/stdc++.h>
using namespace std;

//time complexity O(n^2)

    int maxProfit(vector<int>& prices) {
        vector<int> ans;
        int temp;

        for(int i=0; i<prices.size(); i++){
            
            temp = *max_element(prices.begin()+i, prices.end());
           
                ans.push_back(temp-prices[i]);
            
        }

        return *max_element(ans.begin(), ans.end());

    }


int main(){
    vector<int> arr = {1,2,3,4,5};

    cout<<maxProfit(arr);
}