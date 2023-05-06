#https://leetcode.com/problems/stickers-to-spell-word/
#We are given n different types of stickers. Each sticker has a lowercase English word on it.
#You would like to spell out the given string target by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
#Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.
#Note: In all test cases, all words were chosen randomly from the 1000 most common US English words, and target was chosen as a concatenation of two random words.


class Solution(object):
    def minStickers(self, stickers, target):
        """
        :type stickers: List[str]
        :type target: str
        :rtype: int
        """
        if not stickers or not target:
            return 0
        dp = [float('inf') for _ in range(len(target)+1)]
        dp[0] = 0
        for i in range(1,len(target)+1):
            for sticker in stickers:
                if target[i-1] in sticker:
                    for j in range(len(sticker)):
                        if target[i-1] == sticker[j]:
                            dp[i] = min(dp[i],dp[i-1]+1)
                            break
        return dp[-1]
        
        
    