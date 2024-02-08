/**https://leetcode.com/problems/strange-printer/ */
//There is a strange printer with the following two special properties:
//The printer can only print a sequence of the same character each time.
//At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
//Given a string s, return the minimum number of turns the printer needed to print it.


int strangePrinter(char * s){
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

    