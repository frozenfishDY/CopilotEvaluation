/**https://leetcode.com/problems/delete-greatest-value-in-each-row/ */
//You are given an m x n matrix grid consisting of positive integers.
//Perform the following operation until grid becomes empty:
//Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
//Add the maximum of deleted elements to the answer.
//Note that the number of columns decreases by one after each operation.
//Return the answer after performing the operations described above.


class DeleteGreatestValueInEachRow {
    public int deleteGreatestValue(int[][] grid) {
        int sum = 0;
        while(grid.length > 0){
            int max = Integer.MIN_VALUE;
            int maxIndex = 0;
            for(int i = 0; i < grid.length; i++){
                for(int j = 0; j < grid[i].length; j++){
                    if(grid[i][j] > max){
                        max = grid[i][j];
                        maxIndex = i;
                    }
                }
            }
            sum += max;
            int[][] newGrid = new int[grid.length - 1][grid[0].length - 1];
            int count = 0;
            for(int i = 0; i < grid.length; i++){
                if(i == maxIndex) continue;
                for(int j = 0; j < grid[i].length; j++){
                    if(j == maxIndex) continue;
                    newGrid[count][j] = grid[i][j];
                }
                count++;
            }
            grid = newGrid;
        }
        return sum;
        
        

        
    }
}

    