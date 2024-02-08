/**https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/ */
//You are given a 2D integer array tiles where tiles[i] = [li, ri] represents that every tile j in the range li <= j <= ri is colored white.
//You are also given an integer carpetLen, the length of a single carpet that can be placed anywhere.
//Return the maximum number of white tiles that can be covered by the carpet.


class MaximumWhiteTilesCoveredByACarpet {
    public int maximumWhiteTiles(int[][] tiles, int carpetLen) {
        int[] count = new int[100000];
        for (int[] tile : tiles) {
            count[tile[0]]++;
            count[tile[1] + 1]--;
        }
        for (int i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }
        int result = 0;
        for (int i = 0; i < count.length; i++) {
            if (count[i] > 0) {
                result += Math.min(carpetLen, count[i]);
            }
        }
        return result;
        
    }
}
     
    