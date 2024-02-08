/**https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/ */
//You are given a list of songs where the ith song has a duration of time[i] seconds.
//Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.


class PairsOfSongsWithTotalDurationsDivisibleBy60 {
    public int numPairsDivisibleBy60(int[] time) {
        int[] cnt = new int[60];
        int res = 0;
        for(int i : time){
            res += cnt[(60 - i % 60) % 60];
            cnt[i % 60]++;
        }
        return res;
        
    }
}

    