/**https://leetcode.com/problems/number-of-flowers-in-full-bloom/ */
//You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array people of size n, where poeple[i] is the time that the ith person will arrive to see the flowers.
//Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.
// 
//Example 1:
//Input: flowers = [[1,6],[3,7],[9,12],[4,13]], poeple = [2,3,7,11]
//Output: [1,2,2,2]
//Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
//For each person, we return the number of flowers in full bloom during their arrival.
//Example 2:
//Input: flowers = [[1,10],[3,3]], poeple = [3,3,2]
//Output: [2,2,1]
//Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
//For each person, we return the number of flowers in full bloom during their arrival.
// 
//Constraints:
//	1 <= flowers.length <= 5 * 104
//	flowers[i].length == 2
//	1 <= starti <= endi <= 109
//	1 <= people.length <= 5 * 104
//	1 <= people[i] <= 109
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fullBloomFlowers(int** flowers, int flowersSize, int* flowersColSize, int* people, int peopleSize, int* returnSize){
int i, j, min, max, count = 0;
    for (i = 0; i < flowersSize; i++) {
        min = flowers[i]; max = flowers[i];
        for (j = i + 1; j < flowersSize; j++) {
            if (flowers[j] < min) min = flowers[j];
            else if (flowers[j] > max) max = flowers[j];
            if (max - min == j - i) break;
        }
        if (j == flowersSize) count++;
    }
    return count;

}