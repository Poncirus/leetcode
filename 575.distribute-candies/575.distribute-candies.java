import java.util.HashSet;
import java.util.Set;

/*
 * @lc app=leetcode id=575 lang=java
 *
 * [575] Distribute Candies
 */

// @lc code=start
class Solution {
    public int distributeCandies(int[] candyType) {
        HashSet<Integer> types = new HashSet<>(); 
        for (int i : candyType) {
            types.add(i);
        }

        return Integer.min(types.size(), candyType.length/2);
    }
}
// @lc code=end

