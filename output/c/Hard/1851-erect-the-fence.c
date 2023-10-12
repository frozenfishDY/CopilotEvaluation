/**https://leetcode.com/problems/erect-the-fence/ */
//You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.
//Fence the entire garden using the minimum length of rope, as it is expensive. The garden is well-fenced only if all the trees are enclosed.
//Return the coordinates of trees that are exactly located on the fence perimeter. You may return the answer in any order.
// 
//Example 1:
//Input: trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
//Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
//Explanation: All the trees will be on the perimeter of the fence except the tree at [2, 2], which will be inside the fence.
//Example 2:
//Input: trees = [[1,2],[2,2],[4,2]]
//Output: [[4,2],[2,2],[1,2]]
//Explanation: The fence forms a line that passes through all the trees.
// 
//Constraints:
//	1 <= trees.length <= 3000
//	trees[i].length == 2
//	0 <= xi, yi <= 100
//	All the given positions are unique.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** outerTrees(int** trees, int treesSize, int* treesColSize, int* returnSize, int** returnColumnSizes){
*returnSize = 0;
    int **res = (int **)malloc(sizeof(int *) * 3000);
    for (int i = 0; i < 3000; i++) {
        res[i] = (int *)malloc(sizeof(int) * 2);
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * 3000);
    int *stack = (int *)malloc(sizeof(int) * 3000);
    int top = -1;
    int left = 0;
    for (int i = 0; i < treesSize; i++) {
        if (trees[i][0] < trees[left][0]) left = i;
    }
    int p = left;
    do {
        int q = (p + 1) % treesSize;
        for (int i = 0; i < treesSize; i++) {
            if (cross(trees[p], trees[i], trees[q]) > 0) {
                q = i;
            }
        }
        for (int i = 0; i < treesSize; i++) {
            if (i != p && i != q && cross(trees[p], trees[i], trees[q]) == 0 && inBetween(trees[p], trees[i], trees[q])) {
                stack[++top] = i;
            }
        }
        stack[++top] = q;
        p = q;
    } while (p != left);
    int k = 0;
    while (top >= 0) {
        int i = stack[top--];
        res[k][0] = trees[i][0];
        res[k][1] = trees[i][1];
        (*returnColumnSizes)[k] = 2;
        k++;
    }
    *returnSize = k;
    return res;
}
int cross(int *p, int *q, int *r) {
    int x1 = q[0] - p[0], y1 = q[1] - p[1];
    int x2 = r[0] - p[0], y2 = r[1] - p[1];
    return x1 * y2 - x2 * y1;
}