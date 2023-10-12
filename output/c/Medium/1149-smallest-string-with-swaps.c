/**https://leetcode.com/problems/smallest-string-with-swaps/ */
//You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
//You can swap the characters at any pair of indices in the given pairs any number of times.
//Return the lexicographically smallest string that s can be changed to after using the swaps.
// 
//Example 1:
//Input: s = "dcab", pairs = [[0,3],[1,2]]
//Output: "bacd"
//Explaination: 
//Swap s[0] and s[3], s = "bcad"
//Swap s[1] and s[2], s = "bacd"
//Example 2:
//Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
//Output: "abcd"
//Explaination: 
//Swap s[0] and s[3], s = "bcad"
//Swap s[0] and s[2], s = "acbd"
//Swap s[1] and s[2], s = "abcd"
//Example 3:
//Input: s = "cba", pairs = [[0,1],[1,2]]
//Output: "abc"
//Explaination: 
//Swap s[0] and s[1], s = "bca"
//Swap s[1] and s[2], s = "bac"
//Swap s[0] and s[1], s = "abc"
// 
//Constraints:
//	1 <= s.length <= 10^5
//	0 <= pairs.length <= 10^5
//	0 <= pairs[i][0], pairs[i][1] < s.length
//	s only contains lower case English letters.
int cmp(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}
int find(int *parent, int index) {
    while (index != parent[index]) {
        parent[index] = parent[parent[index]];
        index = parent[index];
    }
    return index;
}
char * smallestStringWithSwaps(char * s, int** pairs, int pairsSize, int* pairsColSize){
int *parent = (int *)malloc(sizeof(int) * strlen(s));
    for (int i = 0; i < strlen(s); ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < pairsSize; ++i) {
        int root1 = find(parent, pairs[i][0]);
        int root2 = find(parent, pairs[i][1]);
        if (root1 != root2) {
            parent[root1] = root2;
        }
    }
    int **group = (int **)malloc(sizeof(int *) * strlen(s));
    for (int i = 0; i < strlen(s); ++i) {
        group[i] = (int *)malloc(sizeof(int) * 2);
        memset(group[i], 0, sizeof(int) * 2);
    }
    for (int i = 0; i < strlen(s); ++i) {
        int root = find(parent, i);
        ++group[root][0];
        group[root][1] += s[i];
    }
    for (int i = 0; i < strlen(s); ++i) {
        if (group[i][0] > 0) {
            qsort(s + i, group[i][0], sizeof(char), cmp);
            for (int j = 0; j < group[i][0]; ++j) {
                s[i + j] = group[i][1] % 256;
                group[i][1] /= 256;
            }
        }
    }
    return s;
}
