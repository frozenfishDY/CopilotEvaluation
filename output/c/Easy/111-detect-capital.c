/**https://leetcode.com/problems/detect-capital/ */
//We define the usage of capitals in a word to be right when one of the following cases holds:
//All letters in this word are capitals, like "USA".
//All letters in this word are not capitals, like "leetcode".
//Only the first letter in this word is capital, like "Google".
//Given a string word, return true if the usage of capitals in it is right.


bool detectCapitalUse(char * word){
    int i = 0;
    int count = 0;
    while(word[i] != '\0'){
        if(word[i] >= 'A' && word[i] <= 'Z'){
            count++;
        }
        i++;
    }
    if(count == 0 || count == i || (count == 1 && word[0] >= 'A' && word[0] <= 'Z')){
        return true;
    }
    return false;

}

    