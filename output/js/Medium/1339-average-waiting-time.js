/**https://leetcode.com/problems/average-waiting-time/ */
//There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:
//arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
//timei is the time needed to prepare the order of the ith customer.
//When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.
//Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.


/**
 * @param {number[][]} customers
 * @return {number}
 */
var averageWaitingTime = function(customers) {
    let n = customers.length;
    let result = 0;
    let time = 0;
    for (let i = 0; i < n; i++) {
        let [arrival, timeToPrepare] = customers[i];
        if (time < arrival) {
            time = arrival;
        }
        time += timeToPrepare;
        result += time - arrival;
    }
    return result / n;
    
};

    