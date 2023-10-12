/**https://leetcode.com/problems/reverse-only-letters/ */
//Given a string s, reverse the string according to the following rules:
//	All the characters that are not English letters remain in the same position.
//	All the English letters (lowercase or uppercase) should be reversed.
//Return s after reversing it.
// 
//Example 1:
//Input: s = "ab-cd"
//Output: "dc-ba"
//Example 2:
//Input: s = "a-bC-dEf-ghIj"
//Output: "j-Ih-gfE-dCba"
//Example 3:
//Input: s = "Test1ng-Leet=code-Q!"
//Output: "Qedo1ct-eeLg=ntse-T!"
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of characters with ASCII values in the range [33, 122].
//	s does not contain '\"' or '\\'.
char * reverseOnlyLetters(char * s){
int len = strlen(s);
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    int i = 0;
    int j = len - 1;
    while(i < len){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            while(j >= 0){
                if(s[j] >= 'A' && s[j] <= 'Z'){
                    res[i] = s[j];
                    j--;
                    break;
                }
                j--;
            }
        }else if(s[i] >= 'a' && s[i] <= 'z'){
            while(j >= 0){
                if(s[j] >= 'a' && s[j] <= 'z'){
                    res[i] = s[j];
                    j--;
                    break;
                }
                j--;
            }
        }else{
            res[i] = s[i];
        }
        i++;
    }
    res[len] = '\0';
    return res;
}