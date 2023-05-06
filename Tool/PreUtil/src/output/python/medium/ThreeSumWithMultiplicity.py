#https://leetcode.com/problems/3sum-with-multiplicity/
#Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
#As the answer can be very large, return it modulo 10^9 + 7.


class Solution(object):
    def threeSumMulti(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
        res = 0
        arr.sort()
        for i in range(len(arr)):
            left = i + 1
            right = len(arr) - 1
            while left < right:
                if arr[i] + arr[left] + arr[right] == target:
                    if arr[left] == arr[right]:
                        res += (right - left + 1) * (right - left) / 2
                        break
                    else:
                        left_count = 1
                        right_count = 1
                        while left < right and arr[left] == arr[left + 1]:
                            left_count += 1
                            left += 1
                        while left < right and arr[right] == arr[right - 1]:
                            right_count += 1
                            right -= 1
                        res += left_count * right_count
                        left += 1
                        right -= 1
                elif arr[i] + arr[left] + arr[right] < target:
                    left += 1
                else:
                    right -= 1
        return res % (10 ** 9 + 7)
        

    