 
 /*
[  https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650 ]
 PROBLEM STATEMENT
You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair. Each time you can either climb one step or two steps. You are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step.

Example :
N=3

We can climb one step at a time i.e. {(0, 1) ,(1, 2),(2,3)} or we can climb the first two-step and then one step i.e. {(0,2),(1, 3)} or we can climb first one step and then two step i.e. {(0,1), (1,3)}.
Input format :

The first line contains an integer 'T', which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only argument of each test case contains an integer 'N', representing the number of stairs.
Output Format :
For each test case/query, print the number of distinct ways to reach the top of stairs. Since the number can be huge, so return output modulo 10^9+7.

Output for every test case will be printed in a separate line.
Note :
You do not need to print anything. It has already been taken care of.
Constraints :
1 <= 'T' <= 10
0 <= 'N' <= 10^5

Where 'T' is the number of test cases, and 'N' is the number of stairs.

It is guaranteed that sum of 'N' over all test cases is <= 10^5.
 */
 
 
 
 //Approach: Recursion but best approach: DP
 #include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    //base case
    if(nStairs <0)
        return 0;
    if(nStairs == 0)
        return 1;

    int ans = countDistinctWays(nStairs -1) 
              + countDistinctWays(nStairs -2);
}