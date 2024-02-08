/**https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/ */
//You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
//Find the maximum profit you can achieve. You may complete at most k transactions.
//Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


int maxProfit(int k, int* prices, int pricesSize){
    if(pricesSize < 2) return 0;
    if(k >= pricesSize / 2){
        int profit = 0;
        for(int i = 1; i < pricesSize; i++){
            if(prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
    int* buy = (int*)malloc(sizeof(int) * k);
    int* sell = (int*)malloc(sizeof(int) * k);
    for(int i = 0; i < k; i++){
        buy[i] = INT_MIN;
        sell[i] = 0;
    }
    for(int i = 0; i < pricesSize; i++){
        buy[0] = fmax(buy[0], -prices[i]);
        sell[0] = fmax(sell[0], buy[0] + prices[i]);
        for(int j = 1; j < k; j++){
            buy[j] = fmax(buy[j], sell[j - 1] - prices[i]);
            sell[j] = fmax(sell[j], buy[j] + prices[i]);
        }
    }
    return sell[k - 1];

}

    