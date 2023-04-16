/**https://leetcode.com/problems/reordered-power-of-2/ */
//You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
//Return true if and only if we can do this so that the resulting number is a power of two.


bool reorderedPowerOf2(int n){
    int* count = (int*)malloc(sizeof(int) * 10);
    for(int i = 0; i < 10; i++){
        count[i] = 0;
    }
    int temp = n;
    while(temp > 0){
        count[temp % 10]++;
        temp /= 10;
    }
    for(int i = 0; i < 31; i++){
        int* count2 = (int*)malloc(sizeof(int) * 10);
        for(int i = 0; i < 10; i++){
            count2[i] = 0;
        }
        temp = 1 << i;
        while(temp > 0){
            count2[temp % 10]++;
            temp /= 10;
        }
        int flag = 1;
        for(int i = 0; i < 10; i++){
            if(count[i] != count2[i]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            return true;
        }
    }
    return false;

}

    