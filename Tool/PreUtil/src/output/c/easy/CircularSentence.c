/**https://leetcode.com/problems/circular-sentence/ */
//A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
//For example, "Hello World", "HELLO", "hello world hello world" are all sentences.
//Words consist of only uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.
//A sentence is circular if:
//The last character of a word is equal to the first character of the next word.
//The last character of the last word is equal to the first character of the first word.
//For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.
//Given a string sentence, return true if it is circular. Otherwise, return false.


bool isCircularSentence(char * sentence){
    int len = strlen(sentence);
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    while(i < len){
        if(sentence[i] == ' '){
            i++;
            continue;
        }
        j = i;
        while(j < len && sentence[j] != ' '){
            j++;
        }
        count++;
        if(count > 1){
            if(sentence[i] != sentence[k]){
                return false;
            }
        }
        k = j - 1;
        i = j + 1;
    }
    return true;


}

    