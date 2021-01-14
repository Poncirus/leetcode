/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (35.47%)
 * Likes:    1305
 * Dislikes: 96
 * Total Accepted:    99K
 * Total Submissions: 272.8K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k.
 * 
 * Define a pair (u,v) which consists of one element from the first array and
 * one element from the second array.
 * 
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * Output: [[1,2],[1,4],[1,6]] 
 * Explanation: The first 3 pairs are returned from the sequence: 
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * Output: [1,1],[1,1]
 * Explanation: The first 2 pairs are returned from the sequence: 
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [1,2], nums2 = [3], k = 3
 * Output: [1,3],[2,3]
 * Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
 * 
 * 
 */

// @lc code=start
typedef pair<int, int> ip;
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans;
        if (nums2.empty() || nums1.empty())
            return ans;
        auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b) {
            return (nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]);
        };
        priority_queue<ip, vector<ip>, decltype(cmp)> PQ(cmp);
        PQ.push({0, 0});
        while (!PQ.empty() && k--)
        {
            pair<int, int> P = PQ.top();
            int x = P.first;
            int y = P.second;
            PQ.pop();
            ans.push_back({nums1[x], nums2[y]});
            if (x < nums1.size() - 1)
                PQ.push({x + 1, y});
            if (x == 0 && y < nums2.size() - 1)
                PQ.push({x, y + 1});
        }
        return ans;
    }
};
// @lc code=end
