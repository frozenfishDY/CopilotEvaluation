/**https://leetcode.com/problems/fruit-into-baskets/ */
//You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
//You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
//You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
//Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
//Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
//Given the integer array fruits, return the maximum number of fruits you can pick.


class FruitIntoBaskets {
    public int totalFruit(int[] fruits) {
        int res = 0;
        int i = 0;
        int j = 0;
        int count = 0;
        int[] map = new int[fruits.length];
        while(j < fruits.length){
            if(map[fruits[j]] == 0){
                count++;
            }
            map[fruits[j]]++;
            j++;
            while(count > 2){
                map[fruits[i]]--;
                if(map[fruits[i]] == 0){
                    count--;
                }
                i++;
            }
            res = Math.max(res, j - i);
        }
        return res;
        
    }
}

    