/**https://leetcode.com/problems/maximum-number-of-eaten-apples/ */
//There is a special kind of apple tree that grows apples every day for n days. On the ith day, the tree grows apples[i] apples that will rot after days[i] days, that is on day i + days[i] the apples will be rotten and cannot be eaten. On some days, the apple tree does not grow any apples, which are denoted by apples[i] == 0 and days[i] == 0.
//You decided to eat at most one apple a day (to keep the doctors away). Note that you can keep eating after the first n days.
//Given two integer arrays days and apples of length n, return the maximum number of apples you can eat.


/**
 * @param {number[]} apples
 * @param {number[]} days
 * @return {number}
 */
var eatenApples = function(apples, days) {
    let n = apples.length;
    let res = 0;
    let q = [];
    for (let i = 0; i < n || q.length; i++) {
        if (i < n && apples[i]) {
            q.push([i + days[i], apples[i]]);
        }
        while (q.length && (q[0][0] <= i || q[0][1] == 0)) {
            q.shift();
        }
        if (q.length) {
            res++;
            q[0][1]--;
        }
    }
    return res;
    
};

    