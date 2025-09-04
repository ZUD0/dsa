/*
Problem: Max Consecutive Ones III
LeetCode: https://leetcode.com/problems/max-consecutive-ones-iii/
--------------------------------------
Given a binary array nums and an integer k, return the maximum number of consecutive 1's
in the array if you can flip at most k 0's.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force: O(n^2)
    int bruteForce(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) zeros++;
                if (zeros > k) break;             // can’t flip more than k zeros
                ans = max(ans, j - i + 1);        // update best window
            }
        }
        return ans;
    }

    // Optimal (Two Pointers): O(n)
    int slidingWindow(vector<int>& nums, int k) {
        int left = 0, zeros = 0, ans = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            if (nums[right] == 0) zeros++;        // include zero
            while (zeros > k) {                   // shrink until ≤ k zeros
                if (nums[left] == 0) zeros--;
                left++;
            }
            ans = max(ans, right - left + 1);     // update best
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1,1,1,0,0,0,1,1,1,1,0};
    cout << sol.bruteForce(a, 2) << "\n";
    cout << sol.slidingWindow(a, 2) << "\n";
    return 0;
}
