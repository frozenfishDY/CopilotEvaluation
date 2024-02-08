/**https://leetcode.com/problems/super-egg-drop/ */
//You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
//You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.
//Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
//Return the minimum number of moves that you need to determine with certainty what the value of f is.


int superEggDrop(int k, int n){
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

    