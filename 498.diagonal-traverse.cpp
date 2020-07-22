/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (46.75%)
 * Likes:    764
 * Dislikes: 333
 * Total Accepted:    84.5K
 * Total Submissions: 175.8K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * Output:  [1,2,4,7,5,3,6,8,9]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The total number of elements of the given matrix will not exceed 10,000.
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return res;

        int i = 0, j = 0;
        bool up = true;
        while (i != matrix.size() - 1 || j != matrix[0].size() - 1)
        {
            res.push_back(matrix[i][j]);
            if (up)
            {
                if (j == matrix[0].size() - 1)
                {
                    i++;
                    up = false;
                }
                else if (i == 0)
                {
                    j++;
                    up = false;
                }
                else
                {
                    i--;
                    j++;
                }
            }
            else
            {
                if (i == matrix.size() - 1)
                {
                    j++;
                    up = true;
                }
                else if (j == 0)
                {
                    i++;
                    up = true;
                }
                else
                {
                    i++;
                    j--;
                }
            }
        }

        res.push_back(matrix[matrix.size() - 1][matrix[0].size() - 1]);
        return res;
    }
};
// @lc code=end
