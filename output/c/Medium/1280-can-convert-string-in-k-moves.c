/**https://leetcode.com/problems/can-convert-string-in-k-moves/ */
//Given two strings s and t, your goal is to convert s into t in k moves or less.
//During the ith (1 <= i <= k) move you can:
//	Choose any index j (1-indexed) from s, such that 1 <= j <= s.length and j has not been chosen in any previous move, and shift the character at that index i times.
//	Do nothing.
//Shifting a character means replacing it by the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Shifting a character by i means applying the shift operations i times.
//Remember that any index j can be picked at most once.
//Return true if it's possible to convert s into t in no more than k moves, otherwise return false.
// 
//Example 1:
//Input: s = "input", t = "ouput", k = 9
//Output: true
//Explanation: In the 6th move, we shift 'i' 6 times to get 'o'. And in the 7th move we shift 'n' to get 'u'.
//Example 2:
//Input: s = "abc", t = "bcd", k = 10
//Output: false
//Explanation: We need to shift each character in s one time to convert it into t. We can shift 'a' to 'b' during the 1st move. However, there is no way to shift the other characters in the remaining moves to obtain t from s.
//Example 3:
//Input: s = "aab", t = "bbb", k = 27
//Output: true
//Explanation: In the 1st move, we shift the first 'a' 1 time to get 'b'. In the 27th move, we shift the second 'a' 27 times to get 'b'.
// 
//Constraints:
//	1 <= s.length, t.length <= 10^5
//	0 <= k <= 10^9
//	s, t contain only lowercase English letters.
bool canConvertString(char * s, char * t, int k){
n = len(grid)
        res = 0
        for i in range(n):
            zeros = 0
            for j in range(n - 1, -1, -1):
                if grid[i][j] == 0:
                    zeros += 1
                else:
                    break
            if zeros < n - i - 1:
                j = i + 1
                while j < n and zeros < n - i - 1:
                    if grid[j][i] == 0:
                        zeros += 1
                        res += 1
                    else:
                        j += 1
                if zeros < n - i - 1:
                    return -1
        return res
}