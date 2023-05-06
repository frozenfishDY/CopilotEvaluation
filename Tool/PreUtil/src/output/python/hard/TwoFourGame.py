#https://leetcode.com/problems/24-game/
#You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.
#You are restricted with the following rules:
#The division operator '/' represents real division, not integer division.
#For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
#Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
#For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
#You cannot concatenate numbers together
#For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
#Return true if you can get such expression that evaluates to 24, and false otherwise.


class Solution(object):
    def judgePoint24(self, cards):
        """
        :type cards: List[int]
        :rtype: bool
        """
        if not cards:
            return False
        if len(cards)==1:
            return abs(cards[0]-24)<0.001
        for i in range(len(cards)):
            for j in range(len(cards)):
                if i!=j:
                    new_cards=[]
                    for k in range(len(cards)):
                        if k!=i and k!=j:
                            new_cards.append(cards[k])
                    for k in range(4):
                        if k<2 and j>i:
                            continue
                        if k==0:
                            new_cards.append(cards[i]+cards[j])
                        elif k==1:
                            new_cards.append(cards[i]*cards[j])
                        elif k==2:
                            new_cards.append(cards[i]-cards[j])
                        else:
                            if cards[j]!=0:
                                new_cards.append(cards[i]/cards[j])
                        if self.judgePoint24(new_cards):
                            return True
                        new_cards.pop()
        return False
        
        
    