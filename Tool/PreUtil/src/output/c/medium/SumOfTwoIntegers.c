/**https://leetcode.com/problems/sum-of-two-integers/ */
//Given two integers a and b, return the sum of the two integers without using the operators + and -.


int getSum(int a, int b){
    int result = 0;
    int carry = 0;
    for(int i = 0; i < 32; i++){
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        int bitResult = bitA ^ bitB ^ carry;
        carry = (bitA & bitB) | (bitA & carry) | (bitB & carry);
        result |= bitResult << i;
    }
    return result;

}

    