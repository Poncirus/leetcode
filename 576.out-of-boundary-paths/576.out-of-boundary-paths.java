/*
 * @lc app=leetcode id=576 lang=java
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
class Solution {
    public int findPaths(int m, int n, int N, int i, int j) {
        final int MOD = (int)1e9 + 7;
        
        int[][] previous, current;
        previous = new int[m][n];
        current = new int[m][n];

        for (int k = 0; k < N; k++) {
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {

                    int ways = 0;

                    ways = (ways + ((x - 1 < 0) ? 1 : (previous[x - 1][y])) % MOD) % MOD;
                    ways = (ways + ((x + 1 >= m) ? 1 : (previous[x + 1][y])) % MOD) % MOD;
                    ways = (ways + ((y - 1 < 0) ? 1 : (previous[x][y - 1])) % MOD) % MOD;
                    ways = (ways + ((y + 1 >= n) ? 1 : (previous[x][y + 1])) % MOD) % MOD;

                    current[x][y] = ways;
                }
            }

            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    previous[x][y] = current[x][y];
                }
            }
        }

        return previous[i][j];
    }
}
// @lc code=end
