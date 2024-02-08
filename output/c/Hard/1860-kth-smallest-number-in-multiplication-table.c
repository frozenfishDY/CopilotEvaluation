/**https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/ */
//Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).
//Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.


int findKthNumber(int m, int n, int k){
    int i, j, t, f;
    char *s = (char *)malloc(sizeof(char) * (n + 1));
    int *a = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    for (i = 0; i < n; i++) {
        f = 1;
        for (j = 1; j <= n - i - 1; j++) {
            f *= j;
        }
        t = (k - 1) / f;
        s[i] = a[t] + '0';
        for (j = t; j < n - i - 1; j++) {
            a[j] = a[j + 1];
        }
        k -= t * f;
    }
    s[n] = '\0';
    return s;

}

    