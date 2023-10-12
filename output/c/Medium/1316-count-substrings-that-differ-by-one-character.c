/**https://leetcode.com/problems/count-substrings-that-differ-by-one-character/ */
//Given two strings s and t, find the number of ways you can choose a non-empty substring of s and replace a single character by a different character such that the resulting substring is a substring of t. In other words, find the number of substrings in s that differ from some substring in t by exactly one character.
//For example, the underlined substrings in "computer" and "computation" only differ by the 'e'/'a', so this is a valid way.
//Return the number of substrings that satisfy the condition above.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "aba", t = "baba"
//Output: 6
//Explanation: The following are the pairs of substrings from s and t that differ by exactly 1 character:
//("aba", "baba")
//("aba", "baba")
//("aba", "baba")
//("aba", "baba")
//("aba", "baba")
//("aba", "baba")
//The underlined portions are the substrings that are chosen from s and t.
//​​Example 2:
//Input: s = "ab", t = "bb"
//Output: 3
//Explanation: The following are the pairs of substrings from s and t that differ by 1 character:
//("ab", "bb")
//("ab", "bb")
//("ab", "bb")
//​​​​The underlined portions are the substrings that are chosen from s and t.
// 
//Constraints:
//	1 <= s.length, t.length <= 100
//	s and t consist of lowercase English letters only.
int countSubstrings(char * s, char * t){
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
                count++;
                break;
            }
        }
    }
    return count;
}