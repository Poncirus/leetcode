/*
 * @lc app=leetcode id=2 lang=golang
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}

	t := l1
	p := 0

	for l2 != nil || p != 0 {
		var i int
		if l2 == nil {
			i = 0
		} else {
			i = l2.Val
		}
		t.Val += i + p
		p = t.Val / 10
		t.Val %= 10

		if t.Next == nil && ((l2 != nil && l2.Next != nil) || p != 0) {
			t.Next = &ListNode{0, nil}
		}

		t = t.Next
		if l2 != nil {
			l2 = l2.Next
		}
	}

	return l1
}

// @lc code=end
