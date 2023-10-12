/**https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/ */
//The numeric value of a lowercase character is defined as its position (1-indexed) in the alphabet, so the numeric value of a is 1, the numeric value of b is 2, the numeric value of c is 3, and so on.
//The numeric value of a string consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string "abe" is equal to 1 + 2 + 5 = 8.
//You are given two integers n and k. Return the lexicographically smallest string with length equal to n and numeric value equal to k.
//Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.
// 
//Example 1:
//Input: n = 3, k = 27
//Output: "aay"
//Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.
//Example 2:
//Input: n = 5, k = 73
//Output: "aaszz"
// 
//Constraints:
//	1 <= n <= 105
//	n <= k <= 26 * n
char * getSmallestString(int n, int k){
char* result = (char*)malloc(sizeof(char) * n + 1);
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
        if(str[i] == 'b')
        {
            count++;
        }
    }
    for(i = 0; i < len; i++)
    {
        if(str[i] == 'b')
        {
            if(count > 0)
            {
                count--;
                visited[i] = 1;
            }
        }
    }
    for(i = 0; i < len; i++)
    {
        if(visited[i] == 0)
        {
            result[j++] = str[i];
        }
    }
    return result;
}