/*
 * @lc app=leetcode id=26 lang=golang
 *
 * [26] Remove Duplicates from Sorted Array
 */
func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	h := nums[0]
	n := 1

	for i := 1; i < len(nums); i++ {
		if nums[i] > h {
			nums[n] = nums[i]
			h = nums[n]
			n++
		}
	}

	return n
}

