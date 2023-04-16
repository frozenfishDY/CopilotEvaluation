/**https://leetcode.com/problems/construct-k-palindrome-strings/ */
//Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.


bool canConstruct(char * s, int k){
    int i, j, count = 0, *arr;
    arr = (int*)malloc(26 * sizeof(int));
    for(i = 0; i < 26; i++){
        arr[i] = 0;
    }
    for(i = 0; i < strlen(s); i++){
        arr[s[i] - 'a']++;
    }
    for(i = 0; i < 26; i++){
        if(arr[i] % 2 == 1){
            count++;
        }
    }
    if(count > k){
        return false;
    }
    return true;

}

    