/*
 * @lc app=leetcode id=27 lang=golang
 *
 * [27] Remove Element
 */
func removeElement(nums []int, val int) int {
	n := 0
    for i := 0; i < len(nums); i++ {
		if nums[i] != val {
			nums[n] = nums[i]
			n++
		}
	}

	return n
}

