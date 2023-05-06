/**https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/ */
//You are given a 0-indexed integer array forts of length n representing the positions of several forts. forts[i] can be -1, 0, or 1 where:
//-1 represents there is no fort at the ith position.
//0 indicates there is an enemy fort at the ith position.
//1 indicates the fort at the ith the position is under your command.
//Now you have decided to move your army from one of your forts at position i to an empty position j such that:
//0 <= i, j <= n - 1
//The army travels over enemy forts only. Formally, for all k where min(i,j) < k < max(i,j), forts[k] == 0.
//While moving the army, all the enemy forts that come in the way are captured.
//Return the maximum number of enemy forts that can be captured. In case it is impossible to move your army, or you do not have any fort under your command, return 0.


class MaximumEnemyFortsThatCanBeCaptured {
    public int captureForts(int[] forts) {
        int max = 0;
        int count = 0;
        for(int i = 0; i < forts.length; i++){
            if(forts[i] == 1){
                count++;
            }
        }
        if(count == 0) return 0;
        for(int i = 0; i < forts.length; i++){
            if(forts[i] == 1){
                int j = i;
                int k = i;
                int temp = 0;
                while(j >= 0 && forts[j] != -1){
                    if(forts[j] == 0){
                        temp++;
                    }
                    j--;
                }
                while(k < forts.length && forts[k] != -1){
                    if(forts[k] == 0){
                        temp++;
                    }
                    k++;
                }
                max = Math.max(max, temp);
            }
        }
        return max;
        
        
        
    }
}

    