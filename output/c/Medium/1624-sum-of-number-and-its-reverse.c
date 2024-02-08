/**https://leetcode.com/problems/sum-of-number-and-its-reverse/ */
//Given a non-negative integer num, return true if num can be expressed as the sum of any non-negative integer and its reverse, or false otherwise.


bool sumOfNumberAndReverse(int num){
    int i, j, k, sum = 0, reverse = 0, temp = 0;
    for(i = 0; i < num; i++){
        temp = i;
        reverse = 0;
        while(temp != 0){
            reverse = reverse * 10 + temp % 10;
            temp = temp / 10;
        }
        sum = i + reverse;
        if(sum == num){
            return true;
        }
    }
    return false;

}

    