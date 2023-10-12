/**https://leetcode.com/problems/maximum-ice-cream-bars/ */
//It is a sweltering summer day, and a boy wants to buy some ice cream bars.
//At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 
//Note: The boy can buy the ice cream bars in any order.
//Return the maximum number of ice cream bars the boy can buy with coins coins.
//You must solve the problem by counting sort.
// 
//Example 1:
//Input: costs = [1,3,2,4,1], coins = 7
//Output: 4
//Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
//Example 2:
//Input: costs = [10,6,8,7,7,8], coins = 5
//Output: 0
//Explanation: The boy cannot afford any of the ice cream bars.
//Example 3:
//Input: costs = [1,6,3,1,2,5], coins = 20
//Output: 6
//Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
// 
//Constraints:
//	costs.length == n
//	1 <= n <= 105
//	1 <= costs[i] <= 105
//	1 <= coins <= 108


int maxIceCream(int* costs, int costsSize, int coins){
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
                if(i != j)
                {
                    count++;
                }
                break;
            }
        }
    }
    return count;
}