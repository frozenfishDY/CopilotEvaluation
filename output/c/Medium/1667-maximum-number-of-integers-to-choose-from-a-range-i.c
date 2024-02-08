/**https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/ */
//You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:
//The chosen integers have to be in the range [1, n].
//Each integer can be chosen at most once.
//The chosen integers should not be in the array banned.
//The sum of the chosen integers should not exceed maxSum.
//Return the maximum number of integers you can choose following the mentioned rules.


int maxCount(int* banned, int bannedSize, int n, int maxSum){
    int* count = (int*)calloc(n + 1, sizeof(int));
    for(int i = 0; i < bannedSize; i++){
        count[banned[i]] = -1;
    }
    count[0] = 0;
    for(int i = 1; i <= n; i++){
        if(count[i] == -1){
            continue;
        }
        for(int j = 0; j < i; j++){
            if(count[j] != -1 && count[j] + i <= maxSum){
                if(count[i] == -1 || count[i] > count[j] + 1){
                    count[i] = count[j] + 1;
                }
            }
        }
    }
    return count[n];

}

    