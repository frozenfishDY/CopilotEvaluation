/**https://leetcode.com/problems/max-number-of-k-sum-pairs/ */
//You are given an integer array nums and an integer k.
//In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
//Return the maximum number of operations you can perform on the array.
// 
//Example 1:
//Input: nums = [1,2,3,4], k = 5
//Output: 2
//Explanation: Starting with nums = [1,2,3,4]:
//- Remove numbers 1 and 4, then nums = [2,3]
//- Remove numbers 2 and 3, then nums = []
//There are no more pairs that sum up to 5, hence a total of 2 operations.
//Example 2:
//Input: nums = [3,1,3,4,3], k = 6
//Output: 1
//Explanation: Starting with nums = [3,1,3,4,3]:
//- Remove the first two 3's, then nums = [1,4,3]
//There are no more pairs that sum up to 6, hence a total of 1 operation.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 109
//	1 <= k <= 109


int maxOperations(int* nums, int numsSize, int k){
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
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            count++;
        }
        flag = 0;
    }
    return count;
}