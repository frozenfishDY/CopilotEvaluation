#https://leetcode.com/problems/text-justification/
#Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
#You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
#Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
#For the last line of text, it should be left-justified, and no extra space is inserted between words.
#Note:
#A word is defined as a character sequence consisting of non-space characters only.
#Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
#The input array words contains at least one word.


class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        # initialize the list of lines
        lines = []
        # initialize the list of words in the current line
        line = []
        # initialize the length of the current line
        line_length = 0
        # iterate over the words in the words list
        for word in words:
            # if the length of the current line plus the length of the current word plus 1 (for the space) is less than or equal to the maximum width
            if line_length + len(word) + 1 <= maxWidth:
                # append the current word to the current line
                line.append(word)
                # increment the length of the current line by the length of the current word plus 1 (for the space)
                line_length += len(word) + 1
            # if the length of the current line plus the length of the current word plus 1 (for the space) is greater than the maximum width
            else:
                # append the current line to the list of lines
                lines.append(line)
                # initialize the list of words in the current line
                line = [word]
                # initialize the length of the current line
                line_length = len(word) + 1
        # append the last line to the list of lines
        lines.append(line)
        # initialize the list of justified lines
        justified_lines = []
        # iterate over the lines
        for i in range(len(lines)):
            # if the current line is not the last line
            if i != len(lines) - 1:
                # initialize the number of spaces in the current line
                spaces = maxWidth - sum([len(word) for word in lines[i]])
                # initialize the number of gaps between words in the current line
                gaps = len(lines[i]) - 1
                # if there are no gaps in the current line
                if gaps == 0:
                    # append the current line to the list of justified lines
                    justified_lines.append(lines[i][0] + ' ' * spaces)
                # if there are gaps in the current line
                else:
                    # initialize the number of spaces in each gap
                    spaces_per_gap = spaces // gaps
                    # initialize the number of gaps with an extra space
                    extra_spaces = spaces % gaps
                    # initialize the justified line
                    justified_line = ''
                    # iterate over the words in the current line
                    for j in range(len(lines[i])):
                        # if the current word is not the last word in the current line
                        if j != len(lines[i]) - 1:
                            # if there are extra spaces remaining
                            if extra_spaces > 0:
                                # append the current word to the justified line with an extra space
                                justified_line += lines[i][j] + ' ' * (spaces_per_gap + 1)
                                # decrement the number of extra spaces remaining
                                extra_spaces -= 1
                            # if there are no extra spaces remaining
                            else:
                                # append the current word to the justified line
                                justified_line += lines[i][j] + ' ' * spaces_per_gap
                        # if the current word is the last word in the current line
                        else:
                            # append the current word to the justified line
                            justified_line += lines[i][j]
                    # append the justified line to the list of justified lines
         
    