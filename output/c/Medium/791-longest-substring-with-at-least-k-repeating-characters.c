/**https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/ */
//Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.


int longestSubstring(char * s, int k){
    int* result = (int*)malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; i++){
        result[i] = 0;
    }
    int length = strlen(s);
    for(int i = 0; i < length; i++){
        result[s[i] - 'a']++;
    }
    int max = 0;
    int start = 0;
    for(int i = 0; i < length; i++){
        if(result[s[i] - 'a'] < k){
            int temp = longestSubstring(s + start, k);
            if(temp > max){
                max = temp;
            }
            start = i + 1;
        }
    }
    if(start == 0){
        return length;
    }
    int temp = longestSubstring(s + start, k);
    if(temp > max){
        max = temp;
    }
    return max;

}

    