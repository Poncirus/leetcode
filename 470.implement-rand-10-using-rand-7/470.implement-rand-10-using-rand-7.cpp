/*
 * @lc app=leetcode id=470 lang=cpp
 *
 * [470] Implement Rand10() Using Rand7()
 *
 * https://leetcode.com/problems/implement-rand10-using-rand7/description/
 *
 * algorithms
 * Medium (45.99%)
 * Likes:    425
 * Dislikes: 133
 * Total Accepted:    22.8K
 * Total Submissions: 49.4K
 * Testcase Example:  '1'
 *
 * Given a function rand7 which generates a uniform random integer in the range
 * 1 to 7, write a function rand10 which generates a uniform random integer in
 * the range 1 to 10.
 * 
 * Do NOT use system's Math.random().
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: [7]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2
 * Output: [8,4]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 3
 * Output: [8,1,10]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * rand7 is predefined.
 * Each testcase has one argument: n, the number of times that rand10 is
 * called.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * What is the expected value for the number of calls to rand7() function?
 * Could you minimize the number of calls to rand7()?
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution
{
public:
    int rand10()
    {
        int a = 7;
        while (a >= 7)
        {
            a = rand7();
        }

        int b = 7;
        while (b >= 6)
        {
            b = rand7();
        }

        if (a > 3)
        {
            return 5 + b;
        }

        return b;
    }
};
// @lc code=end
