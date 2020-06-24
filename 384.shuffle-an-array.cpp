/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 *
 * https://leetcode.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (51.91%)
 * Likes:    504
 * Dislikes: 1015
 * Total Accepted:    123.8K
 * Total Submissions: 236K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * Shuffle a set of numbers without duplicates.
 * 
 * 
 * Example:
 * 
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 * 
 * // Shuffle the array [1,2,3] and return its result. Any permutation of
 * [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 * 
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 * 
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    vector<int> v;

public:
    Solution(vector<int> &nums)
    {
        v = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return v;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        if (v.size() <= 1)
            return v;

        vector<int> r(v);
        for (int i = 0; i < r.size() - 1; i++)
        {
            int ran = rand() % (r.size() - i) + i;
            int t = r[ran];
            r[ran] = r[i];
            r[i] = t;
        }

        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
