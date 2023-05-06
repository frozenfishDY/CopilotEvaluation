#https://leetcode.com/problems/average-waiting-time/
#There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:
#arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
#timei is the time needed to prepare the order of the ith customer.
#When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.
#Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.


class Solution(object):
    def averageWaitingTime(self, customers):
        """
        :type customers: List[List[int]]
        :rtype: float
        """
        result=0
        for i in range(len(customers)):
            if i==0:
                result+=customers[i][1]
            else:
                if customers[i][0]>=customers[i-1][0]+customers[i-1][1]:
                    result+=customers[i][1]
                else:
                    result+=customers[i][1]+customers[i-1][0]+customers[i-1][1]-customers[i][0]
        return result/len(customers)
        

    