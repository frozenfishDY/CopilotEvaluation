/**https://leetcode.com/problems/reward-top-k-students/ */
//You are given two string arrays positive_feedback and negative_feedback, containing the words denoting positive and negative feedback, respectively. Note that no word is both positive and negative.
//Initially every student has 0 points. Each positive word in a feedback report increases the points of a student by 3, whereas each negative word decreases the points by 1.
//You are given n feedback reports, represented by a 0-indexed string array report and a 0-indexed integer array student_id, where student_id[i] represents the ID of the student who has received the feedback report report[i]. The ID of each student is unique.
//Given an integer k, return the top k students after ranking them in non-increasing order by their points. In case more than one student has the same points, the one with the lower ID ranks higher.


class RewardTopKStudents {
    public List<Integer> topStudents(String[] positive_feedback, String[] negative_feedback, String[] report, int[] student_id, int k) {
        Map<String, Integer> positive = new HashMap<>();
        Map<String, Integer> negative = new HashMap<>();
        for(String s : positive_feedback){
            positive.put(s, positive.getOrDefault(s, 0) + 1);
        }
        for(String s : negative_feedback){
            negative.put(s, negative.getOrDefault(s, 0) + 1);
        }
        Map<Integer, Integer> points = new HashMap<>();
        for(int i = 0; i < report.length; i++){
            String[] words = report[i].split(" ");
            for(String word : words){
                if(positive.containsKey(word)){
                    points.put(student_id[i], points.getOrDefault(student_id[i], 0) + 3);
                }else if(negative.containsKey(word)){
                    points.put(student_id[i], points.getOrDefault(student_id[i], 0) - 1);
                }
            }
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if(a[0] == b[0]){
                return a[1] - b[1];
            }
            return b[0] - a[0];
        });
        for(int id : points.keySet()){
            pq.add(new int[]{points.get(id), id});
        }
        List<Integer> ans = new ArrayList<>();
        while(k-- > 0){
            ans.add(pq.poll()[1]);
        }
        return ans;
    }
}

    