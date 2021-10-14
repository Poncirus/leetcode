import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.PriorityQueue;

/*
 * @lc app=leetcode id=632 lang=java
 *
 * [632] Smallest Range Covering Elements from K Lists
 *
 * https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/
 *
 * algorithms
 * Hard (56.35%)
 * Likes:    1719
 * Dislikes: 28
 * Total Accepted:    54K
 * Total Submissions: 95.6K
 * Testcase Example:  '[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]'
 *
 * You have k lists of sorted integers in non-decreasing order. Find the
 * smallest range that includes at least one number from each of the k lists.
 * 
 * We define the range [a, b] is smaller than range [c, d] if b - a < d - c or
 * a < c if b - a == d - c.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
 * Output: [20,24]
 * Explanation: 
 * List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
 * List 2: [0, 9, 12, 20], 20 is in range [20,24].
 * List 3: [5, 18, 22, 30], 22 is in range [20,24].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
 * Output: [1,1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [[10,10],[11,11]]
 * Output: [10,11]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums = [[10],[11]]
 * Output: [10,11]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums = [[1],[2],[3],[4],[5],[6],[7]]
 * Output: [1,7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * nums.length == k
 * 1 <= k <= 3500
 * 1 <= nums[i].length <= 50
 * -10^5 <= nums[i][j] <= 10^5
 * nums[i] is sorted in non-decreasing order.
 * 
 * 
 */

// @lc code=start
class Solution {
    public int[] smallestRange(List<List<Integer>> a) {
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(o -> a.get(o[0]).get(o[1])));
        int max = Integer.MIN_VALUE, start = 0, end = Integer.MAX_VALUE;
        for (int i = 0; i < a.size(); i++) {
            q.offer(new int[] { i, 0 });
            max = Math.max(max, a.get(i).get(0));
        }
        while (q.size() == a.size()) {
            int e[] = q.poll(), row = e[0], col = e[1];
            if (end - start > max - a.get(row).get(col)) {
                start = a.get(row).get(col);
                end = max;
            }
            if (col + 1 < a.get(row).size()) {
                q.offer(new int[] { row, col + 1 });
                max = Math.max(max, a.get(row).get(col + 1));
            }
        }
        return new int[] { start, end };
    }
}
// @lc code=end
