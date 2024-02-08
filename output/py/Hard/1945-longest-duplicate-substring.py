#https://leetcode.com/problems/longest-duplicate-substring/
#Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
#Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".


class Solution(object):
    def longestDupSubstring(self, s):
        """
        :type s: str
        :rtype: str
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

        
        
    