/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (39.58%)
 * Likes:    1215
 * Dislikes: 241
 * Total Accepted:    73.8K
 * Total Submissions: 181.4K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * Given an m x n matrix of non-negative integers representing the height of
 * each unit cell in a continent, the "Pacific ocean" touches the left and top
 * edges of the matrix and the "Atlantic ocean" touches the right and bottom
 * edges.
 * 
 * Water can only flow in four directions (up, down, left, or right) from a
 * cell to another one with height equal or lower.
 * 
 * Find the list of grid coordinates where water can flow to both the Pacific
 * and Atlantic ocean.
 * 
 * Note:
 * 
 * 
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given the following 5x5 matrix:
 * 
 * ⁠ Pacific ~   ~   ~   ~   ~ 
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * Atlantic
 * 
 * Return:
 * 
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
 * parentheses in above matrix).
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    void BFS(vector<vector<bool>> &visited, queue<pair<int, int>> &q, vector<vector<int>> &grid)
    {
        int R[4] = {0, -1, 0, 1};
        int C[4] = {-1, 0, 1, 0};
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            for (int k = 0; k < 4; k++)
            {
                int x = i + R[k], y = j + C[k];
                if (x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size() and !visited[x][y] and grid[x][y] >= grid[i][j])
                {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        vector<vector<int>> res;
        if (!matrix.size())
            return res;
        vector<vector<bool>> vpac(matrix.size(), vector<bool>(matrix[0].size()));
        vector<vector<bool>> vatl(matrix.size(), vector<bool>(matrix[0].size()));
        queue<pair<int, int>> qpac;
        queue<pair<int, int>> qatl;
        for (int i = 0; i < matrix.size(); i++)
        {
            vpac[i][0] = true;
            qpac.push({i, 0});
            vatl[i][matrix[0].size() - 1] = true;
            qatl.push({i, matrix[0].size() - 1});
        }
        for (int j = 0; j < matrix[0].size(); j++)
        {
            vpac[0][j] = true;
            qpac.push({0, j});
            vatl[matrix.size() - 1][j] = true;
            qatl.push({matrix.size() - 1, j});
        }
        BFS(vpac, qpac, matrix);
        BFS(vatl, qatl, matrix);
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (vpac[i][j] and vatl[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};
// @lc code=end
