/*
 * @lc app=leetcode id=4 lang=golang
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	i, p := 0, 0
	j, q := len(nums1)-1, len(nums2)-1

	for (j-i)+(q-p) > 0 {
		if j-i == -1 || i >= len(nums1) {
			p++
		} else if q-p == -1 || p >= len(nums2) {
			i++
		} else {
			if nums1[i] < nums2[p] {
				i++
			} else {
				p++
			}
		}

		if j-i == -1 || j < 0 {
			q--
		} else if q-p == -1 || q < 0 {
			j--
		} else {
			if nums1[j] > nums2[q] {
				j--
			} else {
				q--
			}
		}
	}

	r := 0
	t := 0
	for i <= j {
		r += nums1[i]
		i++
		t++
	}

	for p <= q {
		r += nums2[p]
		p++
		t++
	}

	return float64(r) / float64(t)
}

// @lc code=end
