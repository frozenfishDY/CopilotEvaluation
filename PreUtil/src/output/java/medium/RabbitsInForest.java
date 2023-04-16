/**https://leetcode.com/problems/rabbits-in-forest/ */
//There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.
//Given the array answers, return the minimum number of rabbits that could be in the forest.


class RabbitsInForest {
    public int numRabbits(int[] answers) {
        int[] cnt = new int[1000];
        for(int ans : answers){
            cnt[ans]++;
        }
        int res = 0;
        for(int i = 0; i < 1000; i++){
            res += (cnt[i] + i) / (i + 1) * (i + 1);
        }
        return res;
        
    }
}

    