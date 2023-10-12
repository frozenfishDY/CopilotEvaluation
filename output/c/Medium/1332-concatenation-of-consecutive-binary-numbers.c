/**https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/ */
//Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.
// 
//Example 1:
//Input: n = 1
//Output: 1
//Explanation: "1" in binary corresponds to the decimal value 1. 
//Example 2:
//Input: n = 3
//Output: 27
//Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
//After concatenating them, we have "11011", which corresponds to the decimal value 27.
//Example 3:
//Input: n = 12
//Output: 505379714
//Explanation: The concatenation results in "1101110010111011110001001101010111100".
//The decimal value of that is 118505380540.
//After modulo 109 + 7, the result is 505379714.
// 
//Constraints:
//	1 <= n <= 105


int concatenatedBinary(int n){
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
                result[i] = j + '0';
                break;
            }
        }
    }
    return result;

}