/**https://leetcode.com/problems/the-latest-time-to-catch-a-bus/ */
//You are given a 0-indexed integer array buses of length n, where buses[i] represents the departure time of the ith bus. You are also given a 0-indexed integer array passengers of length m, where passengers[j] represents the arrival time of the jth passenger. All bus departure times are unique. All passenger arrival times are unique.
//You are given an integer capacity, which represents the maximum number of passengers that can get on each bus.
//When a passenger arrives, they will wait in line for the next available bus. You can get on a bus that departs at x minutes if you arrive at y minutes where y <= x, and the bus is not full. Passengers with the earliest arrival times get on the bus first.
//More formally when a bus arrives, either:
//	If capacity or fewer passengers are waiting for a bus, they will all get on the bus, or
//	The capacity passengers with the earliest arrival times will get on the bus.
//Return the latest time you may arrive at the bus station to catch a bus. You cannot arrive at the same time as another passenger.
//Note: The arrays buses and passengers are not necessarily sorted.
// 
//Example 1:
//Input: buses = [10,20], passengers = [2,17,18,19], capacity = 2
//Output: 16
//Explanation: Suppose you arrive at time 16.
//At time 10, the first bus departs with the 0th passenger. 
//At time 20, the second bus departs with you and the 1st passenger.
//Note that you may not arrive at the same time as another passenger, which is why you must arrive before the 1st passenger to catch the bus.
//Example 2:
//Input: buses = [20,30,10], passengers = [19,13,26,4,25,11,21], capacity = 2
//Output: 20
//Explanation: Suppose you arrive at time 20.
//At time 10, the first bus departs with the 3rd passenger. 
//At time 20, the second bus departs with the 5th and 1st passengers.
//At time 30, the third bus departs with the 0th passenger and you.
//Notice if you had arrived any later, then the 6th passenger would have taken your seat on the third bus.
// 
//Constraints:
//	n == buses.length
//	m == passengers.length
//	1 <= n, m, capacity <= 105
//	2 <= buses[i], passengers[i] <= 109
//	Each element in buses is unique.
//	Each element in passengers is unique.
int latestTimeCatchTheBus(int* buses, int busesSize, int* passengers, int passengersSize, int capacity){
int i;
    int j;
    int k;
    int count;
    int left;
    int right;
    int prev;
    int next;
    int* ret = malloc(sizeof(int)*2);
    struct ListNode* node = head;
    i=0;
    while(node){
        arr[i++]=node->val;
        node=node->next;
    }
    ret[0]=arr[left-1];
    ret[1]=arr[right-1];
    *returnSize=2;
    return ret;
}