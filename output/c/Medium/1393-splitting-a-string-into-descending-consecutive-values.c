/**https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/ */
//You are given a string s that consists of only digits.
//Check if we can split s into two or more non-empty substrings such that the numerical values of the substrings are in descending order and the difference between numerical values of every two adjacent substrings is equal to 1.
//	For example, the string s = "0090089" can be split into ["0090", "089"] with numerical values [90,89]. The values are in descending order and adjacent values differ by 1, so this way is valid.
//	Another example, the string s = "001" can be split into ["0", "01"], ["00", "1"], or ["0", "0", "1"]. However all the ways are invalid because they have numerical values [0,1], [0,1], and [0,0,1] respectively, all of which are not in descending order.
//Return true if it is possible to split s​​​​​​ as described above, or false otherwise.
//A substring is a contiguous sequence of characters in a string.
// 
//Example 1:
//Input: s = "1234"
//Output: false
//Explanation: There is no valid way to split s.
//Example 2:
//Input: s = "050043"
//Output: true
//Explanation: s can be split into ["05", "004", "3"] with numerical values [5,4,3].
//The values are in descending order with adjacent values differing by 1.
//Example 3:
//Input: s = "9080701"
//Output: false
//Explanation: There is no valid way to split s.
// 
//Constraints:
//	1 <= s.length <= 20
//	s only consists of digits.
bool splitString(char * s){
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
    if(count == len)
    {
        return true;
    }
    for(i = 0; i < len; i++)
    {
        if(str[i] == 'a')
        {
            for(j = i; j < len; j++)
            {
                if(str[j] == 'b')
                {
                    tmp = j;
                    break;
                }
            }
            for(k = tmp; k < len; k++)
            {
                if(str[k] == 'a')
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                return false;
            }
            else
            {
                flag = 0;
            }
        }
    }
    return true;
}