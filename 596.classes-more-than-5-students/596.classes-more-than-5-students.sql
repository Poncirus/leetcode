--
-- @lc app=leetcode id=596 lang=mysql
--
-- [596] Classes More Than 5 Students
--
-- https://leetcode.com/problems/classes-more-than-5-students/description/
--
-- database
-- Easy (39.24%)
-- Likes:    337
-- Dislikes: 838
-- Total Accepted:    123.2K
-- Total Submissions: 313.9K
-- Testcase Example:  '{"headers": {"courses": ["student", "class"]}, "rows": {"courses": [["A", "Math"], ["B", "English"], ["C", "Math"], ["D", "Biology"], ["E", "Math"], ["F", "Computer"], ["G", "Math"], ["H", "Math"], ["I", "Math"]]}}'
--
-- There is a table courses with columns: student and class
-- 
-- Please list out all classes which have more than or equal to 5 students.
-- 
-- For example, the table:
-- 
-- 
-- +---------+------------+
-- | student | class      |
-- +---------+------------+
-- | A       | Math       |
-- | B       | English    |
-- | C       | Math       |
-- | D       | Biology    |
-- | E       | Math       |
-- | F       | Computer   |
-- | G       | Math       |
-- | H       | Math       |
-- | I       | Math       |
-- +---------+------------+
-- 
-- 
-- Should output:
-- 
-- 
-- +---------+
-- | class   |
-- +---------+
-- | Math    |
-- +---------+
-- 
-- 
-- 
-- 
-- Note:
-- The students should not be counted duplicate in each course.
-- 
--

-- @lc code=start
# Write your MySQL query statement below
select class
from courses
group by class
having count(distinct student) >= 5
-- @lc code=end

