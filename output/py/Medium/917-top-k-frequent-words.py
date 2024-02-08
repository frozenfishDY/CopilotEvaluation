#https://leetcode.com/problems/top-k-frequent-words/
#Given an array of strings words and an integer k, return the k most frequent strings.
#Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.


class Solution(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """                        
        word_count = {}
        for word in words:
            if word in word_count:
                word_count[word] += 1
            else:
                word_count[word] = 1
        word_count = sorted(word_count.items(), key=lambda x: (-x[1], x[0]))
        return [word_count[i][0] for i in range(k)]


        

    