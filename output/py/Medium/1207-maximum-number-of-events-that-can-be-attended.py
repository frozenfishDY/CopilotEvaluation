#https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
#You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
#You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.
#Return the maximum number of events you can attend.
# 
#Example 1:
#Input: events = [[1,2],[2,3],[3,4]]
#Output: 3
#Explanation: You can attend all the three events.
#One way to attend them all is as shown.
#Attend the first event on day 1.
#Attend the second event on day 2.
#Attend the third event on day 3.
#Example 2:
#Input: events= [[1,2],[2,3],[3,4],[1,2]]
#Output: 4
# 
#Constraints:
#	1 <= events.length <= 105
#	events[i].length == 2
#	1 <= startDayi <= endDayi <= 105
class Solution(object):
    def maxEvents(self, events):
        """
        :type events: List[List[int]]
        :rtype: int
        """  
        events.sort()
        #print "events: ", events
        #print "len(events): ", len(events)
        days = set()
        for e in events:
            for d in range(e[0], e[1]+1):
                days.add(d)
        #print "days: ", days
        #print "len(days): ", len(days)
        events.sort(key=lambda x: x[1] - x[0])
        #print "events: ", events
        #print "len(events): ", len(events)
        num = 0
        for d in range(1, max(days)+1):
            for e in events:
                if d >= e[0] and d <= e[1]:
                    #print "d: ", d, " e: ", e
                    events.remove(e)
                    num += 1
                    break
        return num