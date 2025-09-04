/*
Problem: 1248. Count Number of Nice Subarrays
LeetCode: https://leetcode.com/problems/count-number-of-nice-subarrays/
--------------------------------------
A subarray is nice if it contains exactly k odd numbers. Return the count of nice subarrays.
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
            int odd = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] & 1) odd++;                 // count odds
                if (odd == k) ans++;                    // exact k odds
                else if (odd > k) break;                // further only increases odds
            }
        }
        return ans;
    }

    // Optimal (AtMost trick): O(n)
    long long atMost(vector<int>& nums, int K) {
        if (K < 0) return 0;
        int left = 0, odd = 0;
        long long res = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            if (nums[right] & 1) odd++;                 // include odd
            while (odd > K) {                           // shrink to ≤ K odds
                if (nums[left] & 1) odd--;
                left++;
            }
            res += (right - left + 1);                  // all suffixes valid
        }
        return res;
    }

    long long slidingWindow(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

int main() {
    Solution sol;
    vector<int> a = {1,1,2,1,1};
    cout << sol.bruteForce(a, 3) << "\n";
    cout << sol.slidingWindow(a, 3) << "\n";
    return 0;
}
