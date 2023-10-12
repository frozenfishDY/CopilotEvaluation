/**https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/ */
//You are given an integer array coins of length n which represents the n coins that you own. The value of the ith coin is coins[i]. You can make some value x if you can choose some of your n coins such that their values sum up to x.
//Return the maximum number of consecutive integer values that you can make with your coins starting from and including 0.
//Note that you may have multiple coins of the same value.
// 
//Example 1:
//Input: coins = [1,3]
//Output: 2
//Explanation: You can make the following values:
//- 0: take []
//- 1: take [1]
//You can make 2 consecutive integer values starting from 0.
//Example 2:
//Input: coins = [1,1,1,4]
//Output: 8
//Explanation: You can make the following values:
//- 0: take []
//- 1: take [1]
//- 2: take [1,1]
//- 3: take [1,1,1]
//- 4: take [4]
//- 5: take [4,1]
//- 6: take [4,1,1]
//- 7: take [4,1,1,1]
//You can make 8 consecutive integer values starting from 0.
//Example 3:
//Input: nums = [1,4,10,3,1]
//Output: 20
// 
//Constraints:
//	coins.length == n
//	1 <= n <= 4 * 104
//	1 <= coins[i] <= 4 * 104
int getMaximumConsecutive(int* coins, int coinsSize){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int len = strlen(s);
    int min = 0;
    int tmp = 0;
    int count = 0;
    int flag = 0;
    int *visited = (int*)malloc(sizeof(int) * len);
    memset(visited, 0, sizeof(int) * len);
    char *str = (char*)malloc(sizeof(char) * len + 1);
    strcpy(str, s);
    char *str2 = (char*)malloc(sizeof(char) * len + 1);
    strcpy(str2, s);
    for(i = 0; i < len; i++)
    {
        min = i;
        for(j = i + 1; j < len; j++)
        {
            if(str[j] < str[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            tmp = str[i];
            str[i] = str[min];
            str[min] = tmp;
        }
    }
    for(i = 0; i < len; i++)
    {
        for(j = 0; j < len; j++)
        {
            if(str[i] == str2[j] && visited[j] == 0)
            {
                visited[j] = 1;
                count++;
                break;
            }
        }
    }
    return count;
}