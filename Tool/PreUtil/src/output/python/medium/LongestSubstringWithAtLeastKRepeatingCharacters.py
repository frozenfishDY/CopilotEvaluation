#https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
#Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.


class Solution(object):
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        res = 0
        for i in range(1, 27):
            l, r = 0, 0
            cnt = [0] * 26
            total = 0
            less = 0
            while r < len(s):
                cnt[ord(s[r]) - ord('a')] += 1
                if cnt[ord(s[r]) - ord('a')] == 1:
                    total += 1
                    less += 1
                if cnt[ord(s[r]) - ord('a')] == k:
                    less -= 1
                while total > i:
                    cnt[ord(s[l]) - ord('a')] -= 1
                    if cnt[ord(s[l]) - ord('a')] == k - 1:
                        less += 1
                    if cnt[ord(s[l]) - ord('a')] == 0:
                        total -= 1
                        less -= 1
                    l += 1
                if less == 0:
                    res = max(res, r - l + 1)
                r += 1
        return res
        

    