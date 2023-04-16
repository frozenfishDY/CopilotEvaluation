/**https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/ */
//There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.
//In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.
//Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.


class MaximumValueOfKCoinsFromPiles {
    public int maxValueOfCoins(List<List<Integer>> piles, int k) {
        int n = piles.size();
        int[] coins = new int[n];
        int idx = 0;
        for (List<Integer> pile : piles) {
            Collections.sort(pile);
            coins[idx++] = pile.get(pile.size() - 2);
        }
        Arrays.sort(coins);
        int res = 0;
        for (int i = n - 1; i >= n - k; i--) {
            res += coins[i];
        }
        return res;
        
    }
}
     
    