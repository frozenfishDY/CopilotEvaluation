#https://leetcode.com/problems/remove-comments/
#Given a C++ program, remove comments from it. The program source is an array of strings source where source[i] is the ith line of the source code. This represents the result of splitting the original source code string by the newline character '
#'.
#In C++, there are two types of comments, line comments, and block comments.
#The string "//" denotes a line comment, which represents that it and the rest of the characters to the right of it in the same line should be ignored.
#The string "/*" denotes a block comment, which represents that all characters until the next (non-overlapping) occurrence of "*/" should be ignored. (Here, occurrences happen in reading order: line by line from left to right.) To be clear, the string "/*/" does not yet end the block comment, as the ending would be overlapping the beginning.
#The first effective comment takes precedence over others.
#For example, if the string "//" occurs in a block comment, it is ignored.
#Similarly, if the string "/*" occurs in a line or block comment, it is also ignored.
#If a certain line of code is empty after removing comments, you must not output that line: each string in the answer list will be non-empty.
#There will be no control characters, single quote, or double quote characters.
#For example, source = "string s = "/* Not a comment. */";" will not be a test case.
#Also, nothing else such as defines or macros will interfere with the comments.
#It is guaranteed that every open block comment will eventually be closed, so "/*" outside of a line or block comment always starts a new comment.
#Finally, implicit newline characters can be deleted by block comments. Please see the examples below for details.
#After removing the comments from the source code, return the source code in the same format.


class Solution(object):
    def removeComments(self, source):
        """
        :type source: List[str]
        :rtype: List[str]
        """ 
        res = []
        block = False
        for line in source:
            i = 0
            if not block:
                new = []
            while i < len(line):
                if not block and line[i:i+2] == '/*':
                    block = True
                    i += 1
                elif block and line[i:i+2] == '*/':
                    block = False
                    i += 1
                elif not block and line[i:i+2] == '//':
                    break
                elif not block:
                    new.append(line[i])
                i += 1
            if new and not block:
                res.append(''.join(new))
        return res

        

    