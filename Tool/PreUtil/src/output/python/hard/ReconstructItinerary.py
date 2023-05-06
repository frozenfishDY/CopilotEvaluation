#https://leetcode.com/problems/reconstruct-itinerary/
#You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.
#All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
#For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
#You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.


class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        if not tickets:
            return []
        if len(tickets)==1:
            return tickets[0]
        tickets.sort()
        result=[]
        for i in range(len(tickets)):
            if tickets[i][0]=="JFK":
                temp=tickets[i]
                tickets.remove(temp)
                result.append(temp)
                result.extend(self.findItinerary(tickets))
                if len(result)==len(tickets)+1:
                    return result
                else:
                    tickets.append(temp)
                    result.pop()
        return result
        
        
    