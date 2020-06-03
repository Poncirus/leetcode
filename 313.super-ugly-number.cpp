/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 *
 * https://leetcode.com/problems/super-ugly-number/description/
 *
 * algorithms
 * Medium (43.77%)
 * Likes:    563
 * Dislikes: 137
 * Total Accepted:    74.6K
 * Total Submissions: 168.1K
 * Testcase Example:  '12\n[2,7,13,19]'
 *
 * Write a program to find the n^th super ugly number.
 * 
 * Super ugly numbers are positive numbers whose all prime factors are in the
 * given prime list primes of size k.
 * 
 * Example:
 * 
 * 
 * Input: n = 12, primes = [2,7,13,19]
 * Output: 32 
 * Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first
 * 12 
 * ⁠            super ugly numbers given primes = [2,7,13,19] of size 4.
 * 
 * Note:
 * 
 * 
 * 1 is a super ugly number for any given primes.
 * The given numbers in primes are in ascending order.
 * 0 < k ≤ 100, 0 < n ≤ 10^6, 0 < primes[i] < 1000.
 * The n^th super ugly number is guaranteed to fit in a 32-bit signed integer.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
        ugly[0] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < primes.size(); j++)
                ugly[i] = min(ugly[i], ugly[index[j]] * primes[j]);
            for (int j = 0; j < primes.size(); j++)
                index[j] += (ugly[i] == ugly[index[j]] * primes[j]);
        }
        return ugly[n - 1];
    }
};
// @lc code=end
