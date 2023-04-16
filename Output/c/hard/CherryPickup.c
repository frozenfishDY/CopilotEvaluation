/**https://leetcode.com/problems/cherry-pickup/ */
//You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.
//0 means the cell is empty, so you can pass through,
//1 means the cell contains a cherry that you can pick up and pass through, or
//-1 means the cell contains a thorn that blocks your way.
//Return the maximum number of cherries you can collect by following the rules below:
//Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
//After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
//When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
//If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.


int cherryPickup(int** grid, int gridSize, int* gridColSize){
    int i, j, k, l, m, n, o, p, q, r, a, b, c, d, e, f, g, h, w, x, y, z;
    int *s = (int *)malloc(sizeof(int) * (n + 1));
    int *t = (int *)malloc(sizeof(int) * (n + 1));
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

    