/**https://leetcode.com/problems/sell-diminishing-valued-colored-balls/ */
//You have an inventory of different colored balls, and there is a customer that wants orders balls of any color.
//The customer weirdly values the colored balls. Each colored ball's value is the number of balls of that color you currently have in your inventory. For example, if you own 6 yellow balls, the customer would pay 6 for the first yellow ball. After the transaction, there are only 5 yellow balls left, so the next yellow ball is then valued at 5 (i.e., the value of the balls decreases as you sell more to the customer).
//You are given an integer array, inventory, where inventory[i] represents the number of balls of the ith color that you initially own. You are also given an integer orders, which represents the total number of balls that the customer wants. You can sell the balls in any order.
//Return the maximum total value that you can attain after selling orders colored balls. As the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: inventory = [2,5], orders = 4
//Output: 14
//Explanation: Sell the 1st color 1 time (2) and the 2nd color 3 times (5 + 4 + 3).
//The maximum total value is 2 + 5 + 4 + 3 = 14.
//Example 2:
//Input: inventory = [3,5], orders = 6
//Output: 19
//Explanation: Sell the 1st color 2 times (3 + 2) and the 2nd color 4 times (5 + 4 + 3 + 2).
//The maximum total value is 3 + 2 + 5 + 4 + 3 + 2 = 19.
// 
//Constraints:
//	1 <= inventory.length <= 105
//	1 <= inventory[i] <= 109
//	1 <= orders <= min(sum(inventory[i]), 109)
int maxProfit(int* inventory, int inventorySize, int orders){
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
                break;
            }
        }
    }
    for(i = 0; i < len; i++)
    {
        if(visited[i] == 0)
        {
            count++;
        }
    }
    return count;
}