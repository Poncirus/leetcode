/*
 * @lc app=leetcode id=148 lang=golang
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (39.66%)
 * Likes:    2206
 * Dislikes: 112
 * Total Accepted:    236.7K
 * Total Submissions: 595.6K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func sortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
		return head
	}

	divide := head.Val
	l1, l2 := &ListNode{}, &ListNode{}
	p1, p2 := l1, l2

	for p := head.Next; p != nil; p = p.Next {
		if p.Val <= divide {
			p1.Next = p
			p1 = p
		} else {
			p2.Next = p
			p2 = p
		}
	}

	p1.Next = nil
	p2.Next = head
	head.Next = nil

	l1 = sortList(l1.Next)
	l2 = sortList(l2.Next)

	if l1 == nil {
		return l2
	}

	p := l1
	for p.Next != nil {
		p = p.Next
	}
	p.Next = l2

	return l1
}
// @lc code=end

