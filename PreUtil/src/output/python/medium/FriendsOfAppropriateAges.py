#https://leetcode.com/problems/friends-of-appropriate-ages/
#There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.
#A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:
#age[y] <= 0.5 * age[x] + 7
#age[y] > age[x]
#age[y] > 100 && age[x] < 100
#Otherwise, x will send a friend request to y.
#Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.
#Return the total number of friend requests made.


class Solution(object):
    def numFriendRequests(self, ages):
        """
        :type ages: List[int]
        :rtype: int
        """
        res = 0
        for i in range(len(ages)):
            for j in range(len(ages)):
                if i != j and ages[i] <= 0.5 * ages[j] + 7 or ages[i] > ages[j] or ages[i] > 100 and ages[j] < 100:
                    res += 1
        return res
        

    