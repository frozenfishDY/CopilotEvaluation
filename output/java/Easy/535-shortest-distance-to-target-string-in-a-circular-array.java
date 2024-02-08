/**https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/ */
//You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.
//Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n], where n is the length of words.
//Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.
//Return the shortest distance needed to reach the string target. If the string target does not exist in words, return -1.


class ShortestDistanceToTargetStringInACircularArray {
    public int closetTarget(String[] words, String target, int startIndex) {
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < words.length; i++){
            if(words[i].equals(target)){
                min = Math.min(min, Math.abs(i - startIndex));
            }
        }
        return min == Integer.MAX_VALUE ? -1 : min;
        
    }
}

    