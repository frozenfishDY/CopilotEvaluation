#https://leetcode.com/problems/utf-8-validation/
#Given an integer array data representing the data, return whether it is a valid UTF-8 encoding (i.e. it translates to a sequence of valid UTF-8 encoded characters).
#A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
#For a 1-byte character, the first bit is a 0, followed by its Unicode code.
#For an n-bytes character, the first n bits are all one's, the n + 1 bit is 0, followed by n - 1 bytes with the most significant 2 bits being 10.
#This is how the UTF-8 encoding would work:
#     Number of Bytes   |        UTF-8 Octet Sequence
#                       |              (binary)
#   --------------------+-----------------------------------------
#            1          |   0xxxxxxx
#            2          |   110xxxxx 10xxxxxx
#            3          |   1110xxxx 10xxxxxx 10xxxxxx
#            4          |   11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
#x denotes a bit in the binary form of a byte that may be either 0 or 1.
#Note: The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.


class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """       
        def check(data, i, n):
            if i + n > len(data):
                return False
            for j in range(i+1, i+n):
                if data[j] >> 6 != 0b10:
                    return False
            return True
        
        i = 0
        while i < len(data):
            if data[i] >> 7 == 0:
                i += 1
            elif data[i] >> 5 == 0b110:
                if not check(data, i, 2):
                    return False
                i += 2
            elif data[i] >> 4 == 0b1110:
                if not check(data, i, 3):
                    return False
                i += 3
            elif data[i] >> 3 == 0b11110:
                if not check(data, i, 4):
                    return False
                i += 4
            else:
                return False
        return True

        

    