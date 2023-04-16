/**https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/ */
//Alice is a caretaker of n gardens and she wants to plant flowers to maximize the total beauty of all her gardens.
//You are given a 0-indexed integer array flowers of size n, where flowers[i] is the number of flowers already planted in the ith garden. Flowers that are already planted cannot be removed. You are then given another integer newFlowers, which is the maximum number of flowers that Alice can additionally plant. You are also given the integers target, full, and partial.
//A garden is considered complete if it has at least target flowers. The total beauty of the gardens is then determined as the sum of the following:
//The number of complete gardens multiplied by full.
//The minimum number of flowers in any of the incomplete gardens multiplied by partial. If there are no incomplete gardens, then this value will be 0.
//Return the maximum total beauty that Alice can obtain after planting at most newFlowers flowers.


class MaximumTotalBeautyOfTheGardens {
    public long maximumBeauty(int[] flowers, long newFlowers, int target, int full, int partial) {
        int n = flowers.length;
        int[] complete = new int[n];
        int[] incomplete = new int[n];
        int completeCount = 0;
        int incompleteCount = 0;
        for (int i = 0; i < n; i++) {
            if (flowers[i] >= target) {
                complete[completeCount++] = flowers[i];
            } else {
                incomplete[incompleteCount++] = flowers[i];
            }
        }
        Arrays.sort(complete, 0, completeCount);
        Arrays.sort(incomplete, 0, incompleteCount);
        long res = 0;
        long sum = 0;
        for (int i = 0; i < completeCount; i++) {
            sum += complete[i];
            res = Math.max(res, (i + 1) * full + (incompleteCount > 0 ? incomplete[0] : 0) * partial);
        }
        for (int i = 0; i < incompleteCount; i++) {
            sum += incomplete[i];
            res = Math.max(res, completeCount * full + (i + 1) * partial);
        }
        long left = 0;
        long right = 0;
        long sum2 = 0;
        while (right < newFlowers) {
            sum2 += sum;
            while (right - left > 0) {
                sum2 -= sum;
                left++;
            }
            res = Math.max(res, sum2);
            right++;
        }
        return res;
        
    }
}
     
    