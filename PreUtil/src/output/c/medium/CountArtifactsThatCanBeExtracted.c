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


int digArtifacts(int n, int** artifacts, int artifactsSize, int* artifactsColSize, int** dig, int digSize, int* digColSize){
    int i, j, k, l;
    int count = 0;
    int x, y;
    int flag = 0;
    for(i = 0; i < digSize; i++){
        x = dig[i][0];
        y = dig[i][1];
        for(j = 0; j < artifactsSize; j++){
            if(x >= artifacts[j][0] && x <= artifacts[j][2] && y >= artifacts[j][1] && y <= artifacts[j][3]){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            for(k = 0; k < artifactsSize; k++){
                if(x >= artifacts[k][0] && x <= artifacts[k][2] && y >= artifacts[k][1] && y <= artifacts[k][3]){
                    artifacts[k][0] = -1;
                    artifacts[k][1] = -1;
                    artifacts[k][2] = -1;
                    artifacts[k][3] = -1;
                }
            }
            flag = 0;
        }
    }
    for(i = 0; i < artifactsSize; i++){
        if(artifacts[i][0] == -1 && artifacts[i][1] == -1 && artifacts[i][2] == -1 && artifacts[i][3] == -1){
            count++;
        }
    }
    return count;

}

    