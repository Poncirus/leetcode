/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (52.37%)
 * Likes:    2294
 * Dislikes: 122
 * Total Accepted:    181.7K
 * Total Submissions: 338.6K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */

// @lc code=start
class Solution
{
public:
    struct numCompare
    {
        bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y)
        {
            return x.first > y.first;
        }
    };

    static int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, numCompare> minHeap;

        // put the 1st element of each row in the min heap
        // we don't need to push more than 'k' elements in the heap
        for (int i = 0; i < n && i < k; i++)
        {
            minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
        }

        // take the smallest element form the min heap, if the running count is equal to k return the number
        // if the row of the top element has more elements, add the next element to the heap
        int numberCount = 0, result = 0;
        while (!minHeap.empty())
        {
            auto heapTop = minHeap.top();
            minHeap.pop();
            result = heapTop.first;
            if (++numberCount == k)
            {
                break;
            }

            heapTop.second.second++;
            if (n > heapTop.second.second)
            {
                heapTop.first = matrix[heapTop.second.first][heapTop.second.second];
                minHeap.push(heapTop);
            }
        }
        return result;
    }
};
// @lc code=end
