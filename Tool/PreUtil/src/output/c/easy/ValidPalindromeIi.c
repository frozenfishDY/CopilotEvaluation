/**https://leetcode.com/problems/valid-palindrome-ii/ */
//Given a string s, return true if the s can be palindrome after deleting at most one character from it.


bool validPalindrome(char * s){
    int len = strlen(s);
    int i = 0;
    int j = len - 1;
    while(i < j){
        if(s[i] != s[j]){
            return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
        }
        i++;
        j--;
    }
    return true;

}

    