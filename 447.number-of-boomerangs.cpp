/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (51.18%)
 * Likes:    396
 * Dislikes: 656
 * Total Accepted:    67.3K
 * Total Submissions: 130.2K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is
 * a tuple of points (i, j, k) such that the distance between i and j equals
 * the distance between i and k (the order of the tuple matters).
 * 
 * Find the number of boomerangs. You may assume that n will be at most 500 and
 * coordinates of points are all in the range [-10000, 10000] (inclusive).
 * 
 * Example:
 * 
 * 
 * Input:
 * [[0,0],[1,0],[2,0]]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int boomerangs = 0;

        for (int i = 0; i < points.size(); i++)
        {
            map<double, int> distances;
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }

                int xDist = abs(points[i][0] - points[j][0]);
                int yDist = abs(points[i][1] - points[j][1]);
                double distance = sqrt((double)((xDist * xDist) + (yDist * yDist)));

                distances[distance]++;
            }

            for (auto x : distances)
            {
                if (x.second > 1)
                {
                    boomerangs += x.second * (x.second - 1);
                }
            }
        }

        return boomerangs;
    }
};
// @lc code=end
