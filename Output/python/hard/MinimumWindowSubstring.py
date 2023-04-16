#https://leetcode.com/problems/minimum-window-substring/
#Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
#The testcases will be generated such that the answer is unique.


class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """       
        # initialize the 2D array of distances
        distances = [[0 for j in range(len(t) + 1)] for i in range(len(s) + 1)]
        # iterate over the rows of the 2D array of distances
        for i in range(len(s) + 1):
            # iterate over the columns of the 2D array of distances
            for j in range(len(t) + 1):
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
                    # if the current character in s is equal to the current character in t
                    if s[i - 1] == t[j - 1]:
                        # set the current cell to the cell above and to the left
                        distances[i][j] = distances[i - 1][j - 1]
                    # if the current character in s is not equal to the current character in t
                    else:
                        # set the current cell to the minimum of the cell above, the cell to the left, and the cell above and to the left plus 1
                        distances[i][j] = min(distances[i - 1][j], distances[i][j - 1], distances[i - 1][j - 1]) + 1
        # return the bottom right cell of the 2D array of distances
        return distances[len(s)][len(t)]
        
        
    