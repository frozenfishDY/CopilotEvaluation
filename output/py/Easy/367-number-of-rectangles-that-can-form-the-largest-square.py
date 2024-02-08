#https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/
#You are given an array rectangles where rectangles[i] = [li, wi] represents the ith rectangle of length li and width wi._x000D_
#_x000D_
#You can cut the ith rectangle to form a square with a side length of k if both k <= li and k <= wi. For example, if you have a rectangle [4,6], you can cut it to get a square with a side length of at most 4._x000D_
#_x000D_
#Let maxLen be the side length of the largest square you can obtain from any of the given rectangles._x000D_
#_x000D_
#Return the number of rectangles that can make a square with a side length of maxLen._x000D_
#_x000D_
# _x000D_
#Example 1:_x000D_
#_x000D_
#_x000D_
#Input: rectangles = [[5,8],[3,9],[5,12],[16,5]]_x000D_
#Output: 3_x000D_
#Explanation: The largest squares you can get from each rectangle are of lengths [5,3,5,5]._x000D_
#The largest possible square is of length 5, and you can get it out of 3 rectangles._x000D_
#_x000D_
#_x000D_
#Example 2:_x000D_
#_x000D_
#_x000D_
#Input: rectangles = [[2,3],[3,7],[4,3],[3,7]]_x000D_
#Output: 3_x000D_
#_x000D_
#_x000D_
# _x000D_
#Constraints:_x000D_
#_x000D_
#_x000D_
#	1 <= rectangles.length <= 1000_x000D_
#	rectangles[i].length == 2_x000D_
#	1 <= li, wi <= 109_x000D_
#	li != wi_x000D_
class Solution(object):
    def countGoodRectangles(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: int
        """
        return collections.Counter(min(i) for i in rectangles)[max(collections.Counter(min(i) for i in rectangles))]
