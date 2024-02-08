#https://leetcode.com/problems/swap-for-longest-repeated-character-substring/
#You are given a string text. You can swap two of the characters in the text.
#Return the length of the longest substring with repeated characters.
# 
#Example 1:
#Input: text = "ababa"
#Output: 3
#Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa" with length 3.
#Example 2:
#Input: text = "aaabaaa"
#Output: 6
#Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.
#Example 3:
#Input: text = "aaaaa"
#Output: 5
#Explanation: No need to swap, longest repeated character substring is "aaaaa" with length is 5.
# 
#Constraints:
#	1 <= text.length <= 2 * 104
#	text consist of lowercase English characters only.
class Solution(object):
    def maxRepOpt1(self, text):
        """
        :type text: str
        :rtype: int
        """
        ans, count, prev, prev_count, prev_prev_count = 0, Counter(text), None, 0, 0
        for c in text:
            if c == prev:
                prev_count += 1
            else:
                ans = max(ans, prev_count + min(count[c], 1 + prev_prev_count))
                prev_count, prev_prev_count, prev = 1, prev_count, c
        return max(ans, prev_count + min(count[c], 1 + prev_prev_count))
