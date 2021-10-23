/*
 * @lc app=leetcode id=661 lang=java
 *
 * [661] Image Smoother
 *
 * https://leetcode.com/problems/image-smoother/description/
 *
 * algorithms
 * Easy (53.20%)
 * Likes:    337
 * Dislikes: 1442
 * Total Accepted:    59.1K
 * Total Submissions: 111K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * An image smoother is a filter of the size 3 x 3 that can be applied to each
 * cell of an image by rounding down the average of the cell and the eight
 * surrounding cells (i.e., the average of the nine cells in the blue
 * smoother). If one or more of the surrounding cells of a cell is not present,
 * we do not consider it in the average (i.e., the average of the four cells in
 * the red smoother).
 * 
 * Given an m x n integer matrix img representing the grayscale of an image,
 * return the image after applying the smoother on each cell of it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: img = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: [[0,0,0],[0,0,0],[0,0,0]]
 * Explanation:
 * For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
 * For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) =
 * 0
 * For the point (1,1): floor(8/9) = floor(0.88888889) = 0
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: img = [[100,200,100],[200,50,200],[100,200,100]]
 * Output: [[137,141,137],[141,138,141],[137,141,137]]
 * Explanation:
 * For the points (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) =
 * floor(137.5) = 137
 * For the points (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6)
 * = floor(141.666667) = 141
 * For the point (1,1): floor((50+200+200+200+200+100+100+100+100)/9) =
 * floor(138.888889) = 138
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == img.length
 * n == img[i].length
 * 1 <= m, n <= 200
 * 0 <= img[i][j] <= 255
 * 
 * 
 */

// @lc code=start
class Solution {
    public int[][] imageSmoother(int[][] M) {
        if (M == null)
            return null;
        int rows = M.length;
        if (rows == 0)
            return new int[0][];
        int cols = M[0].length;

        int result[][] = new int[rows][cols];

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int count = 0;
                int sum = 0;
                for (int incR : new int[] { -1, 0, 1 }) {
                    for (int incC : new int[] { -1, 0, 1 }) {
                        if (isValid(row + incR, col + incC, rows, cols)) {
                            count++;
                            sum += M[row + incR][col + incC];
                        }
                    }
                }
                result[row][col] = sum / count;
            }
        }

        return result;

    }

    private boolean isValid(int x, int y, int rows, int cols) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }
}
// @lc code=end
