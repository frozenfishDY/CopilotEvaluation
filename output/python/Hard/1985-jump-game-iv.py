#https://leetcode.com/problems/jump-game-iv/
#Given an array of integers arr, you are initially positioned at the first index of the array.
#In one step you can jump from index i to index:
#	i + 1 where: i + 1 < arr.length.
#	i - 1 where: i - 1 >= 0.
#	j where: arr[i] == arr[j] and i != j.
#Return the minimum number of steps to reach the last index of the array.
#Notice that you can not jump outside of the array at any time.
# 
#Example 1:
#Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
#Output: 3
#Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
#Example 2:
#Input: arr = [7]
#Output: 0
#Explanation: Start index is the last index. You do not need to jump.
#Example 3:
#Input: arr = [7,6,9,6,9,6,9,7]
#Output: 1
#Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
# 
#Constraints:
#	1 <= arr.length <= 5 * 104
#	-108 <= arr[i] <= 108
class Solution(object):
    def minJumps(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        #BFS
        #Time:  O(n)
        #Space: O(n)
        if len(arr) == 1:
            return 0
        graph = collections.defaultdict(list)
        for i, a in enumerate(arr):
            graph[a].append(i)
        result = 0
        q = collections.deque([0])
        lookup = set([0])
        while q:
            for _ in range(len(q)):
                i = q.popleft()
                if i + 1 == len(arr):
                    return result
                for j in [i - 1, i + 1] + graph[arr[i]]:
                    if 0 <= j < len(arr) and j not in lookup:
                        lookup.add(j)
                        q.append(j)
                graph[arr[i]] = []
            result += 1
        return -1