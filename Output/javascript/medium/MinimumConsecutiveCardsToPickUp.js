/**https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/ */
//ou are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.
//Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.


/**
 * @param {number[]} cards
 * @return {number}
 */
var minimumCardPickup = function(cards) {
    let map = {};
    for (let i = 0; i < cards.length; i++) {
        if (map[cards[i]] === undefined) {
            map[cards[i]] = 1;
        } else {
            map[cards[i]]++;
        }
    }
    let min = Infinity;
    for (let key in map) {
        if (map[key] % 2 === 0) {
            min = Math.min(min, cards.length - map[key]);
        }
    }
    return min === Infinity ? -1 : min;
    
};

    