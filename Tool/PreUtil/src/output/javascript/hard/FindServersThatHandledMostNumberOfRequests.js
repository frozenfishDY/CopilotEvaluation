/**https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/ */
//You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but cannot handle more than one request at a time. The requests are assigned to servers according to a specific algorithm:
//The ith (0-indexed) request arrives.
//If all servers are busy, the request is dropped (not handled at all).
//If the (i % k)th server is available, assign the request to that server.
//Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the ith server is busy, try to assign the request to the (i+1)th server, then the (i+2)th server, and so on.
//You are given a strictly increasing array arrival of positive integers, where arrival[i] represents the arrival time of the ith request, and another array load, where load[i] represents the load of the ith request (the time it takes to complete). Your goal is to find the busiest server(s). A server is considered busiest if it handled the most number of requests successfully among all the servers.
//Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.


/**
 * @param {number} k
 * @param {number[]} arrival
 * @param {number[]} load
 * @return {number[]}
 */
var busiestServers = function(k, arrival, load) {
    let n = arrival.length;
    let cnt = new Array(k).fill(0);
    let busy = new Array(k).fill(0);
    let pq = new PriorityQueue((a, b) => a[0] < b[0]);
    for(let i = 0; i < n; i++){
        let time = arrival[i];
        let l = load[i];
        while(pq.length() > 0 && pq.peek()[0] <= time){
            let [_, id] = pq.poll();
            busy[id] = 0;
        }
        let j = i % k;
        while(busy[j] == 1){
            j = (j + 1) % k;
        }
        cnt[j]++;
        busy[j] = 1;
        pq.offer([time + l, j]);
    }
    let maxCnt = 0;
    let res = [];
    for(let i = 0; i < k; i++){
        if(cnt[i] > maxCnt){
            maxCnt = cnt[i];
            res = [i];
        }else if(cnt[i] == maxCnt){
            res.push(i);
        }
    }
    return res;
    
    
};

    