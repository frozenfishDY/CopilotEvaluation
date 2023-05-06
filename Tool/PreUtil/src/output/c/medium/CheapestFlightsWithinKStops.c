/**https://leetcode.com/problems/cheapest-flights-within-k-stops/ */
//There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
//You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.


int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k){
    int* cost = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        cost[i] = INT_MAX;
    }
    cost[src] = 0;
    for(int i = 0; i <= k; i++){
        int* temp = (int*)malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++){
            temp[j] = cost[j];
        }
        for(int j = 0; j < flightsSize; j++){
            int from = flights[j][0];
            int to = flights[j][1];
            int price = flights[j][2];
            if(cost[from] != INT_MAX && temp[to] > cost[from] + price){
                temp[to] = cost[from] + price;
            }
        }
        cost = temp;
    }
    return cost[dst] == INT_MAX ? -1 : cost[dst];

}

    