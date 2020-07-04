/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 *
 * https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/
 *
 * algorithms
 * Hard (27.99%)
 * Likes:    313
 * Dislikes: 52
 * Total Accepted:    12.4K
 * Total Submissions: 43.1K
 * Testcase Example:  '13\n2'
 *
 * Given integers n and k, find the lexicographically k-th smallest integer in
 * the range from 1 to n.
 * 
 * Note: 1 ≤ k ≤ n ≤ 10^9.
 * 
 * Example:
 * 
 * Input:
 * n: 13   k: 2
 * 
 * Output:
 * 10
 * 
 * Explanation:
 * The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so
 * the second smallest number is 10.
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int findKthNumber(int n, int k, int start = 0)
    {
        if (k > 0)
        {
            for (int i = (start == 0) ? 1 : 0; i <= 9; i++)
            { // append 0-9 to the prefix
                int count = numbersBeginWith(n, 10 * start + i);
                if (k <= count) // if k <= count, the answer is begin with the prefix
                    return findKthNumber(n, k - 1, 10 * start + i);
                k -= count; // if the answer does not begin with the prefix, remove all the numbers begin with this prefix
            }
        }
        return start;
    }

    // return how many numbers are begin with the prefix and in the range of N
    int numbersBeginWith(int n, long long prefix)
    {
        long long fac = 1;
        int count = 0;
        for (int digit = 1; digit <= 9; digit++)
        {
            long long min = prefix * fac;
            long long max = prefix * fac + fac - 1;
            if (n < min)
                break;
            else if (min <= n && n <= max)
            {
                count += (n - min + 1);
                break;
            }
            else
                count += fac;
            fac *= 10;
        }
        return count;
    }
};
// @lc code=end
