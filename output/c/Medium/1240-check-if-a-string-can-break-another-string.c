/**https://leetcode.com/problems/check-if-a-string-can-break-another-string/ */
//Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can break some permutation of string s2 or vice-versa. In other words s2 can break s1 or vice-versa.
//A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) for all i between 0 and n-1.
// 
//Example 1:
//Input: s1 = "abc", s2 = "xya"
//Output: true
//Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".
//Example 2:
//Input: s1 = "abe", s2 = "acd"
//Output: false 
//Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab" and "eba" and all permutation for s2="acd" are: "acd", "adc", "cad", "cda", "dac" and "dca". However, there is not any permutation from s1 which can break some permutation from s2 and vice-versa.
//Example 3:
//Input: s1 = "leetcodee", s2 = "interview"
//Output: true
// 
//Constraints:
//	s1.length == n
//	s2.length == n
//	1 <= n <= 10^5
//	All strings consist of lowercase English letters.
bool checkIfCanBreak(char * s1, char * s2){
int i, j, k, max, max_index;
    int *s1_count = (int *)malloc(sizeof(int) * 26);
    int *s2_count = (int *)malloc(sizeof(int) * 26);
    memset(s1_count, 0, sizeof(int) * 26);
    memset(s2_count, 0, sizeof(int) * 26);
    for(i = 0; i < strlen(s1); i++)
    {
        s1_count[s1[i] - 'a']++;
    }
    for(i = 0; i < strlen(s2); i++)
    {
        s2_count[s2[i] - 'a']++;
    }
    for(i = 0; i < 26; i++)
    {
        if(s1_count[i] > s2_count[i])
        {
            max = 0;
            max_index = 0;
            for(j = 0; j < 26; j++)
            {
                if(s2_count[j] > max)
                {
                    max = s2_count[j];
                    max_index = j;
                }
            }
            s2_count[max_index] = 0;
            s1_count[i] -= max;
            i--;
        }
        else if(s1_count[i] < s2_count[i])
        {
            max = 0;
            max_index = 0;
            for(j = 0; j < 26; j++)
            {
                if(s1_count[j] > max)
                {
                    max = s1_count[j];
                    max_index = j;
                }
            }
            s1_count[max_index] = 0;
            s2_count[i] -= max;
            i--;
        }
    }
    for(i = 0; i < 26; i++)
    {
        if(s1_count[i] != s2_count[i])
        {
            return false;
        }
    }
    return true;
}