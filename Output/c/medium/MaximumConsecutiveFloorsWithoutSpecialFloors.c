/**https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/ */
//Alice manages a company and has rented some floors of a building as office space. Alice has decided some of these floors should be special floors, used for relaxation only.
//You are given two integers bottom and top, which denote that Alice has rented all the floors from bottom to top (inclusive). You are also given the integer array special, where special[i] denotes a special floor that Alice has designated for relaxation.
//Return the maximum number of consecutive floors without a special floor.


int maxConsecutive(int bottom, int top, int* special, int specialSize){
    int i, j, k, count = 0, max = 0, temp = 0;
    for(i = bottom; i <= top; i++){
        count = 0;
        for(j = 0; j < specialSize; j++){
            if(i == special[j]){
                count++;
            }
        }
        if(count == 0){
            temp++;
        }
        else{
            if(temp > max){
                max = temp;
            }
            temp = 0;
        }
    }
    if(temp > max){
        max = temp;
    }
    return max;

}

    