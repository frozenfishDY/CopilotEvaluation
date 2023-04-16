/**https://leetcode.com/problems/total-hamming-distance/ */
//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.


int totalHammingDistance(int* nums, int numsSize){
    int count = 0;
    for(int i = 0; i < 32; i++){
        int bitCount = 0;
        for(int j = 0; j < numsSize; j++){
            bitCount += (nums[j] >> i) & 1;
        }
        count += bitCount * (numsSize - bitCount);
    }
    return count;

}

    