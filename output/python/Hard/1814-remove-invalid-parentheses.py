#https://leetcode.com/problems/remove-invalid-parentheses/
#Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
#Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.
# 
#Example 1:
#Input: s = "()())()"
#Output: ["(())()","()()()"]
#Example 2:
#Input: s = "(a)())()"
#Output: ["(a())()","(a)()()"]
#Example 3:
#Input: s = ")("
#Output: [""]
# 
#Constraints:
#	1 <= s.length <= 25
#	s consists of lowercase English letters and parentheses '(' and ')'.
#	There will be at most 20 parentheses in s.
class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        #https://leetcode.com/problems/remove-invalid-parentheses/discuss/75032/Share-my-Python-BFS-solution
        def isValid(s):
            count = 0
            for c in s:
                if c == '(':
                    count += 1
                elif c == ')':
                    count -= 1
                    if count < 0:
                        return False
            return count == 0
        result = []
        visited = set([s])
        queue = collections.deque([s])
        found = False
        while queue:
            cur = queue.popleft()
            if isValid(cur):
                result.append(cur)
                found = True
            if found:
                continue
            for i in range(len(cur)):
                if cur[i] not in '()':
                    continue
                temp = cur[:i] + cur[i + 1:]
                if temp not in visited:
                    visited.add(temp)
                    queue.append(temp)
        return result