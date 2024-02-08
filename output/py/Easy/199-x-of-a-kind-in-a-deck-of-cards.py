#https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
#You are given an integer array deck where deck[i] represents the number written on the ith card.
#Partition the cards into one or more groups such that:
#	Each group has exactly x cards where x > 1, and
#	All the cards in one group have the same integer written on them.
#Return true if such partition is possible, or false otherwise.
# 
#Example 1:
#Input: deck = [1,2,3,4,4,3,2,1]
#Output: true
#Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
#Example 2:
#Input: deck = [1,1,1,2,2,2,3,3]
#Output: false
#Explanation: No possible partition.
# 
#Constraints:
#	1 <= deck.length <= 104
#	0 <= deck[i] < 104
class Solution(object):
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        deck.sort()
        count=1
        for i in range(1, len(deck)):
            if deck[i]==deck[i-1]:
                count+=1
            else:
                break
        if count==len(deck):
            return True
        for x in range(2, count+1):
            if count%x==0:
                flag=True
                for i in range(x, len(deck), x):
                    for j in range(x):
                        if deck[i]!=deck[i-j-1]:
                            flag=False
                            break
                    if not flag:
                        break
                if flag:
                    return True
        return False