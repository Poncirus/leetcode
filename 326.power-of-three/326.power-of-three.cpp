/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (41.92%)
 * Likes:    480
 * Dislikes: 1422
 * Total Accepted:    252.3K
 * Total Submissions: 600.9K
 * Testcase Example:  '27'
 *
 * Given an integer, write a function to determine if it is a power of three.
 * 
 * Example 1:
 * 
 * 
 * Input: 27
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: 9
 * Output: true
 * 
 * Example 4:
 * 
 * 
 * Input: 45
 * Output: false
 * 
 * Follow up:
 * Could you do it without using any loop / recursion?
 */

// @lc code=start
class Solution
{
public:
    int const Max3PowerInt = 1162261467; // 3^19, 3^20 = 3486784401 > MaxInt32
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;
        return Max3PowerInt % n == 0;
    }
};
// @lc code=end
