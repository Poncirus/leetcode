import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=638 lang=java
 *
 * [638] Shopping Offers
 *
 * https://leetcode.com/problems/shopping-offers/description/
 *
 * algorithms
 * Medium (53.97%)
 * Likes:    872
 * Dislikes: 576
 * Total Accepted:    41.7K
 * Total Submissions: 77.2K
 * Testcase Example:  '[2,5]\n[[3,0,5],[1,2,10]]\n[3,2]'
 *
 * In LeetCode Store, there are n items to sell. Each item has a price.
 * However, there are some special offers, and a special offer consists of one
 * or more different kinds of items with a sale price.
 * 
 * You are given an integer array price where price[i] is the price of the i^th
 * item, and an integer array needs where needs[i] is the number of pieces of
 * the i^th item you want to buy.
 * 
 * You are also given an array special where special[i] is of size n + 1 where
 * special[i][j] is the number of pieces of the j^th item in the i^th offer and
 * special[i][n] (i.e., the last integer in the array) is the price of the i^th
 * offer.
 * 
 * Return the lowest price you have to pay for exactly certain items as given,
 * where you could make optimal use of the special offers. You are not allowed
 * to buy more items than you want, even if that would lower the overall price.
 * You could use any of the special offers as many times as you want.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
 * Output: 14
 * Explanation: There are two kinds of items, A and B. Their prices are $2 and
 * $5 respectively. 
 * In special offer 1, you can pay $5 for 3A and 0B
 * In special offer 2, you can pay $10 for 1A and 2B. 
 * You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer
 * #2), and $4 for 2A.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]
 * Output: 11
 * Explanation: The price of A is $2, and $3 for B, $4 for C. 
 * You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
 * You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special
 * offer #1), and $3 for 1B, $4 for 1C. 
 * You cannot add more items, though only $9 for 2A ,2B and 1C.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == price.length
 * n == needs.length
 * 1 <= n <= 6
 * 0 <= price[i] <= 10
 * 0 <= needs[i] <= 10
 * 1 <= special.length <= 100
 * special[i].length == n + 1
 * 0 <= special[i][j] <= 50
 * 
 * 
 */

// @lc code=start
class Solution {

    private List<Integer> price;
    List<List<Integer>> special;
    

    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        this.price = price;
        this.special = special;

        return recursion(needs, 0);
    }

    private int recursion(List<Integer> needs, int spIdx) {
        int res = 0;
        for (int i = 0; i < needs.size(); i++) {
            res += price.get(i) * needs.get(i);
        }

        if (spIdx == special.size()) {
            return res;
        }

        List<Integer> sp = special.get(spIdx);
        for (int i = 0; true; i++) {
            List<Integer> n = new ArrayList<>();
            for (int j = 0; j < needs.size(); j++) {
                int t = needs.get(j) - sp.get(j) * i;
                if (t < 0) {
                    n = null;
                    break;
                }
                n.add(t);
            }

            if (n == null) {
                break;
            }

            res = Math.min(res, sp.get(needs.size()) * i + recursion(n, spIdx + 1));
        }

        return res;
    }
}
// @lc code=end

