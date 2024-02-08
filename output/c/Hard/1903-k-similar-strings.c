/**https://leetcode.com/problems/k-similar-strings/ */
//Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.
//Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.


int kSimilarity(char * s1, char * s2){
    int i, j, k, t, f, m = 0;
    int *a = (int *)malloc(sizeof(int) * strlen(s1));
    for (i = 0; i < strlen(s1); i++) {
        a[i] = i;
    }
    for (i = 0; i < strlen(s1); i++) {
        for (j = i + 1; j < strlen(s1); j++) {
            if (a[i] == a[j]) {
                f = 1;
                for (k = 0; k < strlen(s1); k++) {
                    if (s1[k] != s2[k]) {
                        if (f == 0) {
                            f = 2;
                            break;
                        }
                        f = 0;
                        t = k;
                    }
                }
                if (f == 0) {
                    f = 1;
                    for (k = 0; k < strlen(s1); k++) {
                        if (k != t && s1[k] != s2[k]) {
                            f = 0;
                            break;
                        }
                    }
                }
                if (f == 1) {
                    for (k = 0; k < strlen(s1); k++) {
                        if (a[k] == a[j]) {
                            a[k] = a[i];
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < strlen(s1); i++) {
        if (a[i] == i) {
            m++;
        }
    }
    return m;

}

    