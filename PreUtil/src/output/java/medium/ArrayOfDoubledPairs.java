/**https://leetcode.com/problems/array-of-doubled-pairs/ */
//Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.


class ArrayOfDoubledPairs {
    public boolean canReorderDoubled(int[] arr) {
        int n = arr.length;
        Map<Integer, Integer> map = new HashMap<>();
        for(int i : arr){
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        List<Integer> list = new ArrayList<>(map.keySet());
        Collections.sort(list, (a, b) -> Math.abs(a) - Math.abs(b));
        for(int i : list){
            if(map.get(i) > map.getOrDefault(2 * i, 0)){
                return false;
            }
            map.put(2 * i, map.get(2 * i) - map.get(i));
        }
        return true;
        
    }
}

    