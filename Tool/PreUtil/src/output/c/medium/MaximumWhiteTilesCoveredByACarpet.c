/**https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/ */
//You are given a 2D integer array tiles where tiles[i] = [li, ri] represents that every tile j in the range li <= j <= ri is colored white.
//You are also given an integer carpetLen, the length of a single carpet that can be placed anywhere.
//Return the maximum number of white tiles that can be covered by the carpet.


int maximumWhiteTiles(int** tiles, int tilesSize, int* tilesColSize, int carpetLen){
    int i, j, k, count = 0, max = 0, temp = 0;
    for(i = 0; i < tilesSize; i++){
        for(j = tiles[i][0]; j <= tiles[i][1]; j++){
            count = 0;
            for(k = 0; k < tilesSize; k++){
                if(j >= tiles[k][0] && j <= tiles[k][1]){
                    count++;
                }
            }
            if(count > max){
                max = count;
            }
        }
    }
    return max * carpetLen;

}

    