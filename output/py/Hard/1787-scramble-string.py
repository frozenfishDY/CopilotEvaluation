#https://leetcode.com/problems/scramble-string/
#We can scramble a string s to get a string t using the following algorithm:
#If the length of the string is 1, stop.
#If the length of the string is > 1, do the following:
#Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
#Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
#Apply step 1 recursively on each of the two substrings x and y.
#Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.


class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """      
        # if the length of s1 is not equal to the length of s2
        if len(s1) != len(s2):
            # return false
            return False
        # if the length of s1 is 0
        if len(s1) == 0:
            # return true
            return True
        # if s1 is equal to s2
        if s1 == s2:
            # return true
            return True
        # initialize the 2D array of distances
        distances = [[0 for j in range(len(s2) + 1)] for i in range(len(s1) + 1)]
        # iterate over the rows of the 2D array of distances
        for i in range(len(s1) + 1):
            # iterate over the columns of the 2D array of distances
            for j in range(len(s2) + 1):
                # if the current row is 0
                if i == 0:
                    # set the current cell to the current column
                    distances[i][j] = j
                # if the current column is 0
                elif j == 0:
                    # set the current cell to the current row
                    distances[i][j] = i
                # if the current row is not 0 and the current column is not 0
                else:
                    # if the current character in s1 is equal to the current character in s2
                    if s1[i - 1] == s2[j - 1]:
                        # set the current cell to the cell above and to the left
                        distances[i][j] = distances[i - 1][j - 1]
                    # if the current character in s1 is not equal to the current character in s2
                    else:
                        # set the current cell to the minimum of the cell above, the cell to the left, and the cell above and to the left plus 1
                        distances[i][j] = min(distances[i - 1][j], distances[i][j - 1], distances[i - 1][j - 1]) + 1
        # return true if the bottom right cell of the 2D array of distances is 1
        return distances[len(s1)][len(s2)] == 1
        

        
    