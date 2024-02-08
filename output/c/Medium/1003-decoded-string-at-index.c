/**https://leetcode.com/problems/decoded-string-at-index/ */
//You are given an encoded string s. To decode the string to a tape, the encoded string is read one character at a time and the following steps are taken:
//If the character read is a letter, that letter is written onto the tape.
//If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
//Given an integer k, return the kth letter (1-indexed) in the decoded string.


char * decodeAtIndex(char * s, int k){
    long long int length = 0;
    int i = 0;
    while(length < k){
        if(s[i] >= '0' && s[i] <= '9'){
            length *= s[i] - '0';
        }else{
            length++;
        }
        i++;
    }
    i--;
    while(i >= 0){
        if(s[i] >= '0' && s[i] <= '9'){
            length /= s[i] - '0';
            k %= length;
        }else{
            if(k == length || k == 0){
                return s + i;
            }
            length--;
        }
        i--;
    }
    return s;

}

    