/**https://leetcode.com/problems/valid-palindrome/ */
//A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
//Given a string s, return true if it is a palindrome, or false otherwise.

bool isPalindrome(char * s){
    int len = strlen(s);
    if(len == 0){
        return true;
    }
    int i = 0;
    int j = len - 1;
    while(i < j){
        if(!isalnum(s[i])){
            i++;
            continue;
        }
        if(!isalnum(s[j])){
            j--;
            continue;
        }
        if(tolower(s[i]) != tolower(s[j])){
            return false;
        }
        i++;
        j--;
    }
    return true;

}
    