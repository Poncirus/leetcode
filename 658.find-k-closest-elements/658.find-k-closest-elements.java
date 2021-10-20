import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

/*
 * @lc app=leetcode id=658 lang=java
 *
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (43.60%)
 * Likes:    3310
 * Dislikes: 369
 * Total Accepted:    224.2K
 * Total Submissions: 513.3K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * Given a sorted integer array arr, two integers k and x, return the k closest
 * integers to x in the array. The result should also be sorted in ascending
 * order.
 * 
 * An integer a is closer to x than an integer b if:
 * 
 * 
 * |a - x| < |b - x|, or
 * |a - x| == |b - x| and a < b
 * 
 * 
 * 
 * Example 1:
 * Input: arr = [1,2,3,4,5], k = 4, x = 3
 * Output: [1,2,3,4]
 * Example 2:
 * Input: arr = [1,2,3,4,5], k = 4, x = -1
 * Output: [1,2,3,4]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * arr is sorted in ascending order.
 * -10^4 <= arr[i], x <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(k + 1, new Comparator<Integer>(){
            @Override
            public int compare(Integer o1, Integer o2) {
                int dis = Math.abs(o2 - x) - Math.abs(o1 - x);
                if (dis != 0) {
                    return dis;
                }
                return o2 - o1;
            }
        });

        for (int i = 0; i < arr.length; i++) {
            pq.add(arr[i]);
            if (i < k) {
                continue;
            }
            pq.poll();
        }

        List<Integer> res = new ArrayList<>();
        while (!pq.isEmpty()) {
            res.add(pq.poll());
        }
        res.sort((a, b) -> a - b);
        return res;
    }
}
// @lc code=end

