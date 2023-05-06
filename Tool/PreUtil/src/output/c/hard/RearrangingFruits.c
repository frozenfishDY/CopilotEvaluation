/**https://leetcode.com/problems/rearranging-fruits/ */
//You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:
//Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
//The cost of the swap is min(basket1[i],basket2[j]).
//Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.
//Return the minimum cost to make both the baskets equal or -1 if impossible.


long long minCost(int* basket1, int basket1Size, int* basket2, int basket2Size){
    long long result = 0;
    int* queue = (int*)malloc(sizeof(int) * basket1Size);
    int head = 0, tail = 0;
    for(int i = 0; i < basket1Size; i++){
        while(head < tail && basket1[queue[tail - 1]] < basket1[i]) tail--;
        queue[tail++] = i;
        if(i - queue[head] >= k) head++;
        if(i >= k - 1) result += basket1[queue[head]];
    }
    return result;

}

    