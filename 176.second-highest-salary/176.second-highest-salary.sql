--
-- @lc app=leetcode id=176 lang=mysql
--
-- [176] Second Highest Salary
--
-- https://leetcode.com/problems/second-highest-salary/description/
--
-- database
-- Easy (30.17%)
-- Likes:    674
-- Dislikes: 375
-- Total Accepted:    195.1K
-- Total Submissions: 645.2K
-- Testcase Example:  '{"headers": {"Employee": ["Id", "Salary"]}, "rows": {"Employee": [[1, 100], [2, 200], [3, 300]]}}'
--
-- Write a SQL query to get the second highest salary from the Employee
-- table.
-- 
-- 
-- +----+--------+
-- | Id | Salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+
-- 
-- 
-- For example, given the above Employee table, the query should return 200 as
-- the second highest salary. If there is no second highest salary, then the
-- query should return null.
-- 
-- 
-- +---------------------+
-- | SecondHighestSalary |
-- +---------------------+
-- | 200                 |
-- +---------------------+
-- 
-- 
--

-- @lc code=start
# Write your MySQL query statement below
SELECT (
    SELECT DISTINCT Salary
    FROM Employee
    ORDER BY Salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary
-- @lc code=end

