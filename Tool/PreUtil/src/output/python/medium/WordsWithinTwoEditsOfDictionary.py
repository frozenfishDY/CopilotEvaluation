#https://leetcode.com/problems/words-within-two-edits-of-dictionary/
#You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.
#In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.
#Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.


class Solution(object):
    def twoEditWords(self, queries, dictionary):
        """
        :type queries: List[str]
        :type dictionary: List[str]
        :rtype: List[str]
        """
        result=[]
        for i in range(len(queries)):
            for j in range(len(dictionary)):
                if self.edit_distance(queries[i],dictionary[j])<=2:
                    result.append(queries[i])
                    break
        return result
        

    