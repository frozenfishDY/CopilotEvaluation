/**https://leetcode.com/problems/binary-watch/ */
//A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.
//For example, the below binary watch reads "4:51".
//Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.
//The hour must not contain a leading zero.
//For example, "01:00" is not valid. It should be "1:00".
//The minute must be consist of two digits and may contain a leading zero.
//For example, "10:2" is not valid. It should be "10:02".


class BinaryWatch {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> result = new ArrayList<>();
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 60; j++){
                if(Integer.bitCount(i) + Integer.bitCount(j) == turnedOn){
                    result.add(i + ":" + (j < 10 ? "0" + j : j));
                }
            }
        }
        return result;
        
        
    }
}

    