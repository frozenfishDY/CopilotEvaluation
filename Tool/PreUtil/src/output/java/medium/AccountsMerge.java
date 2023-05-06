/**https://leetcode.com/problems/accounts-merge/ */
//Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
//Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
//After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.


class AccountsMerge {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, String> emailToName = new HashMap<>();
        Map<String, List<String>> graph = new HashMap<>();
        for(List<String> account : accounts){
            String name = account.get(0);
            for(int i = 1; i < account.size(); i++){
                String email = account.get(i);
                emailToName.put(email, name);
                graph.computeIfAbsent(email, x -> new ArrayList<>()).add(account.get(1));
                graph.computeIfAbsent(account.get(1), x -> new ArrayList<>()).add(email);
            }
        }
        Set<String> seen = new HashSet<>();
        List<List<String>> res = new ArrayList<>();
        for(String email : graph.keySet()){
            if(!seen.contains(email)){
                seen.add(email);
                Stack<String> stack = new Stack<>();
                stack.push(email);
                List<String> component = new ArrayList<>();
                while(!stack.isEmpty()){
                    String node = stack.pop();
                    component.add(node);
                    for(String nei : graph.get(node)){
                        if(!seen.contains(nei)){
                            seen.add(nei);
                            stack.push(nei);
                        }
                    }
                }
                Collections.sort(component);
                component.add(0, emailToName.get(email));
                res.add(component);
            }
        }
        return res;
        
        
    }
}

    