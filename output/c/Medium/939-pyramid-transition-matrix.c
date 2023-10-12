/**https://leetcode.com/problems/pyramid-transition-matrix/ */
//You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.
//To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.
//	For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
//You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.
//Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.
// 
//Example 1:
//Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
//Output: true
//Explanation: The allowed triangular patterns are shown on the right.
//Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
//There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.
//Example 2:
//Input: bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
//Output: false
//Explanation: The allowed triangular patterns are shown on the right.
//Starting from the bottom (level 4), there are multiple ways to build level 3, but trying all the possibilites, you will get always stuck before building level 1.
// 
//Constraints:
//	2 <= bottom.length <= 6
//	0 <= allowed.length <= 216
//	allowed[i].length == 3
//	The letters in all input strings are from the set {'A', 'B', 'C', 'D', 'E', 'F'}.
//	All the values of allowed are unique.
bool pyramidTransition(char * bottom, char ** allowed, int allowedSize){
int n = strlen(bottom);
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < allowedSize; j++) {
            if (allowed[j][0] == bottom[i]) {
                dp[i][i] |= (1 << (allowed[j][2] - 'A'));
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            for (int k = j; k < j + i; k++) {
                for (int l = 0; l < allowedSize; l++) {
                    if (allowed[l][0] == (dp[j][k] + 'A') && allowed[l][1] == (dp[k + 1][j + i] + 'A')) {
                        dp[j][j + i] |= (1 << (allowed[l][2] - 'A'));
                    }
                }
            }
        }
    }
    return dp[0][n - 1] != 0;
}