/**https://leetcode.com/problems/evaluate-division/ */
//You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.
//You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
//Return the answers to all queries. If a single answer cannot be determined, return -1.0.
//Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.


class EvaluateDivision {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        int n = equations.size();
        Map<String, Integer> map = new HashMap<>();
        int idx = 0;
        for(int i = 0; i < n; i++){
            String a = equations.get(i).get(0);
            String b = equations.get(i).get(1);
            if(!map.containsKey(a)){
                map.put(a, idx++);
            }
            if(!map.containsKey(b)){
                map.put(b, idx++);
            }
        }
        double[][] g = new double[idx][idx];
        for(int i = 0; i < idx; i++){
            Arrays.fill(g[i], -1);
        }
        for(int i = 0; i < n; i++){
            String a = equations.get(i).get(0);
            String b = equations.get(i).get(1);
            int x = map.get(a);
            int y = map.get(b);
            g[x][y] = values[i];
            g[y][x] = 1 / values[i];
        }
        for(int i = 0; i < idx; i++){
            g[i][i] = 1;
        }
        for(int k = 0; k < idx; k++){
            for(int i = 0; i < idx; i++){
                for(int j = 0; j < idx; j++){
                    if(g[i][k] != -1 && g[k][j] != -1){
                        g[i][j] = g[i][k] * g[k][j];
                    }
                }
            }
        }
        int m = queries.size();
        double[] res = new double[m];
        for(int i = 0; i < m; i++){
            String a = queries.get(i).get(0);
            String b = queries.get(i).get(1);
            if(!map.containsKey(a) || !map.containsKey(b)){
                res[i] = -1;
            }else{
                int x = map.get(a);
                int y = map.get(b);
                res[i] = g[x][y];
            }
        }
        return res;
        
        
    }
}

    