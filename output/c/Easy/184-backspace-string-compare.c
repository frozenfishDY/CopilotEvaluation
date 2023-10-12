/**https://leetcode.com/problems/backspace-string-compare/ */
//Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
//Note that after backspacing an empty text, the text will continue empty.
// 
//Example 1:
//Input: s = "ab#c", t = "ad#c"
//Output: true
//Explanation: Both s and t become "ac".
//Example 2:
//Input: s = "ab##", t = "c#d#"
//Output: true
//Explanation: Both s and t become "".
//Example 3:
//Input: s = "a#c", t = "b"
//Output: false
//Explanation: s becomes "c" while t becomes "b".
// 
//Constraints:
//	1 <= s.length, t.length <= 200
//	s and t only contain lowercase letters and '#' characters.
// 
//Follow up: Can you solve it in O(n) time and O(1) space?
bool backspaceCompare(char * s, char * t){
int i = 0;
    int j = 0;
    int len = strlen(s);
    int len_t = strlen(t);
    while(i < len){
        if(s[i] == '#'){
            if(i > 0){
                int k = i;
                while(k < len){
                    s[k - 1] = s[k];
                    k++;
                }
                len--;
                i--;
            }
        }
        i++;
    }
    while(j < len_t){
        if(t[j] == '#'){
            if(j > 0){
                int k = j;
                while(k < len_t){
                    t[k - 1] = t[k];
                    k++;
                }
                len_t--;
                j--;
            }
        }
        j++;
    }
    if(len != len_t){
        return false;
    }
    for(int m = 0; m < len; m++){
        if(s[m] != t[m]){
            return false;
        }
    }
    return true;
}