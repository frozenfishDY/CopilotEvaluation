/**https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/ */
//Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.
//An integer y is a power of three if there exists an integer x such that y == 3x.
// 
//Example 1:
//Input: n = 12
//Output: true
//Explanation: 12 = 31 + 32
//Example 2:
//Input: n = 91
//Output: true
//Explanation: 91 = 30 + 32 + 34
//Example 3:
//Input: n = 21
//Output: false
// 
//Constraints:
//	1 <= n <= 107
bool checkPowersOfThree(int n){
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
        if(j == len)
        {
            count++;
        }
    }
    return count;
}