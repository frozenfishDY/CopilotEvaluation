/**https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/ */
//ou are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.
//Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.


class MinimumConsecutiveCardsToPickUp {
    public int minimumCardPickup(int[] cards) {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int card : cards) {
            min = Math.min(min, card);
            max = Math.max(max, card);
        }
        int[] count = new int[max - min + 1];
        for (int card : cards) {
            count[card - min]++;
        }
        int result = 0;
        for (int i = 0; i < count.length; i++) {
            if (count[i] == 0) {
                result++;
            } else {
                result = 0;
            }
            if (result == 2) {
                return 2;
            }
        }
        return -1;
        
    }
}
     
    