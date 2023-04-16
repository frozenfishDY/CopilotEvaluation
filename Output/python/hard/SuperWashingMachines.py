#https://leetcode.com/problems/super-washing-machines/
#You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.
#For each move, you could choose any m (1 <= m <= n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines at the same time.
#Given an integer array machines representing the number of dresses in each washing machine from left to right on the line, return the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.


class Solution(object):
    def findMinMoves(self, machines):
        """
        :type machines: List[int]
        :rtype: int
        """
        if not machines:
            return 0
        total=sum(machines)
        if total%len(machines)!=0:
            return -1
        avg=total/len(machines)
        result=0
        left=0
        for i in range(len(machines)):
            left+=machines[i]-avg
            result=max(result,abs(left),machines[i]-avg)
        return result
        
        
    