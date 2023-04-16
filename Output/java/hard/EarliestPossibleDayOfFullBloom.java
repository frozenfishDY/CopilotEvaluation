/**https://leetcode.com/problems/earliest-possible-day-of-full-bloom/ */
//You have n flower seeds. Every seed must be planted first before it can begin to grow, then bloom. Planting a seed takes time and so does the growth of a seed. You are given two 0-indexed integer arrays plantTime and growTime, of length n each:
//plantTime[i] is the number of full days it takes you to plant the ith seed. Every day, you can work on planting exactly one seed. You do not have to work on planting the same seed on consecutive days, but the planting of a seed is not complete until you have worked plantTime[i] days on planting it in total.
//growTime[i] is the number of full days it takes the ith seed to grow after being completely planted. After the last day of its growth, the flower blooms and stays bloomed forever.
//From the beginning of day 0, you can plant the seeds in any order.
//Return the earliest possible day where all seeds are blooming.


class EarliestPossibleDayOfFullBloom {
    public int earliestFullBloom(int[] plantTime, int[] growTime) {
        int n = plantTime.length;
        int[][] flowers = new int[n][2];
        for (int i = 0; i < n; i++) {
            flowers[i][0] = plantTime[i];
            flowers[i][1] = plantTime[i] + growTime[i];
        }
        Arrays.sort(flowers, (a, b) -> a[0] - b[0]);
        int res = 0;
        int left = 0;
        int right = 0;
        int sum = 0;
        while (right < n) {
            sum += flowers[right][1];
            while (flowers[right][0] - flowers[left][0] > 0) {
                sum -= flowers[left][1];
                left++;
            }
            res = Math.max(res, sum);
            right++;
        }
        return res;
        
    }
}
     
    