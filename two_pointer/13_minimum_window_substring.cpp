/*
Problem: Minimum Window Substring
LeetCode: https://leetcode.com/problems/minimum-window-substring/
--------------------------------------
Given two strings s and t, return the minimum window in s which contains all
the characters of t (with multiplicity). If no such window, return "".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force: O(n^2 + alphabet) — expand from each start until covers t
    string bruteForce(string s, string t) {
        if (t.empty()) return "";
        vector<int> need(128, 0);
        for (char c: t) need[c]++;

        int n = s.size();
        int bestLen = INT_MAX, bestL = -1;
        for (int i = 0; i < n; i++) {
            vector<int> have(128, 0);
            int remaining = t.size();
            for (int j = i; j < n; j++) {
                if (need[s[j]] > 0) {                  // only matters if needed
                    if (have[s[j]] < need[s[j]]) remaining--;
                    have[s[j]]++;
                }
                if (remaining == 0) {                  // first time window covers t
                    if (j - i + 1 < bestLen) bestLen = j - i + 1, bestL = i;
                    break;                             // any longer window from i is worse
                }
            }
        }
        return bestL == -1 ? "" : s.substr(bestL, bestLen);
    }

    // Optimal (Sliding Window): O(n)
    string slidingWindow(string s, string t) {
        if (t.empty()) return "";
        vector<int> need(128, 0), have(128, 0);
        int required = 0;
        f
