/**https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/ */
//You have n bags numbered from 0 to n - 1. You are given two 0-indexed integer arrays capacity and rocks. The ith bag can hold a maximum of capacity[i] rocks and currently contains rocks[i] rocks. You are also given an integer additionalRocks, the number of additional rocks you can place in any of the bags.
//Return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.


int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks){
    int i, j, k, count = 0, max = 0, temp = 0;
    for(i = 0; i < capacitySize; i++){
        temp = capacity[i] - rocks[i];
        if(temp <= additionalRocks){
            count++;
            additionalRocks -= temp;
        }
    }
    return count;

}

    