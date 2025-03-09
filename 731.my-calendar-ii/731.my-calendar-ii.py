#
# @lc app=leetcode id=731 lang=python3
#
# [731] My Calendar II
#
# https://leetcode.com/problems/my-calendar-ii/description/
#
# algorithms
# Medium (62.83%)
# Likes:    2182
# Dislikes: 180
# Total Accepted:    191.1K
# Total Submissions: 304.2K
# Testcase Example:  '["MyCalendarTwo","book","book","book","book","book","book"]\n' +
  '[[],[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]'
#
# You are implementing a program to use as your calendar. We can add a new
# event if adding the event will not cause a triple booking.
# 
# A triple booking happens when three events have some non-empty intersection
# (i.e., some moment is common to all the three events.).
# 
# The event can be represented as a pair of integers startTime and endTime that
# represents a booking on the half-open interval [startTime, endTime), the
# range of real numbers x such that startTime <= x < endTime.
# 
# Implement the MyCalendarTwo class:
# 
# 
# MyCalendarTwo() Initializes the calendar object.
# boolean book(int startTime, int endTime) Returns true if the event can be
# added to the calendar successfully without causing a triple booking.
# Otherwise, return false and do not add the event to the calendar.
# 
# 
# 
# Example 1:
# 
# 
# Input
# ["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
# [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
# Output
# [null, true, true, true, false, true, true]
# 
# Explanation
# MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
# myCalendarTwo.book(10, 20); // return True, The event can be booked. 
# myCalendarTwo.book(50, 60); // return True, The event can be booked. 
# myCalendarTwo.book(10, 40); // return True, The event can be double booked. 
# myCalendarTwo.book(5, 15);  // return False, The event cannot be booked,
# because it would result in a triple booking.
# myCalendarTwo.book(5, 10); // return True, The event can be booked, as it
# does not use time 10 which is already double booked.
# myCalendarTwo.book(25, 55); // return True, The event can be booked, as the
# time in [25, 40) will be double booked with the third event, the time [40,
# 50) will be single booked, and the time [50, 55) will be double booked with
# the second event.
# 
# 
# 
# Constraints:
# 
# 
# 0 <= start < end <= 10^9
# At most 1000 calls will be made to book.
# 
# 
#

# @lc code=start
class MyCalendarTwo:
    def __init__(self):
        # List to hold the booked intervals
        self.bookings = []
        
    def book(self, start: int, end: int) -> bool:
        # Check for overlaps with existing bookings
        for a, b in self.bookings:
            # Check if the new booking overlaps with the existing interval
            if start < b and end > a:
                # Calculate the overlapping sub-interval
                new_start = max(a, start)
                new_end = min(b, end)
                
                # Check if the sub-interval overlaps more than once
                if self.check(new_start, new_end):
                    return False  # Overlapping more than once, booking fails
        
        # If there are no conflicts, add the booking
        self.bookings.append((start, end))
        return True  # Booking successful
    
    def check(self, start: int, end: int) -> bool:
        overlap_count = 0
        
        for a, b in self.bookings:
            # Check for strict overlap
            if start < b and end > a:
                overlap_count += 1
                if overlap_count == 2:
                    return True  # Found more than one overlap
        
        return False  # No overlapping found
        


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(startTime,endTime)
# @lc code=end

