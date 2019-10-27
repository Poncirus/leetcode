/*
 * @lc app=leetcode id=83 lang=golang
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	i := head

	for i != nil {
		j := i.Next
		for j != nil && i.Val == j.Val {
			j = j.Next
		}

		i.Next = j
		i = j
	}

	return head
}

// @lc code=end
