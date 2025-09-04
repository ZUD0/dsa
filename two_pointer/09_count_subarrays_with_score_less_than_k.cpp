/*
Problem: Count Subarrays With Score Less Than K
LeetCode: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
--------------------------------------
Score of subarray = sum(subarray) * length(subarray). Count subarrays with score < k.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force: O(n^2)
    long long bruteForce(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                long long len = j - i + 1;
                if (sum * len < k) ans++;             // count if score < k
                else break;                           // longer will only increase score
            }
        }
        return ans;
    }

    // Optimal (Sliding Window): O(n)
    long long slidingWindow(vector<int>& nums, long long k) {
        long long ans = 0, sum = 0;
        int left = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            sum += nums[right];                       // expand
            while (left <= right && sum * (right - left + 1) >= k) {
                sum -= nums[left];                    // shrink until score < k
                left++;
            }
            ans += (right - left + 1);                // all suffixes ending at right are valid
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> a = {2,1,4,3,5};
    cout << sol.bruteForce(a, 10) << "\n";
    cout << sol.slidingWindow(a, 10) << "\n";
    return 0;
}
