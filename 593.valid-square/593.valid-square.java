/*
 * @lc app=leetcode id=593 lang=java
 *
 * [593] Valid Square
 *
 * https://leetcode.com/problems/valid-square/description/
 *
 * algorithms
 * Medium (43.42%)
 * Likes:    538
 * Dislikes: 645
 * Total Accepted:    68.3K
 * Total Submissions: 157.3K
 * Testcase Example:  '[0,0]\n[1,1]\n[1,0]\n[0,1]'
 *
 * Given the coordinates of four points in 2D space p1, p2, p3 and p4, return
 * true if the four points construct a square.
 * 
 * The coordinate of a point pi is represented as [xi, yi]. The input is not
 * given in any order.
 * 
 * A valid square has four equal sides with positive length and four equal
 * angles (90-degree angles).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * p1.length == p2.length == p3.length == p4.length == 2
 * -10^4 <= xi, yi <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        HashSet<Integer> hs = new HashSet<>(
                Arrays.asList(dis(p1, p2), dis(p1, p3), dis(p1, p4), dis(p2, p3), dis(p2, p4), dis(p3, p4)));
        return !hs.contains(0) && hs.size() == 2;
    }

    int dis(int[] a, int[] b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
}
// @lc code=end
