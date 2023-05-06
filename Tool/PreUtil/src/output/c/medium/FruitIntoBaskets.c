/**https://leetcode.com/problems/fruit-into-baskets/ */
//You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
//You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
//You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
//Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
//Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
//Given the integer array fruits, return the maximum number of fruits you can pick.


int totalFruit(int* fruits, int fruitsSize){
    int* hash = (int*)malloc(sizeof(int) * 10001);
    for(int i = 0; i < 10001; i++){
        hash[i] = 0;
    }
    int result = 0;
    int left = 0;
    int right = 0;
    int count = 0;
    while(right < fruitsSize){
        if(hash[fruits[right]] == 0){
            count++;
        }
        hash[fruits[right]]++;
        right++;
        while(count > 2){
            hash[fruits[left]]--;
            if(hash[fruits[left]] == 0){
                count--;
            }
            left++;
        }
        result = result > right - left ? result : right - left;
    }
    return result;

}

    