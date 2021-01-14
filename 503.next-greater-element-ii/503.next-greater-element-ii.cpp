/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (54.08%)
 * Likes:    1508
 * Dislikes: 69
 * Total Accepted:    95.7K
 * Total Submissions: 170.1K
 * Testcase Example:  '[1,2,1]'
 *
 * 
 * Given a circular array (the next element of the last element is the first
 * element of the array), print the Next Greater Number for every element. The
 * Next Greater Number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, output -1 for this
 * number.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; The number 2 can't find
 * next greater number; The second 1's next greater number needs to search
 * circularly, which is also 2.
 * 
 * 
 * 
 * Note:
 * The length of given array won't exceed 10000.
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> res(nums.size(), -1);
        stack<int> s;
        stack<size_t> p;

        for (size_t i = 0; i < nums.size(); i++)
        {
            while (!s.empty() && nums[i] > s.top())
            {
                res[p.top()] = nums[i];
                p.pop();
                s.pop();
            }

            s.push(nums[i]);
            p.push(i);
        }

        for (size_t i = 0; i < nums.size() && !s.empty(); i++)
        {
            while (!s.empty() && nums[i] > s.top())
            {
                res[p.top()] = nums[i];
                p.pop();
                s.pop();
            }
        }

        return res;
    }
};
// @lc code=end
