/**https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/ */
//Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.
//A grid is said to be valid if all the cells above the main diagonal are zeros.
//Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.
//The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).
// 
//Example 1:
//Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
//Output: 3
//Example 2:
//Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
//Output: -1
//Explanation: All rows are similar, swaps have no effect on the grid.
//Example 3:
//Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
//Output: 0
// 
//Constraints:
//	n == grid.length == grid[i].length
//	1 <= n <= 200
//	grid[i][j] is either 0 or 1
class Solution {
    public int minSwaps(int[][] grid) {
        int[] arr = new int[grid.length];
        for(int i = 0; i < grid.length; i++){
            int count = 0;
            for(int j = grid.length - 1; j >= 0; j--){
                if(grid[i][j] == 0){
                    count++;
                }else{
                    break;
                }
            }
            arr[i] = count;
        }
        int res = 0;
        for(int i = 0; i < arr.length; i++){
            if(arr[i] < grid.length - 1 - i){
                int j = i + 1;
                while(j < arr.length){
                    if(arr[j] >= grid.length - 1 - i){
                        break;
                    }
                    j++;
                }
                if(j == arr.length){
                    return -1;
                }
                while(j > i){
                    int tmp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = tmp;
                    res++;
                    j--;
                }
            }
        }
        return res;
    }
}