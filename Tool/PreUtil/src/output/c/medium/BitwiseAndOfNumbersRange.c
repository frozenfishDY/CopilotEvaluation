/**https://leetcode.com/problems/bitwise-and-of-numbers-range/ */
//Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.


int rangeBitwiseAnd(int left, int right){
    int count = 0;
    while(left != right){
        left >>= 1;
        right >>= 1;
        count++;
    }
    return left << count;

}

    