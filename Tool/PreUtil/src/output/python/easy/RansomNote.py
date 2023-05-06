#https://leetcode.com/problems/ransom-note/
#Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
#Each letter in magazine can only be used once in ransomNote.


class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """ 
        if len(ransomNote)>len(magazine):
            return False
        dict={}
        for i in range(0,len(magazine)):
            if magazine[i] in dict:
                dict[magazine[i]]+=1
            else:
                dict[magazine[i]]=1
        for i in range(0,len(ransomNote)):
            if ransomNote[i] in dict:
                dict[ransomNote[i]]-=1
            else:
                return False
        for key in dict:
            if dict[key]<0:
                return False
        return True

    