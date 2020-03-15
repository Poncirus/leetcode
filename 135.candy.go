/*
 * @lc app=leetcode id=135 lang=golang
 *
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (30.36%)
 * Likes:    740
 * Dislikes: 149
 * Total Accepted:    120.8K
 * Total Submissions: 397.6K
 * Testcase Example:  '[1,0,2]'
 *
 * There are N children standing in a line. Each child is assigned a rating
 * value.
 * 
 * You are giving candies to these children subjected to the following
 * requirements:
 * 
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * 
 * 
 * What is the minimum candies you must give?
 * 
 * Example 1:
 * 
 * 
 * Input: [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2,
 * 1, 2 candies respectively.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1,
 * 2, 1 candies respectively.
 * ⁠            The third child gets 1 candy because it satisfies the above two
 * conditions.
 * 
 * 
 */

// @lc code=start
func candy(ratings []int) int {
	if len(ratings) == 0 {
		return 0
	}

	res := 1
	line := 1

	lr := 1

	desc := func(i, n int) bool {
		for ;i < len(ratings) - 1 && n > 0; i++ {
			if ratings[i+1] >= ratings[i] {
				break
			}

			n--
		}

		return n != 0
	}

	for i := 1; i < len(ratings); i++ {
		if ratings[i] < ratings[i-1] {
			res += line + 1
			line++
			lr = 1
		} else if ratings[i] == ratings[i-1] {
			line = 1
			res += 1
			lr = 1
		} else {
			if i+1 >= len(ratings) || desc(i, lr) {
				lr++
				res += lr
				line = 0
			} else {
				line = 1
				res += 1
				lr = 1
			}
		}
	}

	return res
}
// @lc code=end

