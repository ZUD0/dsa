/*
Problem: Subarrays with K Different Integers
LeetCode: https://leetcode.com/problems/subarrays-with-k-different-integers/
--------------------------------------
Given an integer array nums and an integer k, return the number of subarrays
with exactly k distinct integers.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force: O(n^2)
    long long bruteForce(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int,int> freq;
            for (int j = i; j < n; j++) {
                freq[nums[j]]++;                       // include element
                if ((int)freq.size() == k) ans++;      // count exact k distinct
                else if ((int)freq.size() > k) break;  // further increases distinct
            }
        }
        return ans;
    }

    // Helper: count subarrays with at most K distinct
    long long atMost(vector<int>& nums, int K) {
        if (K < 0) return 0;
        unordered_map<int,int> freq;
        int left = 0;
        long long res = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            freq[nums[right]]++;                       // expand
            while ((int)freq.size() > K) {             // shrink to ≤ K distinct
                if (--freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }
            res += (right - left + 1);                 // all suffixes ending at right
        }
        return res;
    }

    // Optimal: exact(k) = atMost(k) - atMost(k-1)
    long long slidingWindow(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

int main() {
    Solution sol;
    vector<int> a = {1,2,1,2,3};
    cout << sol.bruteForce(a, 2) << "\n";              // 7
    cout << sol.slidingWindow(a, 2) << "\n";
