/**https://leetcode.com/problems/where-will-the-ball-fall/ */
//You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.
//Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.
//A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
//A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
//We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.
//Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.


class WhereWillTheBallFall {
    public int[] findBall(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[] res = new int[n];
        for(int i = 0; i < n; i++){
            res[i] = i;
        }
        for(int i = 0; i < m; i++){
            int[] next = new int[n];
            Arrays.fill(next, -1);
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    if(j + 1 < n && grid[i][j + 1] == 1 && res[j + 1] != -1){
                        next[j] = res[j + 1];
                    }
                }else{
                    if(j - 1 >= 0 && grid[i][j - 1] == -1 && res[j - 1] != -1){
                        next[j] = res[j - 1];
                    }
                }
            }
            res = next;
        }
        return res;
        
    }
}
     
    