/**https://leetcode.com/problems/regions-cut-by-slashes/ */
//An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '', or blank space ' '. These characters divide the square into contiguous regions.
//Given the grid grid represented as a string array, return the number of regions.
//Note that backslash characters are escaped, so a '' is represented as '\'.


int regionsBySlashes(char ** grid, int gridSize){
    int n = gridSize;
    int size = n * n * 4;
    int* parent = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        parent[i] = i;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int index = (i * n + j) * 4;
            if(i < n - 1){
                int bottom = index + 4 * n;
                unionSet(parent, index + 2, bottom);
            }
            if(j < n - 1){
                int right = index + 4 + 3;
                unionSet(parent, index + 1, right);
            }
            if(grid[i][j] == '/'){
                unionSet(parent, index, index + 3);
                unionSet(parent, index + 1, index + 2);
            }else if(grid[i][j] == '\\'){
                unionSet(parent, index, index + 1);
                unionSet(parent, index + 2, index + 3);
            }else{
                unionSet(parent, index, index + 1);
                unionSet(parent, index + 1, index + 2);
                unionSet(parent, index + 2, index + 3);
            }
        }
    }
    int count = 0;
    for(int i = 0; i < size; i++){
        if(parent[i] == i){
            count++;
        }
    }
    return count;

}

    