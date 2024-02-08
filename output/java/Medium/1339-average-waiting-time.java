/**https://leetcode.com/problems/average-waiting-time/ */
//There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:
//arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
//timei is the time needed to prepare the order of the ith customer.
//When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.
//Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.


class AverageWaitingTime {
    public double averageWaitingTime(int[][] customers) {
        int n = customers.length;
        int[] pre = new int[n + 1];
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + customers[i - 1][1];
        }
        int[] dp = new int[n + 1];
        int res = 0;
        int[] last = new int[10001];
        Arrays.fill(last, -1);
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i - 1];
            if(last[customers[i - 1][0]] != -1){
                dp[i] = Math.max(dp[i], dp[last[customers[i - 1][0]]] + pre[i] - pre[last[customers[i - 1][0]] + 1]);
            }
            last[customers[i - 1][0]] = i - 1;
            res = Math.max(res, dp[i]);
        }
        return res;
        
    }
}
     
    