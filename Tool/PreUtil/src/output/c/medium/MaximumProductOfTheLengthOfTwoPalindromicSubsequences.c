/**https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/ */
//Given a string s, find two disjoint palindromic subsequences of s such that the product of their lengths is maximized. The two subsequences are disjoint if they do not both pick a character at the same index.
//Return the maximum possible product of the lengths of the two palindromic subsequences.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters. A string is palindromic if it reads the same forward and backward.


int maxProduct(char * s){
    int i, j, k, l, m, n;
    int len = strlen(s);
    int max = 0;
    int count = 0;
    int* arr = malloc(len * sizeof(int));
    for(i = 0; i < len; i++){
        for(j = i; j < len; j++){
            for(k = i; k <= j; k++){
                for(l = j; l >= i; l--){
                    if(s[k] == s[l]){
                        count++;
                        break;
                    }
                }
            }
            if(count == j - i + 1){
                arr[i] = j - i + 1;
            }
            count = 0;
        }
    }
    for(i = 0; i < len; i++){
        for(j = i; j < len; j++){
            for(k = i; k <= j; k++){
                for(l = j; l >= i; l--){
                    if(s[k] == s[l]){
                        count++;
                        break;
                    }
                }
            }
            if(count == j - i + 1){
                if(arr[i] * (j - i + 1) > max){
                    max = arr[i] * (j - i + 1);
                }
            }
            count = 0;
        }
    }
    return max;

}

    