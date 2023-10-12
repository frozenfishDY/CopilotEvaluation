/**https://leetcode.com/problems/arithmetic-subarrays/ */
//A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.
//For example, these are arithmetic sequences:
//1, 3, 5, 7, 9
//7, 7, 7, 7
//3, -1, -5, -9
//The following sequence is not arithmetic:
//1, 1, 2, 5, 7
//You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.
//Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.
// 
//Example 1:
//Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
//Output: [true,false,true]
//Explanation:
//In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
//In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
//In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.
//Example 2:
//Input: nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
//Output: [false,true,false,false,true,true]
// 
//Constraints:
//	n == nums.length
//	m == l.length
//	m == r.length
//	2 <= n <= 500
//	1 <= m <= 500
//	0 <= l[i] < r[i] < n
//	-105 <= nums[i] <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize){
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
        if(str[i] != str2[i])
        {
            count++;
            visited[i] = 1;
        }
    }
    if(count == 0)
    {
        return 0;
    }
    else if(count == 2)
    {
        for(i = 0; i < len; i++)
        {
            if(visited[i] == 1)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if(i == len)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}