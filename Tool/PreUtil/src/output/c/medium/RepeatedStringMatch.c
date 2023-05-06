/**https://leetcode.com/problems/repeated-string-match/ */
//Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b to be a substring of a after repeating it, return -1.
//Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".


int repeatedStringMatch(char * a, char * b){
    int aLength = strlen(a);
    int bLength = strlen(b);
    int count = 0;
    int i = 0;
    int j = 0;
    while(i < aLength){
        if(a[i] == b[j]){
            j++;
            if(j == bLength){
                return count + 1;
            }
        }else{
            j = 0;
            if(a[i] == b[j]){
                j++;
            }
        }
        i++;
        if(i == aLength){
            i = 0;
            count++;
        }
    }
    return -1;

}

    