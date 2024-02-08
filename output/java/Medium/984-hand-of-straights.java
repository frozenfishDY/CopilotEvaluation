/**https://leetcode.com/problems/hand-of-straights/ */
//Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
//Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.


class HandOfStraights {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if(hand.length % groupSize != 0){
            return false;
        }
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for(int i : hand){
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        while(!map.isEmpty()){
            int start = map.firstKey();
            for(int i = start; i < start + groupSize; i++){
                if(!map.containsKey(i)){
                    return false;
                }
                int count = map.get(i);
                if(count == 1){
                    map.remove(i);
                }else{
                    map.put(i, count - 1);
                }
            }
        }
        return true;
        
        
        
    }
}

    