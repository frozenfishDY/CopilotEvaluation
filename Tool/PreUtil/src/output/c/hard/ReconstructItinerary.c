/**https://leetcode.com/problems/reconstruct-itinerary/ */
//You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.
//All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
//For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
//You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findItinerary(char *** tickets, int ticketsSize, int* ticketsColSize, int* returnSize){
    char** result = (char**)malloc(sizeof(char*) * (ticketsSize + 1));
    char** queue = (char**)malloc(sizeof(char*) * ticketsSize);
    int head = 0, tail = 0;
    for(int i = 0; i < ticketsSize; i++){
        while(head < tail && strcmp(queue[tail - 1][1], tickets[i][1]) > 0) tail--;
        queue[tail++] = tickets[i];
        if(i - head >= ticketsSize) head++;
        if(i >= ticketsSize - 1) result[i - ticketsSize + 1] = tickets[i][0];
    }
    *returnSize = ticketsSize + 1;
    return result;

}

    