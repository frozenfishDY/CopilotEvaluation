#https://leetcode.com/problems/sentence-similarity-iii/
#A sentence is a list of words that are separated by a single space with no leading or trailing spaces. For example, "Hello World", "HELLO", "hello world hello world" are all sentences. Words consist of only uppercase and lowercase English letters.
#Two sentences sentence1 and sentence2 are similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. For example, sentence1 = "Hello my name is Jane" and sentence2 = "Hello Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in sentence2.
#Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.


class Solution(object):
    def areSentencesSimilar(self, sentence1, sentence2):
        """
        :type sentence1: str
        :type sentence2: str
        :rtype: bool
        """
        if len(sentence1) < len(sentence2):
            sentence1, sentence2 = sentence2, sentence1
        s1 = sentence1.split()
        s2 = sentence2.split()
        if len(s1) < len(s2):
            return False
        i = 0
        while i < len(s2) and s1[i] == s2[i]:
            i += 1
        j = 0
        while j < len(s2) and s1[-j-1] == s2[-j-1]:
            j += 1
        return i + j >= len(s2)
        

    