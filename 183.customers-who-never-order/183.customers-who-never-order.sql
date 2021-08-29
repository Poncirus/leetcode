--
-- @lc app=leetcode id=183 lang=mysql
--
-- [183] Customers Who Never Order
--
-- https://leetcode.com/problems/customers-who-never-order/description/
--
-- database
-- Easy (59.53%)
-- Likes:    632
-- Dislikes: 60
-- Total Accepted:    260.6K
-- Total Submissions: 437.2K
-- Testcase Example:  '{"headers": {"Customers": ["Id", "Name"], "Orders": ["Id", "CustomerId"]}, "rows": {"Customers": [[1, "Joe"], [2, "Henry"], [3, "Sam"], [4, "Max"]], "Orders": [[1, 3], [2, 1]]}}'
--
-- Suppose that a website contains two tables, the Customers table and the
-- Orders table. Write a SQL query to find all customers who never order
-- anything.
-- 
-- Table: Customers.
-- 
-- 
-- +----+-------+
-- | Id | Name  |
-- +----+-------+
-- | 1  | Joe   |
-- | 2  | Henry |
-- | 3  | Sam   |
-- | 4  | Max   |
-- +----+-------+
-- 
-- 
-- Table: Orders.
-- 
-- 
-- +----+------------+
-- | Id | CustomerId |
-- +----+------------+
-- | 1  | 3          |
-- | 2  | 1          |
-- +----+------------+
-- 
-- 
-- Using the above tables as example, return the following:
-- 
-- 
-- +-----------+
-- | Customers |
-- +-----------+
-- | Henry     |
-- | Max       |
-- +-----------+
-- 
-- 
--

-- @lc code=start
# Write your MySQL query statement below
select c.Name as Customers
from Customers as c
left join
(select distinct CustomerId from Orders) as o
on c.Id = o.CustomerId
where o.CustomerId is null
-- @lc code=end

