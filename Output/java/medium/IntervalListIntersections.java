/**https://leetcode.com/problems/interval-list-intersections/ */
//You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.
//Return the intersection of these two interval lists.
//A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
//The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].


class IntervalListIntersections {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        List<int[]> res = new ArrayList<>();
        int i = 0;
        int j = 0;
        while(i < firstList.length && j < secondList.length){
            int[] first = firstList[i];
            int[] second = secondList[j];
            if(first[0] <= second[0]){
                if(first[1] >= second[0]){
                    res.add(new int[]{second[0], Math.min(first[1], second[1])});
                }
                i++;
            }else{
                if(second[1] >= first[0]){
                    res.add(new int[]{first[0], Math.min(first[1], second[1])});
                }
                j++;
            }
        }
        return res.toArray(new int[res.size()][]);
        
        
    }
}

    