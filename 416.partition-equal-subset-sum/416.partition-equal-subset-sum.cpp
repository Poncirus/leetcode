/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (42.38%)
 * Likes:    2501
 * Dislikes: 68
 * Total Accepted:    173.6K
 * Total Submissions: 400.8K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * Note:
 * 
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto p = nums.begin(); p != nums.end(); p++)
        {
            sum += *p;
        }

        if (sum % 2 != 0)
            return false;

        sum /= 2;

        map<int, bool> m;
        m[0] = true;

        for (auto p = nums.begin(); p != nums.end(); ++p)
        {
            vector<int> rec;
            for (auto q = m.begin(); q != m.end(); ++q)
            {
                if (q->first + *p == sum)
                    return true;

                if (q->first + *p < sum)
                    rec.push_back(q->first + *p);
            }

            for (auto q = rec.begin(); q != rec.end(); ++q)
            {
                m[*q] = true;
            }
        }

        return false;
    }
};
// @lc code=end
