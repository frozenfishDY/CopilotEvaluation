/**https://leetcode.com/problems/number-of-orders-in-the-backlog/ */
//You are given a 2D integer array orders, where each orders[i] = [pricei, amounti, orderTypei] denotes that amounti orders have been placed of type orderTypei at the price pricei. The orderTypei is:_x000D_
//_x000D_
//_x000D_
//	0 if it is a batch of buy orders, or_x000D_
//	1 if it is a batch of sell orders._x000D_
//_x000D_
//_x000D_
//Note that orders[i] represents a batch of amounti independent orders with the same price and order type. All orders represented by orders[i] will be placed before all orders represented by orders[i+1] for all valid i._x000D_
//_x000D_
//There is a backlog that consists of orders that have not been executed. The backlog is initially empty. When an order is placed, the following happens:_x000D_
//_x000D_
//_x000D_
//	If the order is a buy order, you look at the sell order with the smallest price in the backlog. If that sell order's price is smaller than or equal to the current buy order's price, they will match and be executed, and that sell order will be removed from the backlog. Else, the buy order is added to the backlog._x000D_
//	Vice versa, if the order is a sell order, you look at the buy order with the largest price in the backlog. If that buy order's price is larger than or equal to the current sell order's price, they will match and be executed, and that buy order will be removed from the backlog. Else, the sell order is added to the backlog._x000D_
//_x000D_
//_x000D_
//Return the total amount of orders in the backlog after placing all the orders from the input. Since this number can be large, return it modulo 109 + 7._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: orders = [[10,5,0],[15,2,1],[25,1,1],[30,4,0]]_x000D_
//Output: 6_x000D_
//Explanation: Here is what happens with the orders:_x000D_
//- 5 orders of type buy with price 10 are placed. There are no sell orders, so the 5 orders are added to the backlog._x000D_
//- 2 orders of type sell with price 15 are placed. There are no buy orders with prices larger than or equal to 15, so the 2 orders are added to the backlog._x000D_
//- 1 order of type sell with price 25 is placed. There are no buy orders with prices larger than or equal to 25 in the backlog, so this order is added to the backlog._x000D_
//- 4 orders of type buy with price 30 are placed. The first 2 orders are matched with the 2 sell orders of the least price, which is 15 and these 2 sell orders are removed from the backlog. The 3rd order is matched with the sell order of the least price, which is 25 and this sell order is removed from the backlog. Then, there are no more sell orders in the backlog, so the 4th order is added to the backlog._x000D_
//Finally, the backlog has 5 buy orders with price 10, and 1 buy order with price 30. So the total number of orders in the backlog is 6._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: orders = [[7,1000000000,1],[15,3,0],[5,999999995,0],[5,1,1]]_x000D_
//Output: 999999984_x000D_
//Explanation: Here is what happens with the orders:_x000D_
//- 109 orders of type sell with price 7 are placed. There are no buy orders, so the 109 orders are added to the backlog._x000D_
//- 3 orders of type buy with price 15 are placed. They are matched with the 3 sell orders with the least price which is 7, and those 3 sell orders are removed from the backlog._x000D_
//- 999999995 orders of type buy with price 5 are placed. The least price of a sell order is 7, so the 999999995 orders are added to the backlog._x000D_
//- 1 order of type sell with price 5 is placed. It is matched with the buy order of the highest price, which is 5, and that buy order is removed from the backlog._x000D_
//Finally, the backlog has (1000000000-3) sell orders with price 7, and (999999995-1) buy orders with price 5. So the total number of orders = 1999999991, which is equal to 999999984 % (109 + 7)._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= orders.length <= 105_x000D_
//	orders[i].length == 3_x000D_
//	1 <= pricei, amounti <= 109_x000D_
//	orderTypei is either 0 or 1._x000D_
class Solution {
    public int getNumberOfBacklogOrders(int[][] orders) {
        int n = orders.length;
        PriorityQueue<int[]> buy = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        PriorityQueue<int[]> sell = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int[] order : orders) {
            if (order[2] == 0) {
                while (order[1] > 0 && !sell.isEmpty() && sell.peek()[0] <= order[0]) {
                    int[] cur = sell.poll();
                    int diff = Math.min(order[1], cur[1]);
                    order[1] -= diff;
                    cur[1] -= diff;
                    if (cur[1] > 0) {
                        sell.offer(cur);
                    }
                }
                if (order[1] > 0) {
                    buy.offer(order);
                }
            } else {
                while (order[1] > 0 && !buy.isEmpty() && buy.peek()[0] >= order[0]) {
                    int[] cur = buy.poll();
                    int diff = Math.min(order[1], cur[1]);
                    order[1] -= diff;
                    cur[1] -= diff;
                    if (cur[1] > 0) {
                        buy.offer(cur);
                    }
                }
                if (order[1] > 0) {
                    sell.offer(order);
                }
            }
        }
        long res = 0;
        while (!buy.isEmpty()) {
            res += buy.poll()[1];
        }
        while (!sell.isEmpty()) {
            res += sell.poll()[1];
        }
        return (int)(res % 1000000007);
    }
}