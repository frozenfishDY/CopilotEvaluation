/**https://leetcode.com/problems/kth-smallest-instructions/ */
//Bob is standing at cell (0, 0), and he wants to reach destination: (row, column). He can only travel right and down. You are going to help Bob by providing instructions for him to reach destination.
//The instructions are represented as a string, where each character is either:
//'H', meaning move horizontally (go right), or
//'V', meaning move vertically (go down).
//Multiple instructions will lead Bob to destination. For example, if destination is (2, 3), both "HHHVV" and "HVHVH" are valid instructions.
//However, Bob is very picky. Bob has a lucky number k, and he wants the kth lexicographically smallest instructions that will lead him to destination. k is 1-indexed.
//Given an integer array destination and an integer k, return the kth lexicographically smallest instructions that will take Bob to destination.


class KthSmallestInstructions {
    public String kthSmallestPath(int[] destination, int k) {
        int row = destination[0];
        int col = destination[1];
        int[][] dp = new int[row + 1][col + 1];
        dp[0][0] = 1;
        for(int i = 1; i <= row; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= col; i++){
            dp[0][i] = 1;
        }
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        StringBuilder sb = new StringBuilder();
        while(row > 0 && col > 0){
            if(dp[row - 1][col] >= k){
                sb.append('H');
                row--;
            }else{
                sb.append('V');
                k -= dp[row - 1][col];
                col--;
            }
        }
        while(row > 0){
            sb.append('H');
            row--;
        }
        while(col > 0){
            sb.append('V');
            col--;
        }
        return sb.toString();
        
    }
}
     
    