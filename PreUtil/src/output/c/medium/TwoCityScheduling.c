/**https://leetcode.com/problems/two-city-scheduling/ */
//A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
//Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.


int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int* diff = (int*)malloc(sizeof(int) * costsSize);
    int sum = 0;
    for(int i = 0; i < costsSize; i++){
        diff[i] = costs[i][0] - costs[i][1];
        sum += costs[i][1];
    }
    qsort(diff, costsSize, sizeof(int), cmp);
    for(int i = 0; i < costsSize / 2; i++){
        sum += diff[i];
    }
    return sum;

}

    