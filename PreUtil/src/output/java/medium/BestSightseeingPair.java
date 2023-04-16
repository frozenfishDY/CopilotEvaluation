/**https://leetcode.com/problems/best-sightseeing-pair/ */
//You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
//The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
//Return the maximum score of a pair of sightseeing spots.


class BestSightseeingPair {
    public int maxScoreSightseeingPair(int[] values) {
        int n = values.length;
        int res = 0;
        int max = values[0];
        for(int i = 1; i < n; i++){
            res = Math.max(res, max + values[i] - i);
            max = Math.max(max, values[i] + i);
        }
        return res;
        
    }
}

    