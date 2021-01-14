/*
 * @lc app=leetcode id=215 lang=golang
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (52.60%)
 * Likes:    3152
 * Dislikes: 222
 * Total Accepted:    553.6K
 * Total Submissions: 1M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

// @lc code=start
func findKthLargest(nums []int, k int) int {
	t := make([]int, k)
	for i := range t {
		t[i] = math.MinInt64
	}

	for _, v := range nums {
		if v > t[k-1] {
			i := k - 1
			for ; i > 0; i-- {
				if v < t[i-1] {
					break
				}

				t[i] = t[i-1]
			}

			t[i] = v
		}
	}

	return t[k-1]
}
// @lc code=end

