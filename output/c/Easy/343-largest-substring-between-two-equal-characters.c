/**https://leetcode.com/problems/largest-substring-between-two-equal-characters/ */
//Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "aa"
//Output: 0
//Explanation: The optimal substring here is an empty substring between the two 'a's.
//Example 2:
//Input: s = "abca"
//Output: 2
//Explanation: The optimal substring here is "bc".
//Example 3:
//Input: s = "cbzxy"
//Output: -1
//Explanation: There are no characters that appear twice in s.
// 
//Constraints:
//	1 <= s.length <= 300
//	s contains only lowercase English letters.
int maxLengthBetweenEqualCharacters(char * s){
int i, j, k, l, m, n = 0;
    for(i = 0; i < strlen(s); i++){
        for(j = i + 1; j < strlen(s); j++){
            if(s[i] == s[j]){
                k = j - i - 1;
                if(k > n)
                    n = k;
            }
        }
    }
    if(n == 0)
        return -1;
    return n;
}