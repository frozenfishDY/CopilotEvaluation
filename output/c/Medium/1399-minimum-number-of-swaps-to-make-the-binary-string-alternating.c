/**https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/ */
//Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.
//The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
//Any two characters may be swapped, even if they are not adjacent.
// 
//Example 1:
//Input: s = "111000"
//Output: 1
//Explanation: Swap positions 1 and 4: "111000" -> "101010"
//The string is now alternating.
//Example 2:
//Input: s = "010"
//Output: 0
//Explanation: The string is already alternating, no swaps are needed.
//Example 3:
//Input: s = "1110"
//Output: -1
// 
//Constraints:
//	1 <= s.length <= 1000
//	s[i] is either '0' or '1'.
int minSwaps(char * s){
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
    if(abs(count - len / 2) > 1)
    {
        return -1;
    }
    if(count > len / 2)
    {
        for(i = 0; i < len; i++)
        {
            if(i % 2 == 0 && str[i] == 'b')
            {
                flag++;
            }
            else if(i % 2 == 1 && str[i] == 'a')
            {
                flag++;
            }
        }
        if(flag % 2 == 0)
        {
            return flag / 2;
        }
        else
        {
            return flag / 2 + 1;
        }
    }
    else if(count < len / 2)
    {
        for(i = 0; i < len; i++)
        {
            if(i % 2 == 0 && str[i] == 'a')
            {
                flag++;
            }
            else if(i % 2 == 1 && str[i] == 'b')
            {
                flag++;
            }
        }
        if(flag % 2 == 0)
        {
            return flag / 2;
        }
        else
        {
            return flag / 2 + 1;
        }
    }
    else
    {
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
                count++;
            }
        }
        return count / 2;
    }
}