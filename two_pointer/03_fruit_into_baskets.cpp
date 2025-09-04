/*
Problem: Fruit Into Baskets
LeetCode: https://leetcode.com/problems/fruit-into-baskets/
--------------------------------------
Given an integer array fruits where fruits[i] is the type of fruit, you have two baskets.
Return the length of the longest subarray that contains at most two distinct types.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force: O(n^2)
    int bruteForce(vector<int>& fruits) {
        int n = fruits.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> types;
            for (int j = i; j < n; j++) {
                types.insert(fruits[j]);
                if ((int)types.size() > 2) break; // stop when >2 types
                ans = max(ans, j - i + 1);        // update best
            }
        }
        return ans;
    }

    // Optimal (Sliding Window with counts): O(n)
    int slidingWindow(vector<int>& fruits) {
        unordered_map<int,int> cnt;
        int left = 0, ans = 0;
        for (int right = 0; right < (int)fruits.size(); right++) {
            cnt[fruits[right]]++;                 // include new type
            while ((int)cnt.size() > 2) {         // shrink until ≤2 types
                if (--cnt[fruits[left]] == 0) cnt.erase(fruits[left]);
                left++;
            }
            ans = max(ans, right - left + 1);     // update best
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> f = {1,2,3,2,2};
    cout << sol.bruteForce(f) << "\n";
    cout << sol.slidingWindow(f) << "\n";
    return 0;
}
