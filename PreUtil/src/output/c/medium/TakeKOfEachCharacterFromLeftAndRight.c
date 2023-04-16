/**https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/ */
//You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
//Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.


int takeCharacters(char * s, int k){
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;
    int left = 0;
    int right = strlen(s) - 1;
    while(left <= right){
        if(s[left] == 'a'){
            aCount++;
        }else if(s[left] == 'b'){
            bCount++;
        }else{
            cCount++;
        }
        if(s[right] == 'a'){
            aCount++;
        }else if(s[right] == 'b'){
            bCount++;
        }else{
            cCount++;
        }
        if(aCount >= k && bCount >= k && cCount >= k){
            return left + 1;
        }
        left++;
        right--;
    }
    return -1;

}

    