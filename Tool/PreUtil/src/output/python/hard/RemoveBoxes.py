#https://leetcode.com/problems/remove-boxes/
#You are given several boxes with different colors represented by different positive numbers.
#You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.
#Return the maximum points you can get.


class Solution(object):
    def removeBoxes(self, boxes):
        """
        :type boxes: List[int]
        :rtype: int
        """      
        if not boxes:
            return 0
        if len(boxes)==1:
            return 1
        result=0
        for i in range(len(boxes)):
            for j in range(i+1,len(boxes)):
                if boxes[i]==boxes[j]:
                    result=max(result,self.removeBoxes(boxes[:i]+boxes[j+1:])+j-i+1)
        return result

        
        
    