/**https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/ */
//You have a 1-indexed binary string of length n where all the bits are 0 initially. We will flip all the bits of this binary string (i.e., change them from 0 to 1) one by one. You are given a 1-indexed integer array flips where flips[i] indicates that the bit at index i will be flipped in the ith step.
//A binary string is prefix-aligned if, after the ith step, all the bits in the inclusive range [1, i] are ones and all the other bits are zeros.
//Return the number of times the binary string is prefix-aligned during the flipping process.


class NumberOfTimesBinaryStringIsPrefixAligned {
    public int numTimesAllBlue(int[] flips) {
        int max = 0;
        int count = 0;
        for(int i = 0; i < flips.length; i++){
            max = Math.max(max, flips[i]);
            if(max == i + 1){
                count++;
            }
        }
        return count;
        
    }
}

    