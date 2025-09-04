/*
Problem: Number of Substrings Containing All Three Characters
LeetCode: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
--------------------------------------
Given a string s of 'a', 'b', 'c', count the substrings that contain at least one of each.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force: O(n^2)
    long long bruteForce(string s) {
        int n = s.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt[3] = {0,0,0};
            for (int j = i; j < n; j++) {
                cnt[s[j]-'a']++;
                if (cnt[0] && cnt[1] && cnt[2]) {       // first time all 3 present
                    ans += (n - j);                     // all extensions stay valid
                    break;
                }
            }
        }
        return ans;
    }

    // Optimal (Sliding Window): O(n)
    long long slidingWindow(string s) {
        int n = s.size(), left = 0;
        int cnt[3] = {0,0,0};
        long long ans = 0;
        for (int right = 0; right < n; right++) {
            cnt[s[right]-'a']++;                        // expand
            while (cnt[0] && cnt[1] && cnt[2]) {        // shrink to minimal valid
                ans += (n - right);                     // all suffixes from right are valid
                cnt[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.bruteForce("abcabc") << "\n";
    cout << sol.slidingWindow("abcabc") << "\n";
    return 0;
}
