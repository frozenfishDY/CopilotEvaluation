/**https://leetcode.com/problems/minimum-money-required-before-transactions/ */
//You are given a 0-indexed 2D integer array transactions, where transactions[i] = [costi, cashbacki].
//The array describes transactions, where each transaction must be completed exactly once in some order. At any given moment, you have a certain amount of money. In order to complete transaction i, money >= costi must hold true. After performing a transaction, money becomes money - costi + cashbacki.
//Return the minimum amount of money required before any transaction so that all of the transactions can be completed regardless of the order of the transactions.
// 
//Example 1:
//Input: transactions = [[2,1],[5,0],[4,2]]
//Output: 10
//Explanation:
//Starting with money = 10, the transactions can be performed in any order.
//It can be shown that starting with money < 10 will fail to complete all transactions in some order.
//Example 2:
//Input: transactions = [[3,0],[0,3]]
//Output: 3
//Explanation:
//- If transactions are in the order [[3,0],[0,3]], the minimum money required to complete the transactions is 3.
//- If transactions are in the order [[0,3],[3,0]], the minimum money required to complete the transactions is 0.
//Thus, starting with money = 3, the transactions can be performed in any order.
// 
//Constraints:
//	1 <= transactions.length <= 105
//	transactions[i].length == 2
//	0 <= costi, cashbacki <= 109
class Solution {
    public long minimumMoney(int[][] transactions) {
        long res = 0;
        TreeMap<Integer, Long> map = new TreeMap<>();
        for (int[] transaction : transactions) {
            int cost = transaction[0];
            int cashback = transaction[1];
            map.put(cost, map.getOrDefault(cost, 0L) + cashback);
        }
        for (Map.Entry<Integer, Long> entry : map.entrySet()) {
            int cost = entry.getKey();
            long cashback = entry.getValue();
            long min = Math.min(cost, cashback);
            cost -= min;
            cashback -= min;
            res += cost;
            if (cashback > 0) {
                map.put(cost, map.getOrDefault(cost, 0L) + cashback);
            }
        }
        return res;
    }
}