/*
 * @lc app=leetcode id=630 lang=java
 *
 * [630] Course Schedule III
 *
 * https://leetcode.com/problems/course-schedule-iii/description/
 *
 * algorithms
 * Hard (35.21%)
 * Likes:    1632
 * Dislikes: 49
 * Total Accepted:    49.9K
 * Total Submissions: 141.5K
 * Testcase Example:  '[[100,200],[200,1300],[1000,1250],[2000,3200]]'
 *
 * There are n different online courses numbered from 1 to n. You are given an
 * array courses where courses[i] = [durationi, lastDayi] indicate that the
 * i^th course should be taken continuously for durationi days and must be
 * finished before or on lastDayi.
 * 
 * You will start on the 1^st day and you cannot take two or more courses
 * simultaneously.
 * 
 * Return the maximum number of courses that you can take.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
 * Output: 3
 * Explanation: 
 * There are totally 4 courses, but you can take 3 courses at most:
 * First, take the 1^st course, it costs 100 days so you will finish it on the
 * 100^th day, and ready to take the next course on the 101^st day.
 * Second, take the 3^rd course, it costs 1000 days so you will finish it on
 * the 1100^th day, and ready to take the next course on the 1101^st day. 
 * Third, take the 2^nd course, it costs 200 days so you will finish it on the
 * 1300^th day. 
 * The 4^th course cannot be taken now, since you will finish it on the 3300^th
 * day, which exceeds the closed date.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: courses = [[1,2]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: courses = [[3,2],[4,3]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= courses.length <= 10^4
 * 1 <= durationi, lastDayi <= 10^4
 * 
 * 
 */

// @lc code=start
public class Solution {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses,(a,b)->a[1]-b[1]); //Sort the courses by their deadlines (Greedy! We have to deal with courses with early deadlines first)
        PriorityQueue<Integer> pq=new PriorityQueue<>((a,b)->b-a);
        int time=0;
        for (int[] c:courses) 
        {
            time+=c[0]; // add current course to a priority queue
            pq.add(c[0]);
            if (time>c[1]) time-=pq.poll(); //If time exceeds, drop the previous course which costs the most time. (That must be the best choice!)
        }        
        return pq.size();
    }
}
// @lc code=end

