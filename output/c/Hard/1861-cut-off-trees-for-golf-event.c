/**https://leetcode.com/problems/cut-off-trees-for-golf-event/ */
//You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix:
//0 means the cell cannot be walked through.
//1 represents an empty cell that can be walked through.
//A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.
//In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.
//You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell).
//Starting from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.
//Note: The input is generated such that no two trees have the same height, and there is at least one tree needs to be cut off.


int cutOffTree(int** forest, int forestSize, int* forestColSize){
    int i, j, k, t, f, n, m, x, y, z, r, c, s, e, d, *a, *b, *q, *p;
    int *dx = (int *)malloc(sizeof(int) * 4);
    int *dy = (int *)malloc(sizeof(int) * 4);
    dx[0] = 0;
    dx[1] = 1;
    dx[2] = 0;
    dx[3] = -1;
    dy[0] = -1;
    dy[1] = 0;
    dy[2] = 1;
    dy[3] = 0;
    n = forestSize;
    m = forestColSize[0];
    a = (int *)malloc(sizeof(int) * n * m);
    b = (int *)malloc(sizeof(int) * n * m);
    q = (int *)malloc(sizeof(int) * n * m);
    p = (int *)malloc(sizeof(int) * n * m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i * m + j] = forest[i][j];
        }
    }
    for (i = 0; i < n * m; i++) {
        b[i] = -1;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i * m + j] > 1) {
                s = i * m + j;
                e = 0;
                q[e] = s;
                b[s] = 0;
                while (e >= 0) {
                    s = q[e];
                    e--;
                    x = s / m;
                    y = s % m;
                    for (k = 0; k < 4; k++) {
                        r = x + dx[k];
                        c = y + dy[k];
                        if (r >= 0 && r < n && c >= 0 && c < m && a[r * m + c] > 0 && b[r * m + c] == -1) {
                            b[r * m + c] = b[s] + 1;
                            e += 1;
                            q[e] = r * m + c;

                              
                              

}

    