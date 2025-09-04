/*
Problem: Longest Repeating Character Replacement
LeetCode: https://leetcode.com/problems/longest-repeating-character-replacement/
--------------------------------------
Given a string s and an integer k, return the length of the longest substring
you can make where all characters are the same after replacing at most k characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force: O(n^2)
    int bruteForce(string s, int k) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int maxFreq = 0;
            for (int j = i; j < n; j++) {
                maxFreq = max(maxFreq, ++freq[s[j]-'A']); // update dominant char
                int len = j - i + 1;
                if (len - maxFreq <= k) ans = max(ans, len); // valid if replacements ≤ k
            }
        }
        return ans;
    }

    // Optimal (Sliding Window): O(n)
    int slidingWindow(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, maxFreq = 0, ans = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            maxFreq = max(maxFreq, ++freq[s[right]-'A']);   // update max freq in window
            while ((right - left + 1) - maxFreq > k) {      // shrink if need > k changes
                freq[s[left]-'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);               // update best
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.bruteForce("AABABBA", 1) << "\n";
    cout << sol.slidingWindow("AABABBA", 1) << "\n";
    return 0;
}
