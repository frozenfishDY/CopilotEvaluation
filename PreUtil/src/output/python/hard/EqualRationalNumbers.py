#https://leetcode.com/problems/equal-rational-numbers/
#Given two strings s and t, each of which represents a non-negative rational number, return true if and only if they represent the same number. The strings may use parentheses to denote the repeating part of the rational number.
#A rational number can be represented using up to three parts: <IntegerPart>, <NonRepeatingPart>, and a <RepeatingPart>. The number will be represented in one of the following three ways:
#<IntegerPart>
#For example, 12, 0, and 123.
#<IntegerPart><.><NonRepeatingPart>
#For example, 0.5, 1., 2.12, and 123.0001.
#<IntegerPart><.><NonRepeatingPart><(><RepeatingPart><)>
#For example, 0.1(6), 1.(9), 123.00(1212).
#The repeating portion of a decimal expansion is conventionally denoted within a pair of round brackets. For example:
#1/6 = 0.16666666... = 0.1(6) = 0.1666(6) = 0.166(66).


class Solution(object):
    def isRationalEqual(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """       
        def getRational(s):
            if '(' not in s:
                return float(s)
            else:
                s = s.replace('(','').replace(')','')
                integer, decimal = s.split('.')
                return float(integer+'.'+decimal[:decimal.index('(')]) + float('0.'+decimal[decimal.index('('):])
        return getRational(s) == getRational(t)

        
        
    