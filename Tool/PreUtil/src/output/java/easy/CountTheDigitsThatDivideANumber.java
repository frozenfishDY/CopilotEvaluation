/**https://leetcode.com/problems/count-the-digits-that-divide-a-number/ */
//Given an integer num, return the number of digits in num that divide num.
//An integer val divides nums if nums % val == 0.


class CountTheDigitsThatDivideANumber {
    public int countDigits(int num) {
        int count = 0;
        int temp = num;
        while(temp > 0){
            int digit = temp % 10;
            if(digit != 0 && num % digit == 0){
                count++;
            }
            temp /= 10;
        }
        return count;
        
        
        
    }
}

    