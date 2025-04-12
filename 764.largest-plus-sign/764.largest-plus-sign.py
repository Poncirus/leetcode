#
# @lc app=leetcode id=764 lang=python3
#
# [764] Largest Plus Sign
#
# https://leetcode.com/problems/largest-plus-sign/description/
#
# algorithms
# Medium (48.56%)
# Likes:    1503
# Dislikes: 238
# Total Accepted:    63.5K
# Total Submissions: 130.9K
# Testcase Example:  '5\n[[4,2]]'
#
# You are given an integer n. You have an n x n binary grid grid with all
# values initially 1's except for some indices given in the array mines. The
# i^th element of the array mines is defined as mines[i] = [xi, yi] where
# grid[xi][yi] == 0.
# 
# Return the order of the largest axis-aligned plus sign of 1's contained in
# grid. If there is none, return 0.
# 
# An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1
# along with four arms of length k - 1 going up, down, left, and right, and
# made of 1's. Note that there could be 0's or 1's beyond the arms of the plus
# sign, only the relevant area of the plus sign is checked for 1's.
# 
# 
# Example 1:
# 
# 
# Input: n = 5, mines = [[4,2]]
# Output: 2
# Explanation: In the above grid, the largest plus sign can only be of order 2.
# One of them is shown.
# 
# 
# Example 2:
# 
# 
# Input: n = 1, mines = [[0,0]]
# Output: 0
# Explanation: There is no plus sign, so return 0.
# 
# 
# 
# Constraints:
# 
# 
# 1 <= n <= 500
# 1 <= mines.length <= 5000
# 0 <= xi, yi < n
# All the pairs (xi, yi) are unique.
# 
# 
#

# @lc code=start
class Solution:
    def orderOfLargestPlusSign(self, N, mines):
        """
        :type N: int
        :type mines: List[List[int]]
        :rtype: int
        """
        grid = [[N] * N for i in range(N)]
            
        for m in mines:
            grid[m[0]][m[1]] = 0
                
        for i in range(N):
            l, r, u, d = 0, 0, 0, 0
                
            for j, k in zip(range(N), reversed(range(N))):
                l = l + 1 if grid[i][j] != 0 else 0
                if l < grid[i][j]:
                    grid[i][j] = l
                
                r = r + 1 if grid[i][k] != 0 else 0
                if r < grid[i][k]:
                    grid[i][k] = r

                u = u + 1 if grid[j][i] != 0 else 0
                if u < grid[j][i]:
                    grid[j][i] = u
                    
                d = d + 1 if grid[k][i] != 0 else 0
                if d < grid[k][i]:
                    grid[k][i] = d
            
        res = 0
            
        for i in range(N):
            for j in range(N):
                if res < grid[i][j]:
                    res = grid[i][j]
                    
        return res
        
# @lc code=end

