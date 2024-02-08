/**https://leetcode.com/problems/super-pow/ */
//Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.


int superPow(int a, int* b, int bSize){
    int result = 1;
    for(int i = 0; i < bSize; i++){
        result = pow(result, 10) * pow(a, b[i]) % 1337;
    }
    return result;

}

    