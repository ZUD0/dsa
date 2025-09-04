/*
Problem: Maximum Points You Can Obtain From Cards
LeetCode: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
--------------------------------------
Pick exactly k cards from either end to maximize score.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force (by splits): O(k^2) naive summing
    int bruteForce(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), best = 0;
        for (int x = 0; x <= k; x++) {
            int sum = 0;
            for (int i = 0; i < x; i++) sum += cardPoints[i];           // x from left
            for (int j = 0; j < k - x; j++) sum += cardPoints[n-1-j];   // k-x from right
            best = max(best, sum);                                      // keep max
        }
        return best;
    }

    // Optimal (Complement window): O(n)
    int slidingWindow(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if (k == n) return total;
        int window = 0;
        for (int i = 0; i < n - k; i++) window += cardPoints[i];        // initial window sum
        int minWindow = window;
        for (int i = n - k; i < n; i++) {
            window += cardPoints[i];                                    // slide right
            window -= cardPoints[i - (n - k)];
            minWindow = min(minWindow, window);                         // track min
        }
        return total - minWindow;                                       // take complement
    }
};

int main() {
    Solution sol;
    vector<int> v = {1,2,3,4,5,6,1};
    cout << sol.bruteForce(v, 3) << "\n";
    cout << sol.slidingWindow(v, 3) << "\n";
    return 0;
}
