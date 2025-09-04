# Sliding Window & Two-Pointer Problems in C++

This repository contains a curated collection of **classic sliding window and two-pointer problems** from LeetCode, solved in **C++**.  

For each problem, you will find:
- A **problem description** at the top of the file  
- A **brute force solution** (O(n²) or worse, to illustrate baseline thinking)  
- An **optimized sliding window / two-pointer solution** (O(n))  
- A small **`main()` driver** for quick testing  

This repo is intended as both a **learning lab** and a **reference library** for sliding window patterns.

---

## 📌 Problems Covered

| #  | Problem | LeetCode ID | Approach | Brute Force | Optimized |
|----|----------|-------------|----------|-------------|-----------|
| 1  | Longest Substring Without Repeating Characters | [3](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | Sliding Window + Hashmap | O(n²) | O(n) |
| 2  | Max Consecutive Ones III | [1004](https://leetcode.com/problems/max-consecutive-ones-iii/) | Two-Pointer Shrink Window | O(n²) | O(n) |
| 3  | Fruit Into Baskets | [904](https://leetcode.com/problems/fruit-into-baskets/) | Longest Subarray with ≤ 2 Distinct | O(n²) | O(n) |
| 4  | Longest Repeating Character Replacement | [424](https://leetcode.com/problems/longest-repeating-character-replacement/) | Sliding Window + Frequency Count | O(n²) | O(n) |
| 5  | Binary Subarray With Sum | [930](https://leetcode.com/problems/binary-subarrays-with-sum/) | Prefix Sum / AtMost Trick | O(n²) | O(n) |
| 6  | Count Number of Nice Subarrays | [1248](https://leetcode.com/problems/count-number-of-nice-subarrays/) | AtMost Trick on Odds | O(n²) | O(n) |
| 7  | Number of Substrings Containing All Three Characters | [1358](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/) | Sliding Window + Counting | O(n²) | O(n) |
| 8  | Maximum Points You Can Obtain From Cards | [1423](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/) | Complement Sliding Window | O(k²) | O(n) |
| 9  | Count Subarrays With Score Less Than K | [2302](https://leetcode.com/problems/count-subarrays-with-score-less-than-k/) | Sliding Window + Shrink | O(n²) | O(n) |
| 10 | Ways to Split Array Into Good Subarrays | [2750](https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/) | Combinatorics (gap product) | Exponential | O(n) |

---

## 🛠️ How to Compile & Run

Each problem is in its own `.cpp` file. Example:

```bash
g++ 01_longest_substring.cpp -o run
./run
