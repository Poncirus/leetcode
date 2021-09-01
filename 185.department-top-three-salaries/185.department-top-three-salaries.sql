--
-- @lc app=leetcode id=185 lang=mysql
--
-- [185] Department Top Three Salaries
--
-- https://leetcode.com/problems/department-top-three-salaries/description/
--
-- database
-- Hard (42.59%)
-- Likes:    845
-- Dislikes: 168
-- Total Accepted:    129.1K
-- Total Submissions: 301.7K
-- Testcase Example:  '{"headers": {"Employee": ["Id", "Name", "Salary", "DepartmentId"], "Department": ["Id", "Name"]}, "rows": {"Employee": [[1, "Joe", 85000, 1], [2, "Henry", 80000, 2], [3, "Sam", 60000, 2], [4, "Max", 90000, 1], [5, "Janet", 69000, 1], [6, "Randy", 85000, 1], [7, "Will", 70000, 1]], "Department": [[1, "IT"], [2, "Sales"]]}}'
--
-- Table: Employee
--
--
-- +--------------+---------+
-- | Column Name  | Type    |
-- +--------------+---------+
-- | Id           | int     |
-- | Name         | varchar |
-- | Salary       | int     |
-- | DepartmentId | int     |
-- +--------------+---------+
-- Id is the primary key for this table.
-- Each row contains the ID, name, salary, and department of one employee.
--
--
--
--
-- Table: Department
--
--
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | Id          | int     |
-- | Name        | varchar |
-- +-------------+---------+
-- Id is the primary key for this table.
-- Each row contains the ID and the name of one department.
--
--
--
--
-- A company's executives are interested in seeing who earns the most money in
-- each of the company's departments. A high earner in a department is an
-- employee who has a salary in the top three unique salaries for that
-- department.
--
-- Write an SQL query to find the employees who are high earners in each of the
-- departments.
--
-- Return the result table in any order.
--
-- The query result format is in the following example:
--
--
--
--
-- Employee table:
-- +----+-------+--------+--------------+
-- | Id | Name  | Salary | DepartmentId |
-- +----+-------+--------+--------------+
-- | 1  | Joe   | 85000  | 1            |
-- | 2  | Henry | 80000  | 2            |
-- | 3  | Sam   | 60000  | 2            |
-- | 4  | Max   | 90000  | 1            |
-- | 5  | Janet | 69000  | 1            |
-- | 6  | Randy | 85000  | 1            |
-- | 7  | Will  | 70000  | 1            |
-- +----+-------+--------+--------------+
--
-- Department table:
-- +----+-------+
-- | Id | Name  |
-- +----+-------+
-- | 1  | IT    |
-- | 2  | Sales |
-- +----+-------+
--
-- Result table:
-- +------------+----------+--------+
-- | Department | Employee | Salary |
-- +------------+----------+--------+
-- | IT         | Max      | 90000  |
-- | IT         | Joe      | 85000  |
-- | IT         | Randy    | 85000  |
-- | IT         | Will     | 70000  |
-- | Sales      | Henry    | 80000  |
-- | Sales      | Sam      | 60000  |
-- +------------+----------+--------+
--
-- In the IT department:
-- - Max earns the highest unique salary
-- - Both Randy and Joe earn the second-highest unique salary
-- - Will earns the third-highest unique salary
--
-- In the Sales department:
-- - Henry earns the highest salary
-- - Sam earns the second-highest salary
-- - There is no third-highest salary as there are only two employees
--
--
-- @lc code=start
# Write your MySQL query statement below
select
  d.Name Department,
  e1.Name Employee,
  e1.Salary
from
  Employee e1
  join Department d on e1.DepartmentId = d.Id
where
  3 > (
    select
      count(distinct(e2.Salary))
    from
      Employee e2
    where
      e2.Salary > e1.Salary
      and e1.DepartmentId = e2.DepartmentId
  );
-- @lc code=end