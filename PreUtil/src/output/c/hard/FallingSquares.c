/**https://leetcode.com/problems/falling-squares/ */
//There are several squares being dropped onto the X-axis of a 2D plane.
//You are given a 2D integer array positions where positions[i] = [lefti, sideLengthi] represents the ith square with a side length of sideLengthi that is dropped with its left edge aligned with X-coordinate lefti.
//Each square is dropped one at a time from a height above any landed squares. It then falls downward (negative Y direction) until it either lands on the top side of another square or on the X-axis. A square brushing the left/right side of another square does not count as landing on it. Once it lands, it freezes in place and cannot be moved.
//After each square is dropped, you must record the height of the current tallest stack of squares.
//Return an integer array ans where ans[i] represents the height described above after dropping the ith square.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fallingSquares(int** positions, int positionsSize, int* positionsColSize, int* returnSize){
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

    