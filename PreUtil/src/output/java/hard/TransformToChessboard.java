/**https://leetcode.com/problems/transform-to-chessboard/ */
//You are given an n x n binary grid board. In each move, you can swap any two rows with each other, or any two columns with each other.
//Return the minimum number of moves to transform the board into a chessboard board. If the task is impossible, return -1.
//A chessboard board is a board where no 0's and no 1's are 4-directionally adjacent.


class TransformToChessboard {
    public int movesToChessboard(int[][] board) {
        int n = board.length;
        int[] row = new int[n];
        int[] col = new int[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                row[i] = (row[i]<<1) | board[i][j];
                col[j] = (col[j]<<1) | board[i][j];
            }
        }
        int rowSum = 0;
        int colSum = 0;
        int rowSwap = 0;
        int colSwap = 0;
        for(int i=0;i<n;i++){
            rowSum += row[i];
            colSum += col[i];
            if(row[i]==i%2) rowSwap++;
            if(col[i]==i%2) colSwap++;
        }
        if(rowSum!=n/2*(n+1) && rowSum!=n/2*(n-1)) return -1;
        if(colSum!=n/2*(n+1) && colSum!=n/2*(n-1)) return -1;
        if(n%2==1){
            if(rowSwap%2==1) rowSwap = n-rowSwap;
            if(colSwap%2==1) colSwap = n-colSwap;
        }
        else{
            rowSwap = Math.min(n-rowSwap,rowSwap);
            colSwap = Math.min(n-colSwap,colSwap);
        }
        return (rowSwap+colSwap)/2;
        
    }
}
     
    