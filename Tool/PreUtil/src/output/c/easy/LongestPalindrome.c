/**https://leetcode.com/problems/longest-palindrome/ */
//Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
//Letters are case sensitive, for example, "Aa" is not considered a palindrome here.


int longestPalindrome(char * s){
    int len = strlen(s);
    int arr[52] = {0};
    for(int i = 0; i < len; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            arr[s[i] - 'a']++;
        }
        else{
            arr[s[i] - 'A' + 26]++;
        }
    }
    int count = 0;
    for(int i = 0; i < 52; i++){
        if(arr[i] % 2 == 0){
            count += arr[i];
        }
        else{
            count += arr[i] - 1;
        }
    }
    if(count < len){
        count++;
    }
    return count;

}

    