#https://leetcode.com/problems/keyboard-row/
#Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
#In the American keyboard:
#the first row consists of the characters "qwertyuiop",
#the second row consists of the characters "asdfghjkl", and
#the third row consists of the characters "zxcvbnm".


class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """      
        res=[]
        for i in range(len(words)):
            if words[i][0].lower() in "qwertyuiop":
                for j in range(len(words[i])):
                    if words[i][j].lower() not in "qwertyuiop":
                        break
                else:
                    res.append(words[i])
            elif words[i][0].lower() in "asdfghjkl":
                for j in range(len(words[i])):
                    if words[i][j].lower() not in "asdfghjkl":
                        break
                else:
                    res.append(words[i])
            elif words[i][0].lower() in "zxcvbnm":
                for j in range(len(words[i])):
                    if words[i][j].lower() not in "zxcvbnm":
                        break
                else:
                    res.append(words[i])
        return res
       

    