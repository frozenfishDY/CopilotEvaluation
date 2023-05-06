/**https://leetcode.com/problems/count-the-digits-that-divide-a-number/ */
//Given an integer num, return the number of digits in num that divide num.
//An integer val divides nums if nums % val == 0.


int countDigits(int num){
    int count = 0;
    int temp = num;
    while(temp != 0){
        temp /= 10;
        count++;
    }
    return count;

}

    