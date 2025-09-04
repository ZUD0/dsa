/*
Problem: Longest Substring with At Most K Distinct Characters
LeetCode: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
--------------------------------------
Given a string s and an integer k, return the length of the longest substring
that contains at most k distinct characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force: O(n^2)
    int bruteForce(string s, int k) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char,int> cnt;
            for (int j = i; j < n; j++) {
                cnt[s[j]]++;                           // include char
                if ((int)cnt.size() > k) break;        // stop if > k distinct
                ans = max(ans, j - i + 1);             // update best
            }
        }
        return ans;
    }

    // Optimal (Sliding Window): O(n)
    int slidingWindow(string s, int k) {
        if (k == 0) return 0;
        unordered_map<char,int> cnt;
        int left = 0, ans = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            cnt[s[right]]++;                           // expand
            while ((int)cnt.size() > k) {              // shrink until ≤ k distinct
                if (--cnt[s[left]] == 0) cnt.erase(s[left]);
                left++;
            }
            ans = max(ans, right - left + 1);          // update best
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.bruteForce("eceba", 2) << "\n";        // 3 ("ece")
    cout << sol.slidingWindow("eceba", 2) << "\n";
    return 0;
}
