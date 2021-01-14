/*
 * @lc app=leetcode id=88 lang=golang
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
func merge(nums1 []int, m int, nums2 []int, n int) {
	m--
	n--
	for i := m + n + 1; i >= 0; i-- {
		if m < 0 {
			nums1[i] = nums2[n]
			n--
		} else if n < 0 {
			nums1[i] = nums1[m]
			m--
		} else if nums2[n] < nums1[m] {
			nums1[i] = nums1[m]
			m--
		} else {
			nums1[i] = nums2[n]
			n--
		}
	}
}

// @lc code=end
