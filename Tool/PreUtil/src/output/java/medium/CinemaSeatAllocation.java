/**https://leetcode.com/problems/cinema-seat-allocation/ */
//A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as shown in the figure above.
//Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.
//Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but there is an exceptional case on which an aisle split a four-person group, in that case, the aisle split a four-person group in the middle, which means to have two people on each side.


class CinemaSeatAllocation {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        int count = 0;
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for(int[] seat : reservedSeats){
            map.putIfAbsent(seat[0], new HashSet<>());
            map.get(seat[0]).add(seat[1]);
        }
        for(int i = 1; i <= n; i++){
            Set<Integer> set = map.getOrDefault(i, new HashSet<>());
            if(!set.contains(2) && !set.contains(3) && !set.contains(4) && !set.contains(5)){
                count++;
                set.add(2);
                set.add(3);
                set.add(4);
                set.add(5);
            }
            if(!set.contains(6) && !set.contains(7) && !set.contains(8) && !set.contains(9)){
                count++;
                set.add(6);
                set.add(7);
                set.add(8);
                set.add(9);
            }
            if(!set.contains(4) && !set.contains(5) && !set.contains(6) && !set.contains(7)){
                count++;
            }
        }
        return count;
        
        
    }
}

    