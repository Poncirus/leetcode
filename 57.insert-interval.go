/*
 * @lc app=leetcode id=57 lang=golang
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (32.47%)
 * Likes:    1273
 * Dislikes: 146
 * Total Accepted:    220K
 * Total Submissions: 676.1K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
func insert(intervals [][]int, newInterval []int) [][]int {
	if len(intervals) == 0 {
		return [][]int{newInterval}
	}

	if newInterval[1] < intervals[0][0] {
		i := [][]int{newInterval}
		return append(i, intervals...)
	}

	if newInterval[0] > intervals[len(intervals)-1][1] {
		return append(intervals, newInterval)
	}

	p1, p2 := -1, -1
    for i, v := range intervals {
		if v[1] >= newInterval[0] {
			if v[0] > newInterval[1] {
				r := make([][]int, len(intervals)+1)
				copy(r[0:i], intervals[0:i])
				r[i] = newInterval
				copy(r[i+1:], intervals[i:])
				return r
			}

			p1 = i
			if newInterval[0] > v[0] {
				newInterval[0] = v[0]
			}
			break
		}
	}

	for i := p1; i <= len(intervals); i++ {
		if i == len(intervals) || intervals[i][0] > newInterval[1] {
			p2 = i 

			if newInterval[1] < intervals[i-1][1] {
				newInterval[1] = intervals[i-1][1]
			}

			break
		}
	}

	var r [][]int
	r = append(r, intervals[:p1]...)
	r = append(r, newInterval)
	r = append(r, intervals[p2:]...)
	return r
}
// @lc code=end

