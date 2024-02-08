/**https://leetcode.com/problems/hamming-distance/ */
//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//Given two integers x and y, return the Hamming distance between them.


int hammingDistance(int x, int y){
    int count = 0;
    int i = 0;
    while(i < 32){
        if((x & 1) != (y & 1)){
            count++;
        }
        x = x >> 1;
        y = y >> 1;
        i++;
    }
    return count;

}

    