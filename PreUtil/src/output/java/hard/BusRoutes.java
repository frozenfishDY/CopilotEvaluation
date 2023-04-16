/**https://leetcode.com/problems/bus-routes/ */
//You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.
//For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
//You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
//Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.


class BusRoutes {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) {
            return 0;
        }
        int n = routes.length;
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            for (int site : routes[i]) {
                List<Integer> list = map.getOrDefault(site, new ArrayList<>());
                for (int j : list) {
                    graph.get(i).add(j);
                    graph.get(j).add(i);
                }
                list.add(i);
                map.put(site, list);
            }
        }
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[n];
        for (int bus : map.get(source)) {
            queue.offer(bus);
            visited[bus] = true;
        }
        int step = 0;
        while (!queue.isEmpty()) {
            step++;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int bus = queue.poll();
                for (int nextBus : graph.get(bus)) {
                    if (visited[nextBus]) {
                        continue;
                    }
                    visited[nextBus] = true;
                    for (int site : routes[nextBus]) {
                        if (site == target) {
                            return step;
                        }
                        for (int nextNextBus : map.get(site)) {
                            if (!visited[nextNextBus]) {
                                queue.offer(nextNextBus);
                            }
                        }
                    }
                }
            }
        }
        return -1;
        
    }
}
     
    