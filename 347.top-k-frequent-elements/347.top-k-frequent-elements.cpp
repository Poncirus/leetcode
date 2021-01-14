/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (59.05%)
 * Likes:    2918
 * Dislikes: 207
 * Total Accepted:    377.4K
 * Total Submissions: 627K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * It's guaranteed that the answer is unique, in other words the set of the top
 * k frequent elements is unique.
 * You can return the answer in any order.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int num : nums)
        {
            map[num]++;
        }

        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int, int>> pq;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > (int)map.size() - k)
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};
// @lc code=end
