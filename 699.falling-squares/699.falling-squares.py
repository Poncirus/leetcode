#
# @lc app=leetcode id=699 lang=python3
#
# [699] Falling Squares
#
# https://leetcode.com/problems/falling-squares/description/
#
# algorithms
# Hard (45.68%)
# Likes:    643
# Dislikes: 75
# Total Accepted:    29.4K
# Total Submissions: 64.3K
# Testcase Example:  '[[1,2],[2,3],[6,1]]'
#
# There are several squares being dropped onto the X-axis of a 2D plane.
# 
# You are given a 2D integer array positions where positions[i] = [lefti,
# sideLengthi] represents the i^th square with a side length of sideLengthi
# that is dropped with its left edge aligned with X-coordinate lefti.
# 
# Each square is dropped one at a time from a height above any landed squares.
# It then falls downward (negative Y direction) until it either lands on the
# top side of another square or on the X-axis. A square brushing the left/right
# side of another square does not count as landing on it. Once it lands, it
# freezes in place and cannot be moved.
# 
# After each square is dropped, you must record the height of the current
# tallest stack of squares.
# 
# Return an integer array ans where ans[i] represents the height described
# above after dropping the i^th square.
# 
# 
# Example 1:
# 
# 
# Input: positions = [[1,2],[2,3],[6,1]]
# Output: [2,5,5]
# Explanation:
# After the first drop, the tallest stack is square 1 with a height of 2.
# After the second drop, the tallest stack is squares 1 and 2 with a height of
# 5.
# After the third drop, the tallest stack is still squares 1 and 2 with a
# height of 5.
# Thus, we return an answer of [2, 5, 5].
# 
# 
# Example 2:
# 
# 
# Input: positions = [[100,100],[200,100]]
# Output: [100,100]
# Explanation:
# After the first drop, the tallest stack is square 1 with a height of 100.
# After the second drop, the tallest stack is either square 1 or square 2, both
# with heights of 100.
# Thus, we return an answer of [100, 100].
# Note that square 2 only brushes the right side of square 1, which does not
# count as landing on it.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= positions.length <= 1000
# 1 <= lefti <= 10^8
# 1 <= sideLengthi <= 10^6
# 
# 
#

# @lc code=start
class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        ans = []
        heights = {}
        for pos, side in positions:
            # finds nearby positions, if any
            left, right = pos, pos+side-1
            # compare to see if this block overlaps with L/R boundaries of existing blocks
            nearby = [key for key in heights.keys() if not (key[1] < pos or key[0] > right)]
            # finds height of block based on heights of existing and overlapping blocks
            if len(nearby) > 0:
                h = max(heights[key] for key in nearby) + side
            else:
                h = side
            # update the heights for left and right boundaries
            heights[(pos,right)] = h
            # add height to ans
            if len(ans) == 0:
                ans.append(h)
            else:
                ans.append(max(h,ans[-1]))
        return ans
# @lc code=end

