/**https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/ */
//You have the task of delivering some boxes from storage to their ports using only one ship. However, this ship has a limit on the number of boxes and the total weight that it can carry.
//You are given an array boxes, where boxes[i] = [portsi, weighti], and three integers portsCount, maxBoxes, and maxWeight.
//portsi is the port where you need to deliver the ith box and weightsi is the weight of the ith box.
//portsCount is the number of ports.
//maxBoxes and maxWeight are the respective box and weight limits of the ship.
//The boxes need to be delivered in the order they are given. The ship will follow these steps:
//The ship will take some number of boxes from the boxes queue, not violating the maxBoxes and maxWeight constraints.
//For each loaded box in order, the ship will make a trip to the port the box needs to be delivered to and deliver it. If the ship is already at the correct port, no trip is needed, and the box can immediately be delivered.
//The ship then makes a return trip to storage to take more boxes from the queue.
//The ship must end at storage after all the boxes have been delivered.
//Return the minimum number of trips the ship needs to make to deliver all boxes to their respective ports.


class DeliveringBoxesFromStorageToPorts {
    public int boxDelivering(int[][] boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.length;
        int[] dp = new int[n + 1];
        int[] next = new int[n];
        int j = n;
        int weight = 0;
        for(int i = n - 1; i >= 0; i--){
            weight += boxes[i][1];
            while(j > i && (j - i > maxBoxes || weight > maxWeight)){
                j--;
                weight -= boxes[j][1];
            }
            next[i] = j;
        }
        int port = -1;
        for(int i = n - 1; i >= 0; i--){
            while(next[i] < n && boxes[next[i]][0] == boxes[next[i] - 1][0]){
                next[i] = next[next[i]];
            }
            dp[i] = dp[next[i]] + 1;
            if(boxes[i][0] != port){
                port = boxes[i][0];
                dp[i]++;
            }
        }
        return dp[0];
        
    }
}
     
    