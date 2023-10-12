/**https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/ */
//You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.
//Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.
// 
//Example 1:
//Input: cards = [3,4,2,3,4,7]
//Output: 4
//Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.
//Example 2:
//Input: cards = [1,0,5,3]
//Output: -1
//Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.
// 
//Constraints:
//	1 <= cards.length <= 105
//	0 <= cards[i] <= 106
class Solution {
    public int minimumCardPickup(int[] cards) {
        int n = cards.length;
        Arrays.sort(cards);
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < n - 1; i++) {
            if (cards[i] == cards[i + 1]) {
                res = Math.min(res, 2);
            }
        }
        for (int i = 0; i < n - 2; i++) {
            if (cards[i] == cards[i + 2]) {
                res = Math.min(res, 1);
            }
        }
        for (int i = 0; i < n - 3; i++) {
            if (cards[i] == cards[i + 3]) {
                res = Math.min(res, 0);
            }
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}