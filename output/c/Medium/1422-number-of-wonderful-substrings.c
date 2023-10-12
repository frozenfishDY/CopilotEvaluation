/**https://leetcode.com/problems/number-of-wonderful-substrings/ */
//A wonderful string is a string where at most one letter appears an odd number of times._x000D_
//_x000D_
//_x000D_
//	For example, "ccjjc" and "abab" are wonderful, but "ab" is not._x000D_
//_x000D_
//_x000D_
//Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately._x000D_
//_x000D_
//A substring is a contiguous sequence of characters in a string._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: word = "aba"_x000D_
//Output: 4_x000D_
//Explanation: The four wonderful substrings are underlined below:_x000D_
//- "aba" -> "a"_x000D_
//- "aba" -> "b"_x000D_
//- "aba" -> "a"_x000D_
//- "aba" -> "aba"_x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: word = "aabb"_x000D_
//Output: 9_x000D_
//Explanation: The nine wonderful substrings are underlined below:_x000D_
//- "aabb" -> "a"_x000D_
//- "aabb" -> "aa"_x000D_
//- "aabb" -> "aab"_x000D_
//- "aabb" -> "aabb"_x000D_
//- "aabb" -> "a"_x000D_
//- "aabb" -> "abb"_x000D_
//- "aabb" -> "b"_x000D_
//- "aabb" -> "bb"_x000D_
//- "aabb" -> "b"_x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: word = "he"_x000D_
//Output: 2_x000D_
//Explanation: The two wonderful substrings are underlined below:_x000D_
//- "he" -> "h"_x000D_
//- "he" -> "e"_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= word.length <= 105_x000D_
//	word consists of lowercase English letters from 'a' to 'j'._x000D_
long long wonderfulSubstrings(char * word){
int len=strlen(word);
    int i;
    int j;
    int k;
    int flag=0;
    int count=0;
    int *arr=(int *)malloc(sizeof(int)*len);
    for(i=0;i<len;i++){
        arr[i]=0;
    }
    for(i=0;i<len;i++){
        arr[i]=1;
        for(j=0;j<len;j++){
            if(arr[j]==1){
                flag=0;
                for(k=j+1;k<len;k++){
                    if(arr[k]==1){
                        if(word[j]==word[k]){
                            flag=1;
                            break;
                        }
                    }
                }
                if(flag==0){
                    count++;
                }
            }
        }
    }
    return count;
}