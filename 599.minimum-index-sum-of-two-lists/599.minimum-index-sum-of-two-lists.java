import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/*
 * @lc app=leetcode id=599 lang=java
 *
 * [599] Minimum Index Sum of Two Lists
 *
 * https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/
 *
 * algorithms
 * Easy (52.75%)
 * Likes:    951
 * Dislikes: 278
 * Total Accepted:    128.8K
 * Total Submissions: 244K
 * Testcase Example:  '["Shogun","Tapioca Express","Burger King","KFC"]\n' +
  '["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]'
 *
 * Suppose Andy and Doris want to choose a restaurant for dinner, and they both
 * have a list of favorite restaurants represented by strings.
 * 
 * You need to help them find out their common interest with the least list
 * index sum. If there is a choice tie between answers, output all of them with
 * no order requirement. You could assume there always exists an answer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 =
 * ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
 * Output: ["Shogun"]
 * Explanation: The only restaurant they both like is "Shogun".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 =
 * ["KFC","Shogun","Burger King"]
 * Output: ["Shogun"]
 * Explanation: The restaurant they both like and have the least index sum is
 * "Shogun" with index sum 1 (0+1).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 =
 * ["KFC","Burger King","Tapioca Express","Shogun"]
 * Output: ["KFC","Burger King","Tapioca Express","Shogun"]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 =
 * ["KNN","KFC","Burger King","Tapioca Express","Shogun"]
 * Output: ["KFC","Burger King","Tapioca Express","Shogun"]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: list1 = ["KFC"], list2 = ["KFC"]
 * Output: ["KFC"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= list1.length, list2.length <= 1000
 * 1 <= list1[i].length, list2[i].length <= 30
 * list1[i] and list2[i] consist of spaces ' ' and English letters.
 * All the stings of list1 are unique.
 * All the stings of list2 are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        List<String> res = new ArrayList<>();
        int sum = Integer.MAX_VALUE;

        HashMap<String, Integer> m = new HashMap<>();
        for (int i = 0; i < list1.length; i++) {
            m.put(list1[i], i);
        }

        for (int i = 0; i < list2.length; i++) {
            Integer index = m.get(list2[i]);
            if (index != null && index + i <= sum) {
                if (index + i < sum) {
                    res.clear();
                    sum = index + i;
                }
                res.add(list2[i]);
            }
        }

        return res.toArray(new String[0]);
    }
}
// @lc code=end

