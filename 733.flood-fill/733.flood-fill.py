#
# @lc app=leetcode id=733 lang=python3
#
# [733] Flood Fill
#
# https://leetcode.com/problems/flood-fill/description/
#
# algorithms
# Easy (65.84%)
# Likes:    8782
# Dislikes: 906
# Total Accepted:    1.1M
# Total Submissions: 1.7M
# Testcase Example:  '[[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2'
#
# You are given an image represented by an m x n grid of integers image, where
# image[i][j] represents the pixel value of the image. You are also given three
# integers sr, sc, and color. Your task is to perform a flood fill on the image
# starting from the pixel image[sr][sc].
# 
# To perform a flood fill:
# 
# 
# Begin with the starting pixel and change its color to color.
# Perform the same process for each pixel that is directly adjacent (pixels
# that share a side with the original pixel, either horizontally or vertically)
# and shares the same color as the starting pixel.
# Keep repeating this process by checking neighboring pixels of the updated
# pixels and modifying their color if it matches the original color of the
# starting pixel.
# The process stops when there are no more adjacent pixels of the original
# color to update.
# 
# 
# Return the modified image after performing the flood fill.
# 
# 
# Example 1:
# 
# 
# Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
# 
# Output: [[2,2,2],[2,2,0],[2,0,1]]
# 
# Explanation:
# 
# 
# 
# From the center of the image with position (sr, sc) = (1, 1) (i.e., the red
# pixel), all pixels connected by a path of the same color as the starting
# pixel (i.e., the blue pixels) are colored with the new color.
# 
# Note the bottom corner is not colored 2, because it is not horizontally or
# vertically connected to the starting pixel.
# 
# 
# Example 2:
# 
# 
# Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
# 
# Output: [[0,0,0],[0,0,0]]
# 
# Explanation:
# 
# The starting pixel is already colored with 0, which is the same as the target
# color. Therefore, no changes are made to the image.
# 
# 
# 
# Constraints:
# 
# 
# m == image.length
# n == image[i].length
# 1 <= m, n <= 50
# 0 <= image[i][j], color < 2^16
# 0 <= sr < m
# 0 <= sc < n
# 
# 
#

# @lc code=start
class Solution(object):
    def fill(self, image, sr, sc, color, cur):
        # If sr is less than 0 or greater equals to the length of image...
        # Or, If sc is less than 0 or greater equals to the length of image[0]...
        if sr < 0 or sr >= len(image) or sc < 0 or sc >= len(image[0]): return;
        # If image[sr][sc] is not equal to previous color...
        if cur != image[sr][sc]: return;
        # Update the image[sr][sc] as a color...
        image[sr][sc] = color;
        # Make four recursive calls to the function with (sr-1, sc), (sr+1, sc), (sr, sc-1) and (sr, sc+1)...
        self.fill(image, sr-1, sc, color, cur);
        self.fill(image, sr+1, sc, color, cur);
        self.fill(image, sr, sc-1, color, cur);
        self.fill(image, sr, sc+1, color, cur);
    def floodFill(self, image, sr, sc, color):
        # Avoid infinite loop if the new and old colors are the same...
        if image[sr][sc] == color: return image;
        # Run the fill function starting at the position given...
        self.fill(image, sr, sc, color, image[sr][sc]);
        return image;
        
        
# @lc code=end

