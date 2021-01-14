/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (38.05%)
 * Likes:    2819
 * Dislikes: 340
 * Total Accepted:    394.6K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head, *pre = NULL, *nxt;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            nxt = slow->next;
            slow->next = pre;
            pre = slow;
            slow = nxt;
        }
        if (fast)
            slow = slow->next;
        while (slow)
        {
            if (slow->val != pre->val)
                return false;
            slow = slow->next;
            pre = pre->next;
        }
        return true;
    }
};
// @lc code=end
