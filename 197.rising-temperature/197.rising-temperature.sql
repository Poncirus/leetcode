--
-- @lc app=leetcode id=197 lang=mysql
--
-- [197] Rising Temperature
--
-- https://leetcode.com/problems/rising-temperature/description/
--
-- database
-- Easy (41.07%)
-- Likes:    651
-- Dislikes: 285
-- Total Accepted:    173.9K
-- Total Submissions: 422.8K
-- Testcase Example:  '{"headers": {"Weather": ["Id", "RecordDate", "Temperature"]}, "rows": {"Weather": [[1, "2015-01-01", 10], [2, "2015-01-02", 25], [3, "2015-01-03", 20], [4, "2015-01-04", 30]]}}'
--
-- Table: Weather
-- 
-- 
-- +---------------+---------+
-- | Column Name   | Type    |
-- +---------------+---------+
-- | id            | int     |
-- | recordDate    | date    |
-- | temperature   | int     |
-- +---------------+---------+
-- id is the primary key for this table.
-- This table contains information about the temperature in a certain day.
-- 
-- 
-- 
-- 
-- Write an SQL query to find all dates' id with higher temperature compared to
-- its previous dates (yesterday).
-- 
-- Return the result table in any order.
-- 
-- The query result format is in the following example:
-- 
-- 
-- Weather
-- +----+------------+-------------+
-- | id | recordDate | Temperature |
-- +----+------------+-------------+
-- | 1  | 2015-01-01 | 10          |
-- | 2  | 2015-01-02 | 25          |
-- | 3  | 2015-01-03 | 20          |
-- | 4  | 2015-01-04 | 30          |
-- +----+------------+-------------+
-- 
-- Result table:
-- +----+
-- | id |
-- +----+
-- | 2  |
-- | 4  |
-- +----+
-- In 2015-01-02, temperature was higher than the previous day (10 -> 25).
-- In 2015-01-04, temperature was higher than the previous day (20 -> 30).
-- 
-- 
--

-- @lc code=start
# Write your MySQL query statement below
SELECT wt1.Id
FROM Weather wt1, Weather wt2
WHERE wt1.Temperature > wt2.Temperature AND 
      TO_DAYS(wt1.recordDate)-TO_DAYS(wt2.recordDate)=1
-- @lc code=end

