/**https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/ */
//In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
//We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
//Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
//If it cannot be done, return -1.


class MinimumDominoRotationsForEqualRow {
    public int minDominoRotations(int[] tops, int[] bottoms) {
        int n = tops.length;
        int[] cnt = new int[7];
        for(int i = 0; i < n; i++){
            cnt[tops[i]]++;
            cnt[bottoms[i]]++;
        }
        int res = Integer.MAX_VALUE;
        for(int i = 1; i <= 6; i++){
            if(cnt[i] >= n){
                int a = 0;
                int b = 0;
                for(int j = 0; j < n; j++){
                    if(tops[j] != i){
                        a++;
                    }
                    if(bottoms[j] != i){
                        b++;
                    }
                }
                res = Math.min(res, Math.min(a, b));
            }
        }
        return res == Integer.MAX_VALUE ? -1 : res;
        
        
    }
}

    