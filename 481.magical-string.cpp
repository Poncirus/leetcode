/*
 * @lc app=leetcode id=481 lang=cpp
 *
 * [481] Magical String
 *
 * https://leetcode.com/problems/magical-string/description/
 *
 * algorithms
 * Medium (47.05%)
 * Likes:    109
 * Dislikes: 679
 * Total Accepted:    22.2K
 * Total Submissions: 46.9K
 * Testcase Example:  '1'
 *
 * 
 * A magical string S consists of only '1' and '2' and obeys the following
 * rules:
 * 
 * 
 * The string S is magical because concatenating the number of contiguous
 * occurrences of characters '1' and '2' generates the string S itself.
 * 
 * 
 * 
 * The first few elements of string S is the following:
 * S = "1221121221221121122……"
 * 
 * 
 * 
 * If we group the consecutive '1's and '2's in S, it will be:
 * 
 * 
 * 1   22  11  2  1  22  1  22  11  2  11  22 ......
 * 
 * 
 * and the occurrences of '1's or '2's in each group are:
 * 
 * 
 * 1   2       2    1   1    2     1    2     2    1    2    2 ......
 * 
 * 
 * 
 * You can see that the occurrence sequence above is the S itself. 
 * 
 * 
 * 
 * Given an integer N as input, return the number of '1's in the first N number
 * in the magical string S.
 * 
 * 
 * Note:
 * N will not exceed 100,000.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: 6
 * Output: 3
 * Explanation: The first 6 elements of magical string S is "12211" and it
 * contains three 1's, so return 3.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int magicalString(int n)
    {
        if (n == 0)
            return 0;
        if (n <= 3)
            return 1;
        string num = "122";
        int i = 2;
        int cnt_one = 1;
        int counter = 3;
        while (counter < n)
        {
            int times = num[i] - '0';
            char ch = (i % 2 == 0) ? '1' : '2';
            cnt_one += (i % 2 == 0) ? times : 0;
            string t(times, ch);
            num += t;
            counter += times;
            i++;
        }
        while (counter > n)
        {
            if (num[counter - 1] == '1')
            {
                cnt_one--;
            }
            counter--;
        }
        return cnt_one;
    }
};
// @lc code=end
