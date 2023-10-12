/**https://leetcode.com/problems/incremental-memory-leak/ */
//You are given two integers memory1 and memory2 representing the available memory in bits on two memory sticks. There is currently a faulty program running that consumes an increasing amount of memory every second.
//At the ith second (starting from 1), i bits of memory are allocated to the stick with more available memory (or from the first memory stick if both have the same available memory). If neither stick has at least i bits of available memory, the program crashes.
//Return an array containing [crashTime, memory1crash, memory2crash], where crashTime is the time (in seconds) when the program crashed and memory1crash and memory2crash are the available bits of memory in the first and second sticks respectively.
// 
//Example 1:
//Input: memory1 = 2, memory2 = 2
//Output: [3,1,0]
//Explanation: The memory is allocated as follows:
//- At the 1st second, 1 bit of memory is allocated to stick 1. The first stick now has 1 bit of available memory.
//- At the 2nd second, 2 bits of memory are allocated to stick 2. The second stick now has 0 bits of available memory.
//- At the 3rd second, the program crashes. The sticks have 1 and 0 bits available respectively.
//Example 2:
//Input: memory1 = 8, memory2 = 11
//Output: [6,0,4]
//Explanation: The memory is allocated as follows:
//- At the 1st second, 1 bit of memory is allocated to stick 2. The second stick now has 10 bit of available memory.
//- At the 2nd second, 2 bits of memory are allocated to stick 2. The second stick now has 8 bits of available memory.
//- At the 3rd second, 3 bits of memory are allocated to stick 1. The first stick now has 5 bits of available memory.
//- At the 4th second, 4 bits of memory are allocated to stick 2. The second stick now has 4 bits of available memory.
//- At the 5th second, 5 bits of memory are allocated to stick 1. The first stick now has 0 bits of available memory.
//- At the 6th second, the program crashes. The sticks have 0 and 4 bits available respectively.
// 
//Constraints:
//	0 <= memory1, memory2 <= 231 - 1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* memLeak(int memory1, int memory2, int* returnSize){
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