import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

/*
 * @lc app=leetcode id=668 lang=java
 *
 * [668] Kth Smallest Number in Multiplication Table
 *
 * https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
 *
 * algorithms
 * Hard (48.80%)
 * Likes:    858
 * Dislikes: 26
 * Total Accepted:    29.8K
 * Total Submissions: 61.2K
 * Testcase Example:  '3\n3\n5'
 *
 * Nearly everyone has used the Multiplication Table. The multiplication table
 * of size m x n is an integer matrix mat where mat[i][j] == i * j
 * (1-indexed).
 * 
 * Given three integers m, n, and k, return the k^th smallest element in the m
 * x n multiplication table.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 3, k = 5
 * Output: 3
 * Explanation: The 5^th smallest number is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 2, n = 3, k = 6
 * Output: 6
 * Explanation: The 6^th smallest number is 6.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= m, n <= 3 * 10^4
 * 1 <= k <= m * n
 * 
 * 
 */

// @lc code=start
class Solution {
    public int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n + 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            int c = count(mid, m, n);
            if (c >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return high;
    }

    private int count(int v, int m, int n) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            int temp = Math.min(v / i, n);
            count += temp;
        }
        return count;
    }
}
// @lc code=end
