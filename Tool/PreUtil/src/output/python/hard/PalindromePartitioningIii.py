#https://leetcode.com/problems/palindrome-partitioning-iii/
#You are given a string s containing lowercase letters and an integer k. You need to :
#First, change some characters of s to other lowercase English letters.
#Then divide s into k non-empty disjoint substrings such that each substring is a palindrome.
#Return the minimal number of characters that you need to change to divide the string.


class Solution(object):
    def palindromePartition(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """      
        def get_depth(s):
            res = 0
            for c in s:
                if c == '-':
                    res += 1
                else:
                    break
            return res
        def get_val(s):
            res = 0
            for c in s:
                if c == '-':
                    break
                else:
                    res = res * 10 + int(c)
            return res
        def get_node(s):
            return TreeNode(get_val(s))
        def get_children(s):
            res = []
            i = 0
            while i < len(s):
                if s[i] == '-':
                    j = i
                    while j < len(s) and s[j] == '-':
                        j += 1
                    k = j
                    while k < len(s) and s[k] != '-':
                        k += 1
                    res.append(s[j:k])
                    i = k
                else:
                    i += 1
            return res
        def get_tree(s):
            if not s:
                return None
            root = get_node(s)
            children = get_children(s)
            if not children:
                return root
            root.left = get_tree(children[0])
            if len(children) > 1:
                root.right = get_tree(children[1])
            return root
        return get_tree(traversal)

        
        
        
    