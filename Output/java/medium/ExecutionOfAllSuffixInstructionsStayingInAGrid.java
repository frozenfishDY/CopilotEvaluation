/**https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/ */
//There is an n x n grid, with the top-left cell at (0, 0) and the bottom-right cell at (n - 1, n - 1). You are given the integer n and an integer array startPos where startPos = [startrow, startcol] indicates that a robot is initially at cell (startrow, startcol).
//You are also given a 0-indexed string s of length m where s[i] is the ith instruction for the robot: 'L' (move left), 'R' (move right), 'U' (move up), and 'D' (move down).
//The robot can begin executing from any ith instruction in s. It executes the instructions one by one towards the end of s but it stops if either of these conditions is met:
//The next instruction will move the robot off the grid.
//There are no more instructions left to execute.
//Return an array answer of length m where answer[i] is the number of instructions the robot can execute if the robot begins executing from the ith instruction in s.


class ExecutionOfAllSuffixInstructionsStayingInAGrid {
    public int[] executeInstructions(int n, int[] startPos, String s) {
        int[][] directions = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int[][] visited = new int[n][n];
        int[] res = new int[s.length()];
        for(int i = 0; i < s.length(); i++){
            int[] dir = directions[getDirection(s.charAt(i))];
            int x = startPos[0] + dir[0];
            int y = startPos[1] + dir[1];
            if(x < 0 || x >= n || y < 0 || y >= n){
                res[i] = i;
            }else{
                res[i] = i + 1;
                startPos[0] = x;
                startPos[1] = y;
            }
        }
        return res;
        
        
    }
}
     
    