/**https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/ */
//A happy string is a string that:
//consists only of letters of the set ['a', 'b', 'c'].
//s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
//For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
//Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
//Return the kth string of this list or return an empty string if there are less than k happy strings of length n.


char * getHappyString(int n, int k){
    int i, j, count = 0, *arr;
    char *str = (char*)malloc(100000 * sizeof(char));
    arr = (int*)malloc(3 * sizeof(int));
    for(i = 0; i < 100000; i++){
        str[i] = '\0';
    }
    for(i = 0; i < 3; i++){
        arr[i] = 0;
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < 3; j++){
            if(arr[j] == 0){
                if(j == 0){
                    str[count++] = 'a';
                }
                else if(j == 1){
                    str[count++] = 'b';
                }
                else{
                    str[count++] = 'c';
                }
                arr[j] = 1;
                break;
            }
            else{
                if(j == 0){
                    if(str[count - 1] != 'a'){
                        str[count++] = 'a';
                        arr[j] = 1;
                        break;
                    }
                }
                else if(j == 1){
                    if(str[count - 1] != 'b'){
                        str[count++] = 'b';
                        arr[j] = 1;
                        break;
                    }
                }
                else{
                    if(str[count - 1] != 'c'){
                        str[count++] = 'c';
                        arr[j] = 1;
                        break;
                    }
                }
            }
        }
    }
    return str;

}

    