/**https://leetcode.com/problems/elimination-game/ */
//You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr:
//Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
//Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
//Keep repeating the steps again, alternating left to right and right to left, until a single number remains.
//Given the integer n, return the last number that remains in arr.


int lastRemaining(int n){
    int head = 1;
    int step = 1;
    int remaining = n;
    int left = 1;
    while(remaining > 1){
        if(left || remaining % 2 == 1){
            head += step;
        }
        remaining /= 2;
        step *= 2;
        left = !left;
    }
    return head;

}

    