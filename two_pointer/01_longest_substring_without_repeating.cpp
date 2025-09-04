/*
Problem: Longest Substring Without Repeating Characters
LeetCode: https://leetcode.com/problems/longest-substring-without-repeating-characters/
--------------------------------------
Given a string s, find the length of the longest substring without repeating characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force: O(n^2)
    int bruteForce(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            for (int j = i; j < n; j++) {
                if (st.count(s[j])) break;        // stop if repeating character
                st.insert(s[j]);
                ans = max(ans, j - i + 1);        // update max length
            }
        }
        return ans;
    }

    // Optimal (Sliding Window): O(n)
    int slidingWindow(string s) {
        unordered_map<char,int> last;
        int left = 0, ans = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            if (last.count(s[right]) && last[s[right]] >= left) {
                left = last[s[right]] + 1;        // jump left past previous occurrence
            }
            last[s[right]] = right;               // record last seen index
            ans = max(ans, right - left + 1);     // update best
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << sol.bruteForce(s) << "\n";
    cout << sol.slidingWindow(s) << "\n";
    return 0;
}
