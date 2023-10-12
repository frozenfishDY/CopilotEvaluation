/**https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/ */
//You are given an array of strings words. Each element of words consists of two lowercase English letters.
//Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
//Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
//A palindrome is a string that reads the same forward and backward.
// 
//Example 1:
//Input: words = ["lc","cl","gg"]
//Output: 6
//Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
//Note that "clgglc" is another longest palindrome that can be created.
//Example 2:
//Input: words = ["ab","ty","yt","lc","cl","ab"]
//Output: 8
//Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
//Note that "lcyttycl" is another longest palindrome that can be created.
//Example 3:
//Input: words = ["cc","ll","xx"]
//Output: 2
//Explanation: One longest palindrome is "cc", of length 2.
//Note that "ll" is another longest palindrome that can be created, and so is "xx".
// 
//Constraints:
//	1 <= words.length <= 105
//	words[i].length == 2
//	words[i] consists of lowercase English letters.
int longestPalindrome(char ** words, int wordsSize){
int i,j,k;
    int count;
    int left;
    int right;
    int prev;
    int next;
    int len;
    int max=0;
    for(i=0;i<wordsSize;i++){
        count=0;
        len=strlen(words[i]);
        for(j=0;j<len;j++){
            for(k=0;k<len;k++){
                if(j!=k){
                    if(words[i][j]==words[i][k]){
                        count++;
                        break;
                    }
                }
            }
        }
        if(count==len-1){
            if(len>max){
                max=len;
            }
        }
    }
    return max;
}