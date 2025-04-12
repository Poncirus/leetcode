#
# @lc app=leetcode id=749 lang=python3
#
# [749] Contain Virus
#
# https://leetcode.com/problems/contain-virus/description/
#
# algorithms
# Hard (52.19%)
# Likes:    406
# Dislikes: 460
# Total Accepted:    14.7K
# Total Submissions: 28.2K
# Testcase Example:  '[[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]'
#
# A virus is spreading rapidly, and your task is to quarantine the infected
# area by installing walls.
# 
# The world is modeled as an m x n binary grid isInfected, where
# isInfected[i][j] == 0 represents uninfected cells, and isInfected[i][j] == 1
# represents cells contaminated with the virus. A wall (and only one wall) can
# be installed between any two 4-directionally adjacent cells, on the shared
# boundary.
# 
# Every night, the virus spreads to all neighboring cells in all four
# directions unless blocked by a wall. Resources are limited. Each day, you can
# install walls around only one region (i.e., the affected area (continuous
# block of infected cells) that threatens the most uninfected cells the
# following night). There will never be a tie.
# 
# Return the number of walls used to quarantine all the infected regions. If
# the world will become fully infected, return the number of walls used.
# 
# 
# Example 1:
# 
# 
# Input: isInfected =
# [[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]
# Output: 10
# Explanation: There are 2 contaminated regions.
# On the first day, add 5 walls to quarantine the viral region on the left. The
# board after the virus spreads is:
# 
# On the second day, add 5 walls to quarantine the viral region on the right.
# The virus is fully contained.
# 
# 
# 
# Example 2:
# 
# 
# Input: isInfected = [[1,1,1],[1,0,1],[1,1,1]]
# Output: 4
# Explanation: Even though there is only one cell saved, there are 4 walls
# built.
# Notice that walls are only built on the shared boundary of two different
# cells.
# 
# 
# Example 3:
# 
# 
# Input: isInfected =
# [[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]]
# Output: 13
# Explanation: The region on the left only builds two new walls.
# 
# 
# 
# Constraints:
# 
# 
# m == isInfected.length
# n == isInfected[i].length
# 1 <= m, n <= 50
# isInfected[i][j] is either 0 or 1.
# There is always a contiguous viral region throughout the described process
# that will infect strictly more uncontaminated squares in the next round.
# 
# 
#

# @lc code=start
class Solution:
    def containVirus(self, mat: List[List[int]]) -> int:
        m,n = len(mat),len(mat[0])

        def dfs(i,j,visited,nextInfected):  # return no. of walls require to quarantined dfs area
            if 0<=i<m and 0<=j<n and (i,j) not in visited:
                if mat[i][j]==2: # Already quarantined cell
                    return 0
                if mat[i][j]==0:
                    nextInfected.add((i,j)) # add cell which will be infected next day
                    return 1   # require one wall to quarantined cell from one side
                    
                else:
                    visited.add((i,j))
                    return dfs(i-1,j,visited,nextInfected) + dfs(i+1,j,visited,nextInfected) + dfs(i,j-1,visited,nextInfected) + dfs(i,j+1,visited,nextInfected)  # traverse all four direction
            else:
                return 0
				
        ans = 0 
        while True:   # this loop running "how many days we should installing the walls" times
            # For every day check which area infect more cells
            visited = set()  # Using in dfs
            All_nextinfect  = set()
            stop , walls = set(),0   # here stop store the indices of maximum no. of cells in which we stop spreading of virus this day
            
            for i in range(m):
                for j in range(n):
                    if mat[i][j]==1 and (i,j) not in visited:
                        nextInfected = set()
                        a = dfs(i,j,visited,nextInfected)
                        
                        if len(stop)<len(nextInfected):
                            All_nextinfect  = All_nextinfect | stop # leave previous saved area from virus
                            stop = nextInfected  # pick new area which we want to save
                            walls = a  # require walls
                            p,q = i,j  # starting position(indices) of this area
                        else:
                            All_nextinfect  = All_nextinfect | nextInfected   
                            
            if not stop : # if our job is done i.e. No cell will be infect Later
                break
            ans += walls  # add new walls installed this day
            
            # change each cell value to 2 which will be covered by quarantined area
            def fun(p,q):
                if 0<=p<m and 0<=q<n and mat[p][q]==1:
                    mat[p][q]=2
                    fun(p+1,q)
                    fun(p-1,q)
                    fun(p,q-1)
                    fun(p,q+1)
            fun(p,q) # start dfs from start point of quarantined area
            
            for a,b in All_nextinfect: # set new infected cell value = 1 for iterating next day
                mat[a][b] = 1

        return ans   # Final answer
        
# @lc code=end

