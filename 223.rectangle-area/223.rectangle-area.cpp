/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 *
 * https://leetcode.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (37.12%)
 * Likes:    366
 * Dislikes: 668
 * Total Accepted:    102.4K
 * Total Submissions: 274.5K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * 
 * Each rectangle is defined by its bottom left corner and top right corner as
 * shown in the figure.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
 * Output: 45
 * 
 * Note:
 * 
 * Assume that the total area is never beyond the maximum possible value of
 * int.
 * 
 */

// @lc code=start
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        long ans = (long)area(A, B, C, D) + (long)area(E, F, G, H) - (long)area(max(A, E), max(B, F), min(C, G), min(D, H));
        return ans;
    }

    int area(int A, int B, int C, int D)
    {
        return edge(A, C) * edge(B, D);
    }

    long edge(long A, long C)
    {
        return max(0, C-A);
    }

    long max(long a, long b)
    {
        return a > b ? a : b;
    }

    long min(long a, long b)
    {
        return a < b ? a : b;
    }
};
// @lc code=end

