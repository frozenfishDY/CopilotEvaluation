#https://leetcode.com/problems/can-make-palindrome-from-substring/
#You are given a string s and array queries where queries[i] = [lefti, righti, ki]. We may rearrange the substring s[lefti...righti] for each query and then choose up to ki of them to replace with any lowercase English letter.
#If the substring is possible to be a palindrome string after the operations above, the result of the query is true. Otherwise, the result is false.
#Return a boolean array answer where answer[i] is the result of the ith query queries[i].
#Note that each letter is counted individually for replacement, so if, for example s[lefti...righti] = "aaa", and ki = 2, we can only replace two of the letters. Also, note that no query modifies the initial string s.
# 
#Example :
#Input: s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
#Output: [true,false,false,true,true]
#Explanation:
#queries[0]: substring = "d", is palidrome.
#queries[1]: substring = "bc", is not palidrome.
#queries[2]: substring = "abcd", is not palidrome after replacing only 1 character.
#queries[3]: substring = "abcd", could be changed to "abba" which is palidrome. Also this can be changed to "baab" first rearrange it "bacd" then replace "cd" with "ab".
#queries[4]: substring = "abcda", could be changed to "abcba" which is palidrome.
#Example 2:
#Input: s = "lyb", queries = [[0,1,0],[2,2,1]]
#Output: [false,true]
# 
#Constraints:
#	1 <= s.length, queries.length <= 105
#	0 <= lefti <= righti < s.length
#	0 <= ki <= s.length
#	s consists of lowercase English letters.
class Solution(object):
    def canMakePaliQueries(self, s, queries):
        """
        :type s: str
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        # Approach 1: Prefix Sum
        # Time Complexity: O(N + Q)
        # Space Complexity: O(N)
        # Runtime: 1208 ms, faster than 74.87% of Python3 online submissions for Can Make Palindrome from Substring.
        # Memory Usage: 26.7 MB, less than 89.15% of Python3 online submissions for Can Make Palindrome from Substring.
        ans, prefix = [], [0]
        for i in range(len(s)):
            prefix.append(prefix[-1] ^ (1 << (ord(s[i]) - ord('a'))))
        for left, right, k in queries:
            ans.append(bin(prefix[right + 1] ^ prefix[left]).count('1') // 2 <= k)
        return ans
