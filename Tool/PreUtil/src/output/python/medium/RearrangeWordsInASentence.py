#https://leetcode.com/problems/rearrange-words-in-a-sentence/
#Given a sentence text (A sentence is a string of space-separated words) in the following format:
#First letter is in upper case.
#Each word in text are separated by a single space.
#Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.
#Return the new text following the format shown above.


class Solution(object):
    def arrangeWords(self, text):
        """
        :type text: str
        :rtype: str
        """    
        # 1. Split the string into a list of words
        # 2. Sort the list by length
        # 3. Join the list into a string
        # 4. Capitalize the first letter
        # 5. Return the string
        words = text.split(" ")
        words.sort(key=len)
        result = " ".join(words)
        result = result[0].upper() + result[1:]
        return result
            
          

    