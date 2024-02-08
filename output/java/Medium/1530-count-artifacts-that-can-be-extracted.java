/**https://leetcode.com/problems/count-artifacts-that-can-be-extracted/ */
//There is an n x n 0-indexed grid with some artifacts buried in it. You are given the integer n and a 0-indexed 2D integer array artifacts describing the positions of the rectangular artifacts where artifacts[i] = [r1i, c1i, r2i, c2i] denotes that the ith artifact is buried in the subgrid where:
//(r1i, c1i) is the coordinate of the top-left cell of the ith artifact and
//(r2i, c2i) is the coordinate of the bottom-right cell of the ith artifact.
//You will excavate some cells of the grid and remove all the mud from them. If the cell has a part of an artifact buried underneath, it will be uncovered. If all the parts of an artifact are uncovered, you can extract it.
//Given a 0-indexed 2D integer array dig where dig[i] = [ri, ci] indicates that you will excavate the cell (ri, ci), return the number of artifacts that you can extract.
//The test cases are generated such that:
//No two artifacts overlap.
//Each artifact only covers at most 4 cells.
//The entries of dig are unique.


class CountArtifactsThatCanBeExtracted {
    public int digArtifacts(int n, int[][] artifacts, int[][] dig) {
        int[][] grid = new int[n][n];
        for(int[] artifact : artifacts){
            for(int i = artifact[0]; i <= artifact[2]; i++){
                for(int j = artifact[1]; j <= artifact[3]; j++){
                    grid[i][j] = 1;
                }
            }
        }
        int res = 0;
        for(int[] digPos : dig){
            if(grid[digPos[0]][digPos[1]] == 1){
                res++;
                grid[digPos[0]][digPos[1]] = 0;
            }
        }
        return res;
        
    }
}
     
    