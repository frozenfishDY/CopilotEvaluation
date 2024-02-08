/**https://leetcode.com/problems/subdomain-visit-count/ */
//A website domain "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com" and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.
//A count-paired domain is a domain that has one of the two formats "rep d1.d2.d3" or "rep d1.d2" where rep is the number of visits to the domain and d1.d2.d3 is the domain itself.
//For example, "9001 discuss.leetcode.com" is a count-paired domain that indicates that discuss.leetcode.com was visited 9001 times.
//Given an array of count-paired domains cpdomains, return an array of the count-paired domains of each subdomain in the input. You may return the answer in any order.


class SubdomainVisitCount {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> map = new HashMap<>();
        for(String cpdomain : cpdomains){
            String[] arr = cpdomain.split(" ");
            int count = Integer.parseInt(arr[0]);
            String domain = arr[1];
            map.put(domain, map.getOrDefault(domain, 0) + count);
            for(int i = 0; i < domain.length(); i++){
                if(domain.charAt(i) == '.'){
                    String subdomain = domain.substring(i + 1);
                    map.put(subdomain, map.getOrDefault(subdomain, 0) + count);
                }
            }
        }
        List<String> res = new ArrayList<>();
        for(String domain : map.keySet()){
            res.add(map.get(domain) + " " + domain);
        }
        return res;
        
    }
}

    