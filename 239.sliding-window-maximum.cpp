/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (40.89%)
 * Likes:    3076
 * Dislikes: 166
 * Total Accepted:    252.7K
 * Total Submissions: 599.7K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Return the max sliding window.
 * 
 * Follow up:
 * Could you solve it in linear time?
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7] 
 * Explanation: 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int size = nums.size();
        if (k <= 1)
            return nums;

        int g = k - 1;

        vector<int> left;
        for (int i = 0; i < size; i++)
        {
            if (i % g == 0)
            {
                left.push_back(nums[i]);
            }
            else
            {
                left.push_back(nums[i] > left[i - 1] ? nums[i] : left[i - 1]);
            }
        }

        vector<int> right;
        right.resize(size);
        right[size - 1] = nums[size - 1];
        for (int j = size - 2; j >= 0; j--)
        {
            if ((j + 1) % g == 0)
            {
                right[j] = nums[j];
            }
            else
            {
                right[j] = nums[j] > right[j + 1] ? nums[j] : right[j + 1];
            }
        }

        vector<int> res;
        for (int i = 0; i <= size - k; i++)
        {
            res.push_back(right[i] > left[i + k - 1] ? right[i] : left[i + k - 1]);
        }

        return res;
    }
};
// @lc code=end
