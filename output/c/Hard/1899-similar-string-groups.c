/**https://leetcode.com/problems/similar-string-groups/ */
//Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.
//For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".
//Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.
//We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?


int numSimilarGroups(char ** strs, int strsSize){
    int i, j, k, t, f, m = 0;
    int *a = (int *)malloc(sizeof(int) * strsSize);
    for (i = 0; i < strsSize; i++) {
        a[i] = i;
    }
    for (i = 0; i < strsSize; i++) {
        for (j = i + 1; j < strsSize; j++) {
            if (a[i] == a[j]) {
                f = 1;
                for (k = 0; k < strlen(strs[i]); k++) {
                    if (strs[i][k] != strs[j][k]) {
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
                    for (k = 0; k < strlen(strs[i]); k++) {
                        if (k != t && strs[i][k] != strs[j][k]) {
                            f = 0;
                            break;
                        }
                    }
                }
                if (f == 1) {
                    for (k = 0; k < strsSize; k++) {
                        if (a[k] == a[j]) {
                            a[k] = a[i];
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < strsSize; i++) {
        if (a[i] == i) {
            m++;
        }
    }
    return m;

}

    