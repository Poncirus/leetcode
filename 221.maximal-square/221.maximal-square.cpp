/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (35.42%)
 * Likes:    2309
 * Dislikes: 59
 * Total Accepted:    196.1K
 * Total Submissions: 550.6K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int size = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '0')
                {
                    continue;
                }

                for (int k = 1; i + k - 1 < matrix.size() && j + k - 1 < matrix[0].size(); k++)
                {
                    bool flag = false;
                    for (int l = 0; l < k; l++)
                    {
                        if (matrix[i+k-1][j+l] == '0' || matrix[i+l][j+k-1] == '0')
                            flag = true;
                    }

                    if (flag)
                    {
                        if (k - 1 > size)
                        {
                            size = k - 1;
                        }
                        break;
                    }

                    if ((i + k == matrix.size() || j + k == matrix[0].size()) && k > size)
                    {
                        size = k;
                    }
                }
            }
        }

        return size*size;
    }
};
// @lc code=end

