/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 *
 * https://leetcode.com/problems/random-pick-with-weight/description/
 *
 * algorithms
 * Medium (43.42%)
 * Likes:    792
 * Dislikes: 2258
 * Total Accepted:    109.6K
 * Total Submissions: 249.6K
 * Testcase Example:  '["Solution","pickIndex"]\r\n[[[1]],[]]\r'
 *
 * Given an array w of positive integers, where w[i] describes the weight of
 * index i(0-indexed), write a function pickIndex which randomly picks an index
 * in proportion to its weight.
 * 
 * For example, given an input list of values w = [2, 8], when we pick up a
 * number out of it, the chance is that 8 times out of 10 we should pick the
 * number 1 as the answer since it's the second element of the array (w[1] =
 * 8).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["Solution","pickIndex"]
 * [[[1]],[]]
 * Output
 * [null,0]
 * 
 * Explanation
 * Solution solution = new Solution([1]);
 * solution.pickIndex(); // return 0. Since there is only one single element on
 * the array the only option is to return the first element.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input
 * ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
 * [[[1,3]],[],[],[],[],[]]
 * Output
 * [null,1,1,1,1,0]
 * 
 * Explanation
 * Solution solution = new Solution([1, 3]);
 * solution.pickIndex(); // return 1. It's returning the second element (index
 * = 1) that has probability of 3/4.
 * solution.pickIndex(); // return 1
 * solution.pickIndex(); // return 1
 * solution.pickIndex(); // return 1
 * solution.pickIndex(); // return 0. It's returning the first element (index =
 * 0) that has probability of 1/4.
 * 
 * Since this is a randomization problem, multiple answers are allowed so the
 * following outputs can be considered correct :
 * [null,1,1,1,1,0]
 * [null,1,1,1,1,1]
 * [null,1,1,1,0,0]
 * [null,1,1,1,0,1]
 * [null,1,0,1,0,0]
 * ......
 * and so on.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= w.length <= 10000
 * 1 <= w[i] <= 10^5
 * pickIndex will be called at most 10000 times.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    Solution(vector<int> &w)
    {
        int sum = 0;
        for (int i = 0; i < w.size(); i++)
        {
            sum += w[i];
            list.push_back(pair<int, int>{sum, i});
        }

        s = sum;
    }

    int pickIndex()
    {
        int pick = rand() % s;
        for (auto &p : list)
        {
            if (pick < p.first)
                return p.second;
        }

        return 0;
    }

    int s;
    vector<pair<int, int>> list;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
