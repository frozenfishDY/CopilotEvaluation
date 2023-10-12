#https://leetcode.com/problems/longest-absolute-file-path/
#Suppose we have a file system that stores both files and directories. An example of one system is represented in the following picture:
#Here, we have dir as the only directory in the root. dir contains two subdirectories, subdir1 and subdir2. subdir1 contains a file file1.ext and subdirectory subsubdir1. subdir2 contains a subdirectory subsubdir2, which contains a file file2.ext.
#In text form, it looks like this (with ⟶ representing the tab character):
#dir
#⟶ subdir1
#⟶ ⟶ file1.ext
#⟶ ⟶ subsubdir1
#⟶ subdir2
#⟶ ⟶ subsubdir2
#⟶ ⟶ ⟶ file2.ext
#If we were to write this representation in code, it will look like this: "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext". Note that the '\n' and '\t' are the new-line and tab characters.
#Every file and directory has a unique absolute path in the file system, which is the order of directories that must be opened to reach the file/directory itself, all concatenated by '/'s. Using the above example, the absolute path to file2.ext is "dir/subdir2/subsubdir2/file2.ext". Each directory name consists of letters, digits, and/or spaces. Each file name is of the form name.extension, where name and extension consist of letters, digits, and/or spaces.
#Given a string input representing the file system in the explained format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0.
#Note that the testcases are generated such that the file system is valid and no file or directory name has length 0.
# 
#Example 1:
#Input: input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
#Output: 20
#Explanation: We have only one file, and the absolute path is "dir/subdir2/file.ext" of length 20.
#Example 2:
#Input: input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
#Output: 32
#Explanation: We have two files:
#"dir/subdir1/file1.ext" of length 21
#"dir/subdir2/subsubdir2/file2.ext" of length 32.
#We return 32 since it is the longest absolute path to a file.
#Example 3:
#Input: input = "a"
#Output: 0
#Explanation: We do not have any files, just a single directory named "a".
# 
#Constraints:
#	1 <= input.length <= 104
#	input may contain lowercase or uppercase English letters, a new line character '\n', a tab character '\t', a dot '.', a space ' ', and digits.
#	All file and directory names have positive length.
class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        #Solution
        #1. Split the input by '\n'
        #2. For each string in the array, count the number of '\t'
        #3. If the number of '\t' is equal to the length of the stack, push the string into the stack.
        #4. If the number of '\t' is less than the length of the stack, pop the stack until the number of '\t' is equal to the length of the stack.
        #5. If the string contains '.', compare the length of the stack with the current length of the string and update the max length if necessary.
        #6. Return the max length
        #
        #Example:
        #input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
        #stack: ["dir", "subdir1", "subdir2"]
        #maxLen: 0
        #currLen: 20
        #
        #Time complexity: O(n)
        #Space complexity: O(n)

        stack = []
        maxLen = 0
        for s in input.split('\n'):
            currLen = len(s) - s.count('\t')
            while len(stack) > currLen:
                stack.pop()
            if '.' in s:
                maxLen = max(maxLen, sum([len(x) for x in stack]) + len(stack) + len(s) - s.count('\t'))
            else:
                stack.append(s)
        return maxLen