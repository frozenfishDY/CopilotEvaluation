#https://leetcode.com/problems/smallest-string-with-swaps/
#You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
#You can swap the characters at any pair of indices in the given pairs any number of times.
#Return the lexicographically smallest string that s can be changed to after using the swaps.
# 
#Example 1:
#Input: s = "dcab", pairs = [[0,3],[1,2]]
#Output: "bacd"
#Explaination: 
#Swap s[0] and s[3], s = "bcad"
#Swap s[1] and s[2], s = "bacd"
#Example 2:
#Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
#Output: "abcd"
#Explaination: 
#Swap s[0] and s[3], s = "bcad"
#Swap s[0] and s[2], s = "acbd"
#Swap s[1] and s[2], s = "abcd"
#Example 3:
#Input: s = "cba", pairs = [[0,1],[1,2]]
#Output: "abc"
#Explaination: 
#Swap s[0] and s[1], s = "bca"
#Swap s[1] and s[2], s = "bac"
#Swap s[0] and s[1], s = "abc"
# 
#Constraints:
#	1 <= s.length <= 10^5
#	0 <= pairs.length <= 10^5
#	0 <= pairs[i][0], pairs[i][1] < s.length
#	s only contains lower case English letters.
class Solution(object):
    def smallestStringWithSwaps(self, s, pairs):
        """
        :type s: str
        :type pairs: List[List[int]]
        :rtype: str
        """
        # Approach 1: DFS
        # Time Complexity: O(NlogN)
        # Space Complexity: O(N)
        # Runtime: 1724 ms, faster than 11.77% of Python online submissions for Smallest String With Swaps.
        # Memory Usage: 58.2 MB, less than 5.11% of Python online submissions for Smallest String With Swaps.
        # def dfs(node, visited):
        #     visited.add(node)
        #     ans.append(node)
        #     for neighbor in graph[node]:
        #         if neighbor not in visited:
        #             dfs(neighbor, visited)
        # ans, graph, visited = [], defaultdict(list), set()
        # for a, b in pairs:
        #     graph[a].append(b)
        #     graph[b].append(a)
        # for i in range(len(s)):
        #     if i not in visited:
        #         ans.clear()
        #         dfs(i, visited)
        #         ans.sort()
        #         temp = sorted(s[i] for i in ans)
        #         for j, node in enumerate(ans):
        #             s[node] = temp[j]
        # return ''.join(s)
        
        # Approach 2: Union Find
        # Time Complexity: O(NlogN)
        # Space Complexity: O(N)
        # Runtime: 360 ms, faster than 96.40% of Python online submissions for Smallest String With Swaps.
        # Memory Usage: 37.2 MB, less than 99.47% of Python online submissions for Smallest String With Swaps.
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        def union(x, y):
            parent[find(x)] = find(y)
        parent = [i for i in range(len(s))]
        for x, y in pairs:
            union(x, y)
        groups = defaultdict(list)
        for i in range(len(s)):
            groups[find(i)].append(i)
        for group in groups.values():
            chars = sorted(s[node] for node in group)
            for i, node in enumerate(group):
                s[node] = chars[i]
        return ''.join(s)