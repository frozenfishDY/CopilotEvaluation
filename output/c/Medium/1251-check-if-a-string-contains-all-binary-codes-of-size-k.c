/**https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/ */
//Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
// 
//Example 1:
//Input: s = "00110110", k = 2
//Output: true
//Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
//Example 2:
//Input: s = "0110", k = 1
//Output: true
//Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
//Example 3:
//Input: s = "0110", k = 2
//Output: false
//Explanation: The binary code "00" is of length 2 and does not exist in the array.
// 
//Constraints:
//	1 <= s.length <= 5 * 105
//	s[i] is either '0' or '1'.
//	1 <= k <= 20
bool hasAllCodes(char * s, int k){
int len = strlen(s);
    if (len <= k) {
        return false;
    }
    int max = 1 << k;
    int *count = calloc(max, sizeof(int));
    int countIndex = 0;
    for (int i = 0; i < k; i++) {
        countIndex = (countIndex << 1) + (s[i] - '0');
    }
    count[countIndex] = 1;
    for (int i = k; i < len; i++) {
        countIndex = ((countIndex << 1) + (s[i] - '0')) % max;
        count[countIndex] = 1;
    }
    for (int i = 0; i < max; i++) {
        if (count[i] == 0) {
            return false;
        }
    }
    return true;
}