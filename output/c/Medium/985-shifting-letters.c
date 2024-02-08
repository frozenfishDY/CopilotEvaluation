/**https://leetcode.com/problems/shifting-letters/ */
//You are given a string s of lowercase English letters and an integer array shifts of the same length.
//Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').
//For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
//Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.
//Return the final string after all such shifts to s are applied.


char * shiftingLetters(char * s, int* shifts, int shiftsSize){
    int length = strlen(s);
    int* sum = (int*)malloc(sizeof(int) * length);
    sum[length - 1] = shifts[length - 1];
    for(int i = length - 2; i >= 0; i--){
        sum[i] = sum[i + 1] + shifts[i];
    }
    for(int i = 0; i < length; i++){
        s[i] = (s[i] - 'a' + sum[i]) % 26 + 'a';
    }
    return s;

}

    