/**https://leetcode.com/problems/fair-distribution-of-cookies/ */
//You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.
//The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.
//Return the minimum unfairness of all distributions.


int distributeCookies(int* cookies, int cookiesSize, int k){
    int dp[k][cookiesSize];
    for(int i=0;i<k;i++){
        for(int j=0;j<cookiesSize;j++){
            dp[i][j] = INT_MAX;
        }
    }
    for(int i=0;i<cookiesSize;i++){
        dp[0][i] = cookies[i];
    }
    for(int i=1;i<k;i++){
        for(int j=i;j<cookiesSize;j++){
            for(int l=i-1;l<j;l++){
                dp[i][j] = min(dp[i][j], max(dp[i-1][l], cookies[j] - cookies[l]));
            }
        }
    }
    return dp[k-1][cookiesSize-1];

}

    