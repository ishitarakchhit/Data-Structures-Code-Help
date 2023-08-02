#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int solution(int N, vector<int> &A, vector<int> &B)
{
    unordered_map<int, int> frequencyOfNumbers;
    vector<int> freq(N);
    for (int i = 0; i < N; i++)
    {
        frequencyOfNumbers[A[i]]++;
        frequencyOfNumbers[B[i]]++; // this stores the freqyency of each number in graph
    }

     for (auto i = frequencyOfNumbers.begin(); i != frequencyOfNumbers.end(); i++)
     {
        int index = i->first;
         freq[index] = i->second;
     }
    

    int second = 0;
    while (find(freq.begin(), freq.end(), 1) != freq.end())
    {
        vector<int> index;
        for (int i = 0; i < N; i++)
        {
            if (A[i] == -1) // this marks that the current node now no longer exsists
                continue;

            if (frequencyOfNumbers[A[i]] == 1)
            {
                A[i] = -1;
                freq[A[i]]--;
                frequencyOfNumbers[A[i]]--;
                index.push_back(i);
            }

            if (frequencyOfNumbers[B[i]] == 1)
            {
                B[i] = -1;
                freq[B[i]]--;
                frequencyOfNumbers[B[i]]--;
                index.push_back(i);
            }
        }
        for (int i = 0; i < index.size(); i++)
        {
            if (B[i] != -1)
            {   freq[B[index[i]]]--;
                frequencyOfNumbers[B[index[i]]]--;
                B[i] = -1;
            }
            if (A[i] != -1)
            {
                freq[A[index[i]]]--;
                frequencyOfNumbers[A[index[i]]]--;
                A[i] = -1;
            }
        }
        second++;
    }

    return second;
}

int main()
{
    int N = 6;
    vector<int> A = {0, 1, 2,1 ,4,4};
    vector<int> B = {1, 2, 0, 4,5,6};

    int result = solution(N, A, B);
    cout << result << endl; // Output: 1

    return 0;
}
