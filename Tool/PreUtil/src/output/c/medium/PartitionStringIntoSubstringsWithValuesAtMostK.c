/**https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/ */
//You are given a string s consisting of digits from 1 to 9 and an integer k.
//A partition of a string s is called good if:
//Each digit of s is part of exactly one substring.
//The value of each substring is less than or equal to k.
//Return the minimum number of substrings in a good partition of s. If no good partition of s exists, return -1.
//Note that:
//The value of a string is its result when interpreted as an integer. For example, the value of "123" is 123 and the value of "1" is 1.
//A substring is a contiguous sequence of characters within a string.


int minimumPartition(char * s, int k){
    int* result = (int*)malloc(sizeof(int) * (strlen(s) + 1));
    result[0] = 0;
    for(int i = 1; i <= strlen(s); i++){
        result[i] = result[i - 1] + (s[i - 1] - '0');
    }
    int count = 0;
    for(int i = 0; i < strlen(s); i++){
        for(int j = i + 1; j <= strlen(s); j++){
            if(result[j] - result[i] <= k){
                count++;
            }
        }
    }
    return count;

}

    