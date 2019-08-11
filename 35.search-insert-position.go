/*
 * @lc app=leetcode id=35 lang=golang
 *
 * [35] Search Insert Position
 */
func searchInsert(nums []int, target int) int {
	index := 0
    for ; index < len(nums); index++ {
		if target <= nums[index] {
			break
		}
	}

	return index
}

