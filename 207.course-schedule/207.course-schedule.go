/*
 * @lc app=leetcode id=207 lang=golang
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (40.91%)
 * Likes:    2972
 * Dislikes: 151
 * Total Accepted:    333.2K
 * Total Submissions: 813K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 1 <= numCourses <= 10^5
 * 
 * 
 */

// @lc code=start
func canFinish(numCourses int, prerequisites [][]int) bool {
	t := make([][]int, numCourses)
	for i := range t {
		t[i] = make([]int, 0)
	}

	for _, v := range prerequisites {
		t[v[1]] = append(t[v[1]], v[0])
	}

	b := make([]int, numCourses)

	var dfs func(int) bool
	dfs = func(i int) bool {
		if b[i] == 2 {
			return true
		}

		if b[i] == 1 {
			return false
		}

		b[i] = 1
		for _, v := range t[i] {
			if !dfs(v) {
				return false
			}
		}
		b[i] = 2
		return true
	}

	for i := range t {
		if !dfs(i) {
			return false
		}
	}

	return true
}
// @lc code=end

