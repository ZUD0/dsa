/*
Problem: 2750. Ways to Split Array Into Good Subarrays
LeetCode: https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/
--------------------------------------
A subarray is "good" if it contains exactly one `1`. Return the number of ways to split
the array into good subarrays (mod 1e9+7).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int MOD = 1'000'000'007;

    // Check if a cut pattern splits into pieces each having exactly one '1'
    bool isGoodSplit(const vector<int>& nums, const vector<int>& cut) {
        int ones = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == 1) ones++;                     // count ones in current piece
            if (i == (int)nums.size() - 1 || cut[i]) {    // piece ends here
                if (ones != 1) return false;              // piece must have exactly one '1'
                ones = 0;                                 // reset for next piece
            }
        }
        return true;
    }

public:
    // Brute Force (Exponential): O(2^(n-1) * n) for small n
    long long bruteForce(vector<int>& nums) {
        int n = nums.size();
        if (!count(nums.begin(), nums.end(), 1)) return 0;
        long long ways = 0;
        vector<int> cut(n, 0);                            // cut[i]=1 means cut after i
        for (int mask = 0; mask < (1 << (n - 1)); mask++) {
            for (int i = 0; i < n - 1; i++) cut[i] = (mask >> i) & 1;   // build pattern
            cut[n - 1] = 1;                                             // force final cut
            if (isGoodSplit(nums, cut)) ways++;                          // count valid pattern
        }
        return ways % MOD;
    }

    // Optimal (Combinatorics): O(n)
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        vector<int> ones;
        for (int i = 0; i < (int)nums.size(); i++) if (nums[i] == 1) ones.push_back(i);
        if (ones.empty()) return 0;
        if (ones.size() == 1) return 1;
        long long ans = 1;
        for (int i = 1; i < (int)ones.size(); i++) {
            int gap = ones[i] - ones[i-1] - 1;           // zeros between consecutive ones
            ans = (ans * (gap + 1)) % MOD;               // multiply choices from this gap
        }
        return (int)ans;
    }
};

int main() {
    Solution sol;
    vector<int> a = {0,1,0,0,1,0,1};
    cout << sol.bruteForce(a) << "\n";
    cout << sol.numberOfGoodSubarraySplits(a) << "\n";
    return 0;
}
