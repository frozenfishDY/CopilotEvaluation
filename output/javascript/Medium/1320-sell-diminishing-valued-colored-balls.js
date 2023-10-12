/**https://leetcode.com/problems/sell-diminishing-valued-colored-balls/ */
//You have an inventory of different colored balls, and there is a customer that wants orders balls of any color.
//The customer weirdly values the colored balls. Each colored ball's value is the number of balls of that color you currently have in your inventory. For example, if you own 6 yellow balls, the customer would pay 6 for the first yellow ball. After the transaction, there are only 5 yellow balls left, so the next yellow ball is then valued at 5 (i.e., the value of the balls decreases as you sell more to the customer).
//You are given an integer array, inventory, where inventory[i] represents the number of balls of the ith color that you initially own. You are also given an integer orders, which represents the total number of balls that the customer wants. You can sell the balls in any order.
//Return the maximum total value that you can attain after selling orders colored balls. As the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: inventory = [2,5], orders = 4
//Output: 14
//Explanation: Sell the 1st color 1 time (2) and the 2nd color 3 times (5 + 4 + 3).
//The maximum total value is 2 + 5 + 4 + 3 = 14.
//Example 2:
//Input: inventory = [3,5], orders = 6
//Output: 19
//Explanation: Sell the 1st color 2 times (3 + 2) and the 2nd color 4 times (5 + 4 + 3 + 2).
//The maximum total value is 3 + 2 + 5 + 4 + 3 + 2 = 19.
// 
//Constraints:
//	1 <= inventory.length <= 105
//	1 <= inventory[i] <= 109
//	1 <= orders <= min(sum(inventory[i]), 109)
/**
 * @param {number[]} inventory
 * @param {number} orders
 * @return {number}
 */
var maxProfit = function(inventory, orders) {
    let mod = 1000000007;
    inventory.sort((a, b) => b - a);
    let res = 0;
    for (let i = 0; i < inventory.length; i++) {
        if (orders <= 0) break;
        let cur = inventory[i];
        let next = i === inventory.length - 1 ? 0 : inventory[i + 1];
        let diff = cur - next;
        let count = diff * (i + 1);
        if (count < orders) {
            let sum = (cur + next + 1) * diff / 2 * (i + 1);
            res += sum;
            orders -= count;
        } else {
            let rows = Math.floor(orders / (i + 1));
            let cols = orders % (i + 1);
            let sum = (cur + cur - rows + 1) * rows / 2 * (i + 1) + (cur - rows) * cols;
            res += sum;
            orders = 0;
        }
    }
    return res % mod;
};