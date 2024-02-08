/**https://leetcode.com/problems/most-profitable-path-in-a-tree/ */
//There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:
//the price needed to open the gate at node i, if amount[i] is negative, or,
//the cash reward obtained on opening the gate at node i, otherwise.
//The game goes on as follows:
//Initially, Alice is at node 0 and Bob is at node bob.
//At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
//For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
//If the gate is already open, no price will be required, nor will there be any cash reward.
//If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
//If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.
//Return the maximum net income Alice can have if she travels towards the optimal leaf node.


int mostProfitablePath(int** edges, int edgesSize, int* edgesColSize, int bob, int* amount, int amountSize){
    int* dp = (int*)malloc(sizeof(int) * amountSize);
    int* dp2 = (int*)malloc(sizeof(int) * amountSize);
    int* dp3 = (int*)malloc(sizeof(int) * amountSize);
    int* dp4 = (int*)malloc(sizeof(int) * amountSize);
    int* dp5 = (int*)malloc(sizeof(int) * amountSize);
    int* dp6 = (int*)malloc(sizeof(int) * amountSize);
    int* dp7 = (int*)malloc(sizeof(int) * amountSize);
    int* dp8 = (int*)malloc(sizeof(int) * amountSize);
    int* dp9 = (int*)malloc(sizeof(int) * amountSize);
    int* dp10 = (int*)malloc(sizeof(int) * amountSize);
    int* dp11 = (int*)malloc(sizeof(int) * amountSize);
    int* dp12 = (int*)malloc(sizeof(int) * amountSize);
    int* dp13 = (int*)malloc(sizeof(int) * amountSize);
    int* dp14 = (int*)malloc(sizeof(int) * amountSize);
    int* dp15 = (int*)malloc(sizeof(int) * amountSize);
    int* dp16 = (int*)malloc(sizeof(int) * amountSize);
    int* dp17 = (int*)malloc(sizeof(int) * amountSize);
    int* dp18 = (int*)malloc(sizeof(int) * amountSize);
    int* dp19 = (int*)malloc(sizeof(int) * amountSize);
    int* dp20 = (int*)malloc(sizeof(int) * amountSize);
    int* dp21 = (int*)malloc(sizeof(int) * amountSize);
    int* dp22 = (int*)malloc(sizeof(int) * amountSize);
    int* dp23 = (int*)malloc(sizeof(int) * amountSize);
    int* dp24 = (int*)malloc(sizeof(int) * amountSize);
    int* dp25 = (int*)malloc(sizeof(int) * amountSize);
    int* dp26 = (int*)malloc(sizeof(int) * amountSize);
    int* dp27 = (int*)malloc(sizeof(int) * amountSize);
    int* dp28 = (int*)malloc(sizeof(int) * amountSize);
    int* dp29 = (int*)malloc(sizeof(int) * amountSize);
    

}

    