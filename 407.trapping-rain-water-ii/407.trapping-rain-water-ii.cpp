/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 *
 * https://leetcode.com/problems/trapping-rain-water-ii/description/
 *
 * algorithms
 * Hard (40.74%)
 * Likes:    1230
 * Dislikes: 30
 * Total Accepted:    40.1K
 * Total Submissions: 96K
 * Testcase Example:  '[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]'
 *
 * Given an m x n matrix of positive integers representing the height of each
 * unit cell in a 2D elevation map, compute the volume of water it is able to
 * trap after raining.
 * 
 * Example:
 * 
 * 
 * Given the following 3x6 height map:
 * [
 * ⁠ [1,4,3,1,3,2],
 * ⁠ [3,2,1,3,2,4],
 * ⁠ [2,3,3,2,3,1]
 * ]
 * 
 * Return 4.
 * 
 * 
 * 
 * 
 * The above image represents the elevation map
 * [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.
 * 
 * 
 * 
 * 
 * 
 * After the rain, water is trapped between the blocks. The total volume of
 * water trapped is 4.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= m, n <= 110
 * 0 <= heightMap[i][j] <= 20000
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        if (heightMap.size() == 0)
            return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        int row = heightMap.size(), col = heightMap[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        int ans = 0, Max = INT_MIN;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!(i == 0 || i == row - 1 || j == 0 || j == col - 1))
                    continue;
                que.push(make_pair(heightMap[i][j], i * col + j));
                visited[i][j] = 1;
            }
        }
        vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!que.empty())
        {
            auto val = que.top();
            que.pop();
            int height = val.first, x = val.second / col, y = val.second % col;
            Max = max(Max, height);
            for (auto d : dir)
            {
                int x2 = x + d[0], y2 = y + d[1];
                if (x2 >= row || x2 < 0 || y2 < 0 || y2 >= col || visited[x2][y2])
                    continue;
                visited[x2][y2] = 1;
                if (heightMap[x2][y2] < Max)
                    ans += Max - heightMap[x2][y2];
                que.push(make_pair(heightMap[x2][y2], x2 * col + y2));
            }
        }
        return ans;
    }
};
// @lc code=end
