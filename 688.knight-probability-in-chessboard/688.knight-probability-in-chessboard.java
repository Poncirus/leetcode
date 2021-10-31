import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

/*
 * @lc app=leetcode id=688 lang=java
 *
 * [688] Knight Probability in Chessboard
 *
 * https://leetcode.com/problems/knight-probability-in-chessboard/description/
 *
 * algorithms
 * Medium (51.04%)
 * Likes:    1644
 * Dislikes: 263
 * Total Accepted:    70.9K
 * Total Submissions: 138.9K
 * Testcase Example:  '3\n2\n0\n0'
 *
 * On an n x n chessboard, a knight starts at the cell (row, column) and
 * attempts to make exactly k moves. The rows and columns are 0-indexed, so the
 * top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
 * 
 * A chess knight has eight possible moves it can make, as illustrated below.
 * Each move is two cells in a cardinal direction, then one cell in an
 * orthogonal direction.
 * 
 * Each time the knight is to move, it chooses one of eight possible moves
 * uniformly at random (even if the piece would go off the chessboard) and
 * moves there.
 * 
 * The knight continues moving until it has made exactly k moves or has moved
 * off the chessboard.
 * 
 * Return the probability that the knight remains on the board after it has
 * stopped moving.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 2, row = 0, column = 0
 * Output: 0.06250
 * Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight
 * on the board.
 * From each of those positions, there are also two moves that will keep the
 * knight on the board.
 * The total probability the knight stays on the board is 0.0625.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1, k = 0, row = 0, column = 0
 * Output: 1.00000
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 25
 * 0 <= k <= 100
 * 0 <= row, column <= n
 * 
 * 
 */

// @lc code=start
class Solution {

    private List<List<List<Double>>> dp;

    int[][] direction = new int[][] { { 2, 1 }, { -2, 1 }, { 2, -1 }, { -2, -1 }, { 1, 2 }, { 1, -2 }, { -1, 2 },
            { -1, -2 } };

    public double knightProbability(int n, int k, int row, int column) {
        dp = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            List<List<Double>> r = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                List<Double> c = new ArrayList<>(Collections.nCopies(k, null));
                r.add(c);
            }
            dp.add(r);
        }
        return recursion(n, k, row, column);
    }

    private double recursion(int n, int k, int row, int column) {
        if (row < 0 || column < 0 || row >= n || column >= n) {
            return 0.0;
        }

        if (k == 0) {
            return 1.0;
        }

        Double p = dp.get(row).get(column).get(k - 1);
        if (p != null) {
            return p;
        }

        p = 0.0;
        for (int[] d : direction) {
            p += recursion(n, k - 1, row + d[0], column + d[1]);
        }
        p *= 0.125;

        dp.get(row).get(column).set(k - 1, p);
        return p;
    }
}
// @lc code=end
