#https://leetcode.com/problems/erect-the-fence/
#You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.
#Fence the entire garden using the minimum length of rope, as it is expensive. The garden is well-fenced only if all the trees are enclosed.
#Return the coordinates of trees that are exactly located on the fence perimeter. You may return the answer in any order.
# 
#Example 1:
#Input: trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
#Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
#Explanation: All the trees will be on the perimeter of the fence except the tree at [2, 2], which will be inside the fence.
#Example 2:
#Input: trees = [[1,2],[2,2],[4,2]]
#Output: [[4,2],[2,2],[1,2]]
#Explanation: The fence forms a line that passes through all the trees.
# 
#Constraints:
#	1 <= trees.length <= 3000
#	trees[i].length == 2
#	0 <= xi, yi <= 100
#	All the given positions are unique.
class Solution(object):
    def outerTrees(self, trees):
        """
        :type trees: List[List[int]]
        :rtype: List[List[int]]
        """
        #https://leetcode.com/problems/erect-the-fence/discuss/103306/C%2B%2B-and-Python-easy-wiki-solution
        def crossProduct(p1, p2, p3):
            return (p2[0] - p1[0]) * (p3[1] - p2[1]) - (p3[0] - p2[0]) * (p2[1] - p1[1])
        def build(points):
            result = []
            for point in points:
                while len(result) >= 2 and crossProduct(result[-2], result[-1], point) < 0:
                    result.pop()
                result.append(point)
            return result
        trees.sort()
        lower = build(trees)
        upper = build(trees[::-1])
        return list(set(map(tuple, lower + upper)))