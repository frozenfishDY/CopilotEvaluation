#https://leetcode.com/problems/sender-with-largest-word-count/
#You have a chat log of n messages. You are given two string arrays messages and senders where messages[i] is a message sent by senders[i].
#A message is list of words that are separated by a single space with no leading or trailing spaces. The word count of a sender is the total number of words sent by the sender. Note that a sender may send more than one message.
#Return the sender with the largest word count. If there is more than one sender with the largest word count, return the one with the lexicographically largest name.
#Note:
#Uppercase letters come before lowercase letters in lexicographical order.
#"Alice" and "alice" are distinct.


class Solution(object):
    def largestWordCount(self, messages, senders):
        """
        :type messages: List[str]
        :type senders: List[str]
        :rtype: str
        """ 
        # 1. find the sender with the largest word count
        # 2. return the sender with the largest word count
        # 1. find the sender with the largest word count
        # 2. return the sender with the largest word count
        return self.largestWordCountFromIndex(messages, senders, 0, 0)
      
    