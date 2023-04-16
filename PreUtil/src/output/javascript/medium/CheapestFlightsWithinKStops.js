/**https://leetcode.com/problems/cheapest-flights-within-k-stops/ */
//There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
//You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.


/**
 * @param {number} n
 * @param {number[][]} flights
 * @param {number} src
 * @param {number} dst
 * @param {number} k
 * @return {number}
 */
var findCheapestPrice = function(n, flights, src, dst, k) {
    let graph = new Array(n).fill(0).map(() => new Array());
    for(let i = 0; i < flights.length; i++){
        let from = flights[i][0];
        let to = flights[i][1];
        let price = flights[i][2];
        graph[from].push([to, price]);
    }
    let pq = new PriorityQueue();
    pq.push([src, 0, 0]);
    while(!pq.isEmpty()){
        let top = pq.pop();
        let city = top[0];
        let price = top[1];
        let stops = top[2];
        if(city == dst){
            return price;
        }
        if(stops > k){
            continue;
        }
        for(let i = 0; i < graph[city].length; i++){
            let to = graph[city][i][0];
            let newPrice = price + graph[city][i][1];
            pq.push([to, newPrice, stops + 1]);
        }
    }
    return -1;
    
    
};

    