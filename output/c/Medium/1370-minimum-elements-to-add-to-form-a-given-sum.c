/**https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/ */
//You are given an integer array nums and two integers limit and goal. The array nums has an interesting property that abs(nums[i]) <= limit.
//Return the minimum number of elements you need to add to make the sum of the array equal to goal. The array must maintain its property that abs(nums[i]) <= limit.
//Note that abs(x) equals x if x >= 0, and -x otherwise.
// 
//Example 1:
//Input: nums = [1,-1,1], limit = 3, goal = -4
//Output: 2
//Explanation: You can add -2 and -3, then the sum of the array will be 1 - 1 + 1 - 2 - 3 = -4.
//Example 2:
//Input: nums = [1,-10,9,1], limit = 100, goal = 0
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= limit <= 106
//	-limit <= nums[i] <= limit
//	-109 <= goal <= 109
int minElements(int* nums, int numsSize, int limit, int goal){
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
    free(visited);
    free(str);
    free(str2);
    return count;
}