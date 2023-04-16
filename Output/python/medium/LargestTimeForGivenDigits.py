#https://leetcode.com/problems/largest-time-for-given-digits/
#Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.
#24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.
#Return the latest 24-hour time in "HH:MM" format. If no valid time can be made, return an empty string.


class Solution(object):
    def largestTimeFromDigits(self, arr):
        """
        :type arr: List[int]
        :rtype: str
        """
        res = -1
        for i in range(4):
            for j in range(4):
                if i == j:
                    continue
                for k in range(4):
                    if i == k or j == k:
                        continue
                    l = 6 - i - j - k
                    h = 10 * arr[i] + arr[j]
                    m = 10 * arr[k] + arr[l]
                    if h < 24 and m < 60:
                        res = max(res, h * 60 + m)
        return "" if res == -1 else "{:02d}:{:02d}".format(res / 60, res % 60)
        

    