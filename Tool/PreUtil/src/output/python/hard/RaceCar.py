#https://leetcode.com/problems/race-car/
#Your car starts at position 0 and speed +1 on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):
#When you get an instruction 'A', your car does the following:
#position += speed
#speed *= 2
#When you get an instruction 'R', your car does the following:
#If your speed is positive then speed = -1
#otherwise speed = 1
#Your position stays the same.
#For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 --> 3, and your speed goes to 1 --> 2 --> 4 --> -1.
#Given a target position target, return the length of the shortest sequence of instructions to get there.


class Solution(object):
    def racecar(self, target):
        """
        :type target: int
        :rtype: int
        """
        # 1. find the number of steps to reach the target
        # 2. return the number of steps
        return self.find_steps(target)
        
        
    