#include <bits/stdc++.h>
using namespace std;

int Solution::solve(vector<int> &arr)
{
    int n = arr.size();
    vector<int> oddPrefixSum(n, 0);
    vector<int> evenPrefixSum(n, 0);
    oddPrefixSum[0] = 0;
    evenPrefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (i % 2 != 0)
        {
            oddPrefixSum[i] = oddPrefixSum[i - 1] + arr[i];
            evenPrefixSum[i] = evenPrefixSum[i - 1];
        }
        else
        {
            oddPrefixSum[i] = oddPrefixSum[i - 1];
            evenPrefixSum[i] = evenPrefixSum[i - 1] + arr[i];
        }
    }

    int count = 0;
    // for every i, let "oddIndexSumAfterRemoval" denote the sum of
    // odd indexed elements after removing index i
    // Sum of odd indexed elements from (0,i-1) + sum of even indexed elements from (i+1,n-1)
    // oddIndexSumAfterRemoval[i] = oddPrefixSum[i-1]  + evenPrefixSum[n-1] - evenPrefixSum[i]

    // for every i, let "evenIndexSumAfterRemoval" denote the sum of
    // even indexed elements after removing index i
    // Sum of odd indexed elements from (0,i-1) + sum of even indexed elements from (i+1,n-1)
    // evenIndexSumAfterRemoval[i] = evenPrefixSum[i-1]  + oddPrefixSum[n-1] - oddPrefixSum[i]

    for (int i = 0; i < n; i++)
    {
        int oddIndexSumAfterRemoval;
        int evenIndexSumAfterRemoval;
        if (i == 0)
        {
            oddIndexSumAfterRemoval = evenPrefixSum[n - 1] - evenPrefixSum[i];
            evenIndexSumAfterRemoval = oddPrefixSum[n - 1] - oddPrefixSum[i];
        }
        else
        {
            oddIndexSumAfterRemoval = oddPrefixSum[i - 1] + evenPrefixSum[n - 1] - evenPrefixSum[i];
            evenIndexSumAfterRemoval = evenPrefixSum[i - 1] + oddPrefixSum[n - 1] - oddPrefixSum[i];
        }
        if (oddIndexSumAfterRemoval == evenIndexSumAfterRemoval)
        {
            count++;
        }
    }

    return count;
}