/**https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/ */
//You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but cannot handle more than one request at a time. The requests are assigned to servers according to a specific algorithm:
//The ith (0-indexed) request arrives.
//If all servers are busy, the request is dropped (not handled at all).
//If the (i % k)th server is available, assign the request to that server.
//Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the ith server is busy, try to assign the request to the (i+1)th server, then the (i+2)th server, and so on.
//You are given a strictly increasing array arrival of positive integers, where arrival[i] represents the arrival time of the ith request, and another array load, where load[i] represents the load of the ith request (the time it takes to complete). Your goal is to find the busiest server(s). A server is considered busiest if it handled the most number of requests successfully among all the servers.
//Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.


class FindServersThatHandledMostNumberOfRequests {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
        int n = arrival.length;
        int[] count = new int[k];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        PriorityQueue<Integer> available = new PriorityQueue<>();
        for(int i = 0; i < k; i++){
            available.offer(i);
        }
        for(int i = 0; i < n; i++){
            while(!pq.isEmpty() && pq.peek()[0] <= arrival[i]){
                available.offer(pq.poll()[1]);
            }
            if(available.isEmpty()){
                continue;
            }
            int idx = available.poll();
            count[idx]++;
            pq.offer(new int[]{arrival[i] + load[i], idx});
        }
        int max = 0;
        for(int i = 0; i < k; i++){
            max = Math.max(max, count[i]);
        }
        List<Integer> res = new ArrayList<>();
        for(int i = 0; i < k; i++){
            if(count[i] == max){
                res.add(i);
            }
        }
        return res;
        
    }
}
     
    