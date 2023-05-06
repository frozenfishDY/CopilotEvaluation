#https://leetcode.com/problems/distinct-subsequences/
#Given two strings s and t, return the number of distinct subsequences of s which equals t.
#The test cases are generated so that the answer fits on a 32-bit signed integer.


class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        # initialize the 2D array of distances
        distances = [[0 for j in range(len(t) + 1)] for i in range(len(s) + 1)]
        # iterate over the rows of the 2D array of distances
        for i in range(len(s) + 1):
            # iterate over the columns of the 2D array of distances
            for j in range(len(t) + 1):
                # if the current row is 0
                if i == 0:
                    # set the current cell to 0
                    distances[i][j] = 0
                # if the current column is 0
                elif j == 0:
                    # set the current cell to 1
                    distances[i][j] = 1
                # if the current row is not 0 and the current column is not 0
                else:
                    # if the current character in s is equal to the current character in t
                    if s[i - 1] == t[j - 1]:
                        # set the current cell to the cell above and to the left plus the cell above
                        distances[i][j] = distances[i - 1][j - 1] + distances[i - 1][j]
                    # if the current character in s is not equal to the current character in t
                    else:
                        # set the current cell to the cell above
                        distances[i][j] = distances[i - 1][j]
        # return the bottom right cell of the 2D array of distances
        return distances[len(s)][len(t)]
        
        
    