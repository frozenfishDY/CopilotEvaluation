/**https://leetcode.com/problems/total-cost-to-hire-k-workers/ */
//You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.
//You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:
//You will run k sessions and hire exactly one worker in each session.
//In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
//For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
//In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
//If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
//A worker can only be chosen once.
//Return the total cost to hire exactly k workers.


long long totalCost(int* costs, int costsSize, int k, int candidates){
    long long int i, j, k, count = 0;
    int temp;
    for(i = 0; i < costsSize - 1; i++){
        for(j = i + 1; j < costsSize; j++){
            if(costs[i] > costs[j]){
                temp = costs[i];
                costs[i] = costs[j];
                costs[j] = temp;
            }
        }
    }
    for(i = 0; i < k; i++){
        count += costs[i];
    }
    return count;

}

    