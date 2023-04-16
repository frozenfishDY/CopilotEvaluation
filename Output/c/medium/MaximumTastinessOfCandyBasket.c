/**https://leetcode.com/problems/maximum-tastiness-of-candy-basket/ */
//You are given an array of positive integers price where price[i] denotes the price of the ith candy and a positive integer k.
//The store sells baskets of k distinct candies. The tastiness of a candy basket is the smallest absolute difference of the prices of any two candies in the basket.
//Return the maximum tastiness of a candy basket.


int maximumTastiness(int* price, int priceSize, int k){
    int** dp = (int**)malloc(sizeof(int*) * (k + 1));
    for(int i = 0; i <= k; i++){
        dp[i] = (int*)malloc(sizeof(int) * (priceSize + 1));
        for(int j = 0; j <= priceSize; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= k; i++){
        for(int j = i; j <= priceSize; j++){
            dp[i][j] = fmax(dp[i][j - 1], dp[i - 1][j - 1] + price[j - 1]);
            for(int l = j - 2; l >= i - 1; l--){
                dp[i][j] = fmax(dp[i][j], dp[i - 1][l] + price[j - 1] - price[l]);
            }
        }
    }
    return dp[k][priceSize];

}

    