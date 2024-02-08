/**https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/ */
//There is an 8 x 8 chessboard containing n pieces (rooks, queens, or bishops). You are given a string array pieces of length n, where pieces[i] describes the type (rook, queen, or bishop) of the ith piece. In addition, you are given a 2D integer array positions also of length n, where positions[i] = [ri, ci] indicates that the ith piece is currently at the 1-based coordinate (ri, ci) on the chessboard.
//When making a move for a piece, you choose a destination square that the piece will travel toward and stop on.
//A rook can only travel horizontally or vertically from (r, c) to the direction of (r+1, c), (r-1, c), (r, c+1), or (r, c-1).
//A queen can only travel horizontally, vertically, or diagonally from (r, c) to the direction of (r+1, c), (r-1, c), (r, c+1), (r, c-1), (r+1, c+1), (r+1, c-1), (r-1, c+1), (r-1, c-1).
//A bishop can only travel diagonally from (r, c) to the direction of (r+1, c+1), (r+1, c-1), (r-1, c+1), (r-1, c-1).
//You must make a move for every piece on the board simultaneously. A move combination consists of all the moves performed on all the given pieces. Every second, each piece will instantaneously travel one square towards their destination if they are not already at it. All pieces start traveling at the 0th second. A move combination is invalid if, at a given time, two or more pieces occupy the same square.
//Return the number of valid move combinations.
//Notes:
//No two pieces will start in the same square.
//You may choose the square a piece is already on as its destination.
//If two pieces are directly adjacent to each other, it is valid for them to move past each other and swap positions in one second.


class NumberOfValidMoveCombinationsOnChessboard {
    public int countCombinations(String[] pieces, int[][] positions) {
        int n = pieces.length;
        int[][][] dp = new int[n][8][8];
        int[][][] dp2 = new int[n][8][8];
        int[][][] dp3 = new int[n][8][8];
        int[][][] dp4 = new int[n][8][8];
        int[][][] dp5 = new int[n][8][8];
        int[][][] dp6 = new int[n][8][8];
        int[][][] dp7 = new int[n][8][8];
        int[][][] dp8 = new int[n][8][8];
        int[][][] dp9 = new int[n][8][8];
        int[][][] dp10 = new int[n][8][8];
        int[][][] dp11 = new int[n][8][8];
        int[][][] dp12 = new int[n][8][8];
        int[][][] dp13 = new int[n][8][8];
        int[][][] dp14 = new int[n][8][8];
        int[][][] dp15 = new int[n][8][8];
        int[][][] dp16 = new int[n][8][8];
        int[][][] dp17 = new int[n][8][8];
        int[][][] dp18 = new int[n][8][8];
        int[][][] dp19 = new int[n][8][8];
        int[][][] dp20 = new int[n][8][8];
        int[][][] dp21 = new int[n][8][8];
        int[][][] dp22 = new int[n][8][8];
        int[][][] dp23 = new int[n][8][8];
        int[][][] dp24 = new int[n][8][8];
        int[][][] dp25 = new int[n][8][8];
        int[][][] dp26 = new int[n][8][8];
        int[][][] dp27 = new int[n][8][8];
        int[][][] dp28 = new int[n][8][8];
        int[][][] dp29 = new int[n][8][8];
        int[][][] dp30 = new int[n][8][8];
        int[][][] dp31 = new int[n][8][8];
        int[][][] dp32 = new int[n][8][8];
        int[][][] dp33 = new int[n][8][ 8];
        
    }
}
     
    