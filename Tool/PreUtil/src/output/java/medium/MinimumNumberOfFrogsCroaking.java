/**https://leetcode.com/problems/minimum-number-of-frogs-croaking/ */
//You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.
//Return the minimum number of different frogs to finish all the croaks in the given string.
//A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.


class MinimumNumberOfFrogsCroaking {
    public int minNumberOfFrogs(String croakOfFrogs) {
        int[] count = new int[5];
        int frogs = 0;
        int maxFrogs = 0;
        for(char c : croakOfFrogs.toCharArray()){
            if(c == 'c'){
                count[0]++;
                frogs++;
                maxFrogs = Math.max(maxFrogs, frogs);
            }
            else if(c == 'r'){
                if(count[0] == 0){
                    return -1;
                }
                count[0]--;
                count[1]++;
            }
            else if(c == 'o'){
                if(count[1] == 0){
                    return -1;
                }
                count[1]--;
                count[2]++;
            }
            else if(c == 'a'){
                if(count[2] == 0){
                    return -1;
                }
                count[2]--;
                count[3]++;
            }
            else if(c == 'k'){
                if(count[3] == 0){
                    return -1;
                }
                count[3]--;
                frogs--;
            }
        }
        for(int i = 0; i < 5; i++){
            if(count[i] != 0){
                return -1;
            }
        }
        return maxFrogs;
        
        
    }
}

    