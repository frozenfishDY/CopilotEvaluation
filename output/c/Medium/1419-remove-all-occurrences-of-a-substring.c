/**https://leetcode.com/problems/remove-all-occurrences-of-a-substring/ */
//Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
//	Find the leftmost occurrence of the substring part and remove it from s.
//Return s after removing all occurrences of part.
//A substring is a contiguous sequence of characters in a string.
// 
//Example 1:
//Input: s = "daabcbaabcbc", part = "abc"
//Output: "dab"
//Explanation: The following operations are done:
//- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
//- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
//- s = "dababc", remove "abc" starting at index 3, so s = "dab".
//Now s has no occurrences of "abc".
//Example 2:
//Input: s = "axxxxyyyyb", part = "xy"
//Output: "ab"
//Explanation: The following operations are done:
//- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
//- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
//- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
//- s = "axyb", remove "xy" starting at index 1 so s = "ab".
//Now s has no occurrences of "xy".
// 
//Constraints:
//	1 <= s.length <= 1000
//	1 <= part.length <= 1000
//	s​​​​​​ and part consists of lowercase English letters.
char * removeOccurrences(char * s, char * part){
int len1=strlen(s);
    int len2=strlen(part);
    int i;
    int j;
    int flag=0;
    while(1){
        flag=0;
        for(i=0;i<len1;i++){
            if(s[i]==part[0]){
                for(j=1;j<len2;j++){
                    if(s[i+j]!=part[j]){
                        break;
                    }
                }
                if(j==len2){
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){
            break;
        }else{
            for(j=i;j<len1;j++){
                s[j]=s[j+len2];
            }
        }
    }
    return s;
}