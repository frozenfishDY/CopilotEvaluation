/**https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/ */
//Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:
//	Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
//	Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
//	The prefix and the suffix should not intersect at any index.
//	The characters from the prefix and suffix must be the same.
//	Delete both the prefix and the suffix.
//Return the minimum length of s after performing the above operation any number of times (possibly zero times).
// 
//Example 1:
//Input: s = "ca"
//Output: 2
//Explanation: You can't remove any characters, so the string stays as is.
//Example 2:
//Input: s = "cabaabac"
//Output: 0
//Explanation: An optimal sequence of operations is:
//- Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
//- Take prefix = "a" and suffix = "a" and remove them, s = "baab".
//- Take prefix = "b" and suffix = "b" and remove them, s = "aa".
//- Take prefix = "a" and suffix = "a" and remove them, s = "".
//Example 3:
//Input: s = "aabccabba"
//Output: 3
//Explanation: An optimal sequence of operations is:
//- Take prefix = "aa" and suffix = "a" and remove them, s = "bccabb".
//- Take prefix = "b" and suffix = "bb" and remove them, s = "cca".
// 
//Constraints:
//	1 <= s.length <= 105
//	s only consists of characters 'a', 'b', and 'c'.
int minimumLength(char * s){
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
            break;
        }
    }
    for(j = len - 1; j >= 0; j--)
    {
        if(str[j] == 'b')
        {
            break;
        }
    }
    if(i == j)
    {
        return 0;
    }
    for(k = i; k <= j; k++)
    {
        if(str[k] != 'b')
        {
            flag = 1;
        }
    }
    if(flag == 0)
    {
        return 0;
    }
    return len - count;
}