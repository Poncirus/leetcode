/*
 * @lc app=leetcode id=546 lang=cpp
 *
 * [546] Remove Boxes
 *
 * https://leetcode.com/problems/remove-boxes/description/
 *
 * algorithms
 * Hard (40.59%)
 * Likes:    622
 * Dislikes: 50
 * Total Accepted:    14.9K
 * Total Submissions: 35.1K
 * Testcase Example:  '[1,3,2,2,2,3,4,3,1]\r'
 *
 * Given several boxes with different colors represented by different positive
 * numbers.
 * You may experience several rounds to remove boxes until there is no box
 * left. Each time you can choose some continuous boxes with the same color
 * (composed of k boxes, k >= 1), remove them and get k*k points.
 * Find the maximum points you can get.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: boxes = [1,3,2,2,2,3,4,3,1]
 * Output: 23
 * Explanation:
 * [1, 3, 2, 2, 2, 3, 4, 3, 1] 
 * ----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
 * ----> [1, 3, 3, 3, 1] (1*1=1 points) 
 * ----> [1, 1] (3*3=9 points) 
 * ----> [] (2*2=4 points)
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= boxes.length <= 100
 * 1 <= boxes[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int removeBoxes(vector<int> &boxes)
    {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, 0)));
        for (int i = 0; i < n; i++)
        {
            for (int k = i; k < n; k++)
            {
                dp[i][i][n - k] = (n - k) * (n - k);
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; i + j < n; j++)
            {
                for (int k = 1; k <= n - (i + j); k++)
                {
                    if (boxes[i + j] == boxes[i + j - 1])
                    {
                        dp[j][i + j][k] = dp[j][i + j - 1][k + 1];
                    }
                    else
                    {
                        dp[j][i + j][k] = dp[j][i + j - 1][1] + k * k;
                        for (int m = j; m < i + j; m++)
                        {
                            if (boxes[m] == boxes[i + j])
                            {
                                dp[j][i + j][k] = max(dp[j][i + j][k], dp[j][m][k + 1] + dp[m + 1][i + j - 1][1]);
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n - 1][1];
    }
};
// @lc code=end
