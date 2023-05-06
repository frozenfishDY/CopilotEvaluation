/**https://leetcode.com/problems/binary-number-with-alternating-bits/ */
//Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.


bool hasAlternatingBits(int n){
    int last = n & 1;
    n = n >> 1;
    while(n != 0){
        int cur = n & 1;
        if(cur == last){
            return false;
        }
        last = cur;
        n = n >> 1;
    }
    return true;

}

    