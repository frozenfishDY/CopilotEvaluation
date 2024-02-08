/**https://leetcode.com/problems/most-popular-video-creator/ */
//You are given two string arrays creators and ids, and an integer array views, all of length n. The ith video on a platform was created by creator[i], has an id of ids[i], and has views[i] views.
//The popularity of a creator is the sum of the number of views on all of the creator's videos. Find the creator with the highest popularity and the id of their most viewed video.
//If multiple creators have the highest popularity, find all of them.
//If multiple videos have the highest view count for a creator, find the lexicographically smallest id.
//Return a 2D array of strings answer where answer[i] = [creatori, idi] means that creatori has the highest popularity and idi is the id of their most popular video. The answer can be returned in any order.


class MostPopularVideoCreator {
    public List<List<String>> mostPopularCreator(String[] creators, String[] ids, int[] views) {
        Map<String, Map<String, Integer>> map = new HashMap<>();
        for(int i = 0; i < creators.length; i++){
            map.putIfAbsent(creators[i], new HashMap<>());
            map.get(creators[i]).put(ids[i], views[i]);
        }
        int max = 0;
        List<List<String>> res = new ArrayList<>();
        for(String creator : map.keySet()){
            int sum = 0;
            for(String id : map.get(creator).keySet()){
                sum += map.get(creator).get(id);
            }
            if(sum > max){
                max = sum;
                res = new ArrayList<>();
                res.add(Arrays.asList(creator, getMostPopularVideo(map.get(creator))));
            }else if(sum == max){
                res.add(Arrays.asList(creator, getMostPopularVideo(map.get(creator))));
            }
        }
        return res;
        
        
    }
}
     
    