/*
Problem: Binary Subarray With Sum
LeetCode: https://leetcode.com/problems/binary-subarrays-with-sum/
--------------------------------------
Given a binary array nums and an integer goal, return the number of non-empty
subarrays with sum exactly equal to goal.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force: O(n^2)
    long long bruteForce(vector<int>& nums, int goal) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == goal) ans++;                  // count match
            }
        }
        return ans;
    }

    // Optimal (AtMost trick): O(n)
    long long atMost(vector<int>& nums, int S) {
        if (S < 0) return 0;
        int left = 0, sum = 0;
        long long count = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            sum += nums[right];                          // expand
            while (sum > S) {                            // shrink to sum ≤ S
                sum -= nums[left];
                left++;
            }
            count += (right - left + 1);                 // all suffixes valid
        }
        return count;
    }

    long long slidingWindow(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

int main() {
    Solution sol;
    vector<int> a = {1,0,1,0,1};
    cout << sol.bruteForce(a, 2) << "\n";
    cout << sol.slidingWindow(a, 2) << "\n";
    return 0;
}
