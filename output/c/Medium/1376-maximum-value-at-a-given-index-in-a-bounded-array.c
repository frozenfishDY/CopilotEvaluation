/**https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/ */
//You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:
//	nums.length == n
//	nums[i] is a positive integer where 0 <= i < n.
//	abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
//	The sum of all the elements of nums does not exceed maxSum.
//	nums[index] is maximized.
//Return nums[index] of the constructed array.
//Note that abs(x) equals x if x >= 0, and -x otherwise.
// 
//Example 1:
//Input: n = 4, index = 2,  maxSum = 6
//Output: 2
//Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
//There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].
//Example 2:
//Input: n = 6, index = 1,  maxSum = 10
//Output: 3
// 
//Constraints:
//	1 <= n <= maxSum <= 109
//	0 <= index < n
int maxValue(int n, int index, int maxSum){
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
            flag = 1;
            break;
        }
    }
    free(visited);
    free(str);
    free(str2);
    if(flag == 1)
    {
        return false;
    }
    else
    {
        return true;
    }

}