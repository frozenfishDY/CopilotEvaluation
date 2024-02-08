#https://leetcode.com/problems/find-original-array-from-doubled-array/
#An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.
#Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.


class Solution(object):
    def findOriginalArray(self, changed):
        """
        :type changed: List[int]
        :rtype: List[int]
        """   
        # 1. If the length of changed is odd, then return an empty array
        # 2. Create a dictionary to store the frequency of each number in changed
        # 3. Create a result array
        # 4. Loop through the numbers in changed
        # 5. If the number is even, then divide it by 2 and check if the number is in the dictionary
        # 6. If the number is odd, then multiply it by 2 and check if the number is in the dictionary
        # 7. If the number is in the dictionary, then decrement the frequency of the number in the dictionary
        # 8. If the frequency of the number in the dictionary is 0, then remove the number from the dictionary
        # 9. Append the number to the result array
        # 10. Return the result array
        if len(changed) % 2 == 1:
            return []
        freq = {}
        result = []
        for num in changed:
            if num % 2 == 0:
                if num / 2 in freq:
                    freq[num / 2] -= 1
                    if freq[num / 2] == 0:
                        del freq[num / 2]
                    result.append(num / 2)
            else:
                if num * 2 in freq:
                    freq[num * 2] -= 1
                    if freq[num * 2] == 0:
                        del freq[num * 2]
                    result.append(num)
            if num not in freq:
                freq[num] = 1
            else:
                freq[num] += 1
        return result
         

    