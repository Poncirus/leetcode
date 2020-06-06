/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 *
 * https://leetcode.com/problems/create-maximum-number/description/
 *
 * algorithms
 * Hard (26.43%)
 * Likes:    633
 * Dislikes: 214
 * Total Accepted:    37.7K
 * Total Submissions: 141.4K
 * Testcase Example:  '[3,4,6,5]\n[9,1,2,5,8,3]\n5'
 *
 * Given two arrays of length m and n with digits 0-9 representing two numbers.
 * Create the maximum number of length k <= m + n from digits of the two. The
 * relative order of the digits from the same array must be preserved. Return
 * an array of the k digits.
 * 
 * Note: You should try to optimize your time and space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * nums1 = [3, 4, 6, 5]
 * nums2 = [9, 1, 2, 5, 8, 3]
 * k = 5
 * Output:
 * [9, 8, 6, 5, 3]
 * 
 * Example 2:
 * 
 * 
 * Input:
 * nums1 = [6, 7]
 * nums2 = [6, 0, 4]
 * k = 5
 * Output:
 * [6, 7, 6, 0, 4]
 * 
 * Example 3:
 * 
 * 
 * Input:
 * nums1 = [3, 9]
 * nums2 = [8, 9]
 * k = 3
 * Output:
 * [9, 8, 9]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        return number(nums1, nums2, k, 0, 0, vector<int>{});
    }

    vector<int> number(vector<int> &nums1, vector<int> &nums2, int k, int p, int q, vector<int> cur)
    {
        if (k == 0)
            return cur;

        int maxo = nums1.size() + nums2.size() - p - q - k + 1;

        int pm = -1;
        int qm = -1;
        int pmp, qmp;

        for (int i = p; i < nums1.size() && i < p + maxo; i++)
        {
            if (nums1[i] > pm)
            {
                pmp = i;
                pm = nums1[i];
            }
        }

        for (int j = q; j < nums2.size() && j < q + maxo; j++)
        {
            if (nums2[j] > qm)
            {
                qmp = j;
                qm = nums2[j];
            }
        }

        if (pm > qm)
        {
            cur.push_back(pm);
            return number(nums1, nums2, k - 1, pmp + 1, q, cur);
        }
        else if (qm > pm)
        {
            cur.push_back(qm);
            return number(nums1, nums2, k - 1, p, qmp + 1, cur);
        }
        else
        {
            cur.push_back(pm);
            return max(number(nums1, nums2, k - 1, pmp + 1, q, cur), number(nums1, nums2, k - 1, p, qmp + 1, cur));
        }
    }
};
// @lc code=end
