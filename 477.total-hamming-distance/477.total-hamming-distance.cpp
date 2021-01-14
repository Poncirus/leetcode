/*
 * @lc app=leetcode id=477 lang=cpp
 *
 * [477] Total Hamming Distance
 *
 * https://leetcode.com/problems/total-hamming-distance/description/
 *
 * algorithms
 * Medium (50.18%)
 * Likes:    857
 * Dislikes: 54
 * Total Accepted:    63.3K
 * Total Submissions: 125.5K
 * Testcase Example:  '[4,14,2]'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Now your job is to find the total Hamming distance between all pairs of the
 * given numbers.
 * 
 * 
 * Example:
 * 
 * Input: 4, 14, 2
 * 
 * Output: 6
 * 
 * Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is
 * 0010 (just
 * showing the four bits relevant in this case). So the answer will be:
 * HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2
 * + 2 + 2 = 6.
 * 
 * 
 * 
 * Note:
 * 
 * Elements of the given array are in the range of 0  to 10^9
 * Length of the array will not exceed 10^4. 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        vector<int> st;
        for (auto p = nums.begin(); p < nums.end(); ++p)
        {
            for (int i = 0; 1 << i <= *p; ++i)
            {
                if (st.size() < i + 1)
                    st.push_back(0);

                if (*p & 1 << i)
                {
                    st[i]++;
                }
            }
        }

        int res = 0;
        int size = nums.size();
        for (auto p = st.begin(); p < st.end(); ++p)
        {
            res += *p * (size - *p);
        }

        return res;
    }
};
// @lc code=end
