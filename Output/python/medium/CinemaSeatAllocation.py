#https://leetcode.com/problems/cinema-seat-allocation/
#A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as shown in the figure above.
#Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.
#Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but there is an exceptional case on which an aisle split a four-person group, in that case, the aisle split a four-person group in the middle, which means to have two people on each side.


class Solution(object):
    def maxNumberOfFamilies(self, n, reservedSeats):
        """
        :type n: int
        :type reservedSeats: List[List[int]]
        :rtype: int
        """
        # 1. Create a dictionary with the key as the row number and the value as the list of reserved seats
        # 2. Create a variable called count and set it to 0
        # 3. Iterate through the dictionary
        # 4. If the length of the list of reserved seats is 10, then continue
        # 5. If the length of the list of reserved seats is less than 10, then check if the list contains 2,3,4,5 or 6,7,8,9
        # 6. If it does, then increment count by 1
        # 7. If it doesn't, then increment count by 2
        # 8. Return count
        row_dict = {}
        count = 0
        for i in range(len(reservedSeats)):
            if reservedSeats[i][0] in row_dict:
                row_dict[reservedSeats[i][0]].append(reservedSeats[i][1])
            else:
                row_dict[reservedSeats[i][0]] = [reservedSeats[i][1]]
        for key, value in row_dict.items():
            if len(value) == 10:
                continue
            elif 2 in value and 3 in value and 4 in value and 5 in value:
                count += 1
            elif 6 in value and 7 in value and 8 in value and 9 in value:
                count += 1
            else:
                count += 2
        return count
        

    