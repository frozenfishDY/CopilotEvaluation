/**https://leetcode.com/problems/pascals-triangle-ii/ */
//Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


class PascalsTriangleIi {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> res = new ArrayList<>();
        for(int i = 0; i <= rowIndex; i++){
            res.add(0, 1);
            for(int j = 1; j < res.size() - 1; j++){
                res.set(j, res.get(j) + res.get(j + 1));
            }
        }
        return res;
        
    }
}

    