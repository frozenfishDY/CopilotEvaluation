/**https://leetcode.com/problems/count-sorted-vowel-strings/ */
//Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.
//A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.
// 
//Example 1:
//Input: n = 1
//Output: 5
//Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
//Example 2:
//Input: n = 2
//Output: 15
//Explanation: The 15 sorted strings that consist of vowels only are
//["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
//Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
//Example 3:
//Input: n = 33
//Output: 66045
// 
//Constraints:
//	1 <= n <= 50 
int countVowelStrings(int n){
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
                str[i] = j + 'a';
                break;
            }
        }
    }
    for(i = 0; i < len; i++)
    {
        if(str[i] != str2[i])
        {
            count++;
        }
    }
    return count;
}