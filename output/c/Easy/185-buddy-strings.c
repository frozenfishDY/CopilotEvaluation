/**https://leetcode.com/problems/buddy-strings/ */
//Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
//Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
//	For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
// 
//Example 1:
//Input: s = "ab", goal = "ba"
//Output: true
//Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
//Example 2:
//Input: s = "ab", goal = "ab"
//Output: false
//Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
//Example 3:
//Input: s = "aa", goal = "aa"
//Output: true
//Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
// 
//Constraints:
//	1 <= s.length, goal.length <= 2 * 104
//	s and goal consist of lowercase letters.
bool buddyStrings(char * s, char * goal){
        int len_s = strlen(s);
    int len_g = strlen(goal);
    if(len_s != len_g){
        return false;
    }
    int diff = 0;
    int diff_index[2];
    for(int i = 0; i < len_s; i++){
        if(s[i] != goal[i]){
            diff++;
            if(diff > 2){
                return false;
            }
            diff_index[diff - 1] = i;
        }
    }
    if(diff == 0){
        int repeat[26] = {0};
        for(int i = 0; i < len_s; i++){
            if(repeat[s[i] - 'a'] == 1){
                return true;
            }
            repeat[s[i] - 'a']++;
        }
        return false;
    }
    if(diff == 2){
        if(s[diff_index[0]] == goal[diff_index[1]] && s[diff_index[1]] == goal[diff_index[0]]){
            return true;
        }
    }
    return false;
}