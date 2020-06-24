/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 *
 * https://leetcode.com/problems/perfect-rectangle/description/
 *
 * algorithms
 * Hard (29.62%)
 * Likes:    358
 * Dislikes: 72
 * Total Accepted:    24.3K
 * Total Submissions: 80.7K
 * Testcase Example:  '[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]'
 *
 * Given N axis-aligned rectangles where N > 0, determine if they all together
 * form an exact cover of a rectangular region.
 * 
 * Each rectangle is represented as a bottom-left point and a top-right point.
 * For example, a unit square is represented as [1,1,2,2]. (coordinate of
 * bottom-left point is (1, 1) and top-right point is (2, 2)).
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * rectangles = [
 * ⁠ [1,1,3,3],
 * ⁠ [3,1,4,2],
 * ⁠ [3,2,4,4],
 * ⁠ [1,3,2,4],
 * ⁠ [2,3,3,4]
 * ]
 * 
 * Return true. All 5 rectangles together form an exact cover of a rectangular
 * region.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * rectangles = [
 * ⁠ [1,1,2,3],
 * ⁠ [1,3,2,4],
 * ⁠ [3,1,4,2],
 * ⁠ [3,2,4,4]
 * ]
 * 
 * Return false. Because there is a gap between the two rectangular
 * regions.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * rectangles = [
 * ⁠ [1,1,3,3],
 * ⁠ [3,1,4,2],
 * ⁠ [1,3,2,4],
 * ⁠ [3,2,4,4]
 * ]
 * 
 * Return false. Because there is a gap in the top center.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * rectangles = [
 * ⁠ [1,1,3,3],
 * ⁠ [3,1,4,2],
 * ⁠ [1,3,2,4],
 * ⁠ [2,2,4,4]
 * ]
 * 
 * Return false. Because two of the rectangles overlap with each other.
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    inline string getKey(int x, int y) { return to_string(x) + " " + to_string(y); }

public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        if (rectangles.empty() || rectangles[0].empty())
            return false;
        int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN, area = 0;
        unordered_set<string> s;
        for (auto v : rectangles)
        {
            x1 = min(x1, v[0]);
            y1 = min(y1, v[1]);
            x2 = max(x2, v[2]);
            y2 = max(y2, v[3]);
            area += (v[2] - v[0]) * (v[3] - v[1]);
            string a = getKey(v[0], v[1]), b = getKey(v[0], v[3]), c = getKey(v[2], v[1]), d = getKey(v[2], v[3]);
            if (!s.erase(a))
                s.insert(a);
            if (!s.erase(b))
                s.insert(b);
            if (!s.erase(c))
                s.insert(c);
            if (!s.erase(d))
                s.insert(d);
        }
        return s.count(getKey(x1, y1)) && s.count(getKey(x1, y2)) && s.count(getKey(x2, y1)) && s.count(getKey(x2, y2)) && s.size() == 4 && area == (x2 - x1) * (y2 - y1);
    }
};
// @lc code=end
