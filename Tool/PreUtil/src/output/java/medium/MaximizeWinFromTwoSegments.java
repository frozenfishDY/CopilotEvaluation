/**https://leetcode.com/problems/maximize-win-from-two-segments/ */
//There are some prizes on the X-axis. You are given an integer array prizePositions that is sorted in non-decreasing order, where prizePositions[i] is the position of the ith prize. There could be different prizes at the same position on the line. You are also given an integer k.
//You are allowed to select two segments with integer endpoints. The length of each segment must be k. You will collect all prizes whose position falls within at least one of the two selected segments (including the endpoints of the segments). The two selected segments may intersect.
//For example if k = 2, you can choose segments [1, 3] and [2, 4], and you will win any prize i that satisfies 1 <= prizePositions[i] <= 3 or 2 <= prizePositions[i] <= 4.
//Return the maximum number of prizes you can win if you choose the two segments optimally.


class MaximizeWinFromTwoSegments {
    public int maximizeWin(int[] prizePositions, int k) {
        int n = prizePositions.length;
        int[] prefix = new int[n];
        int[] suffix = new int[n];
        int i = 0;
        int j = 0;
        int res = 0;
        while(i < n){
            while(j < n && prizePositions[j] - prizePositions[i] <= k){
                j++;
            }
            prefix[i] = j - i;
            res = Math.max(res, prefix[i]);
            i++;
        }
        i = n - 1;
        j = n - 1;
        while(i >= 0){
            while(j >= 0 && prizePositions[i] - prizePositions[j] <= k){
                j--;
            }
            suffix[i] = i - j;
            res = Math.max(res, suffix[i]);
            i--;
        }
        for(i = 0; i < n - 1; i++){
            res = Math.max(res, prefix[i] + suffix[i + 1]);
        }
        return res;
        
        
    }
}

    