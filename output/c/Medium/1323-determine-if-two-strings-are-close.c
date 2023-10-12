/**https://leetcode.com/problems/determine-if-two-strings-are-close/ */
//Two strings are considered close if you can attain one from the other using the following operations:
//	Operation 1: Swap any two existing characters.
//	
//		For example, abcde -> aecdb
//	
//	
//	Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
//	
//		For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
//	
//	
//You can use the operations on either string as many times as necessary.
//Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
// 
//Example 1:
//Input: word1 = "abc", word2 = "bca"
//Output: true
//Explanation: You can attain word2 from word1 in 2 operations.
//Apply Operation 1: "abc" -> "acb"
//Apply Operation 1: "acb" -> "bca"
//Example 2:
//Input: word1 = "a", word2 = "aa"
//Output: false
//Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
//Example 3:
//Input: word1 = "cabbba", word2 = "abbccc"
//Output: true
//Explanation: You can attain word2 from word1 in 3 operations.
//Apply Operation 1: "cabbba" -> "caabbb"
//Apply Operation 2: "caabbb" -> "baaccc"
//Apply Operation 2: "baaccc" -> "abbccc"
// 
//Constraints:
//	1 <= word1.length, word2.length <= 105
//	word1 and word2 contain only lowercase English letters.
bool closeStrings(char * word1, char * word2){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int *a1 = (int*)malloc(sizeof(int) * 26);
    int *a2 = (int*)malloc(sizeof(int) * 26);
    memset(a1, 0, sizeof(int) * 26);
    memset(a2, 0, sizeof(int) * 26);
    for(i = 0; i < len1; i++)
    {
        a1[word1[i] - 'a']++;
    }
    for(i = 0; i < len2; i++)
    {
        a2[word2[i] - 'a']++;
    }
    for(i = 0; i < 26; i++)
    {
        if((a1[i] == 0 && a2[i] != 0) || (a1[i] != 0 && a2[i] == 0))
        {
            return false;
        }
    }
    for(i = 0; i < 26; i++)
    {
        for(j = i + 1; j < 26; j++)
        {
            if(a1[i] < a1[j])
            {
                k = a1[i];
                a1[i] = a1[j];
                a1[j] = k;
            }
            if(a2[i] < a2[j])
            {
                k = a2[i];
                a2[i] = a2[j];
                a2[j] = k;
            }
        }
    }
    for(i = 0; i < 26; i++)
    {
        if(a1[i] != a2[i])
        {
            return false;
        }
    }
    return true;
}