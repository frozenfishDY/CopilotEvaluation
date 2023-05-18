## RQ1_to_RQ3

This folder contains experiment results of RQ1~RQ3

**Table1.xlsx:** Performance of Copilot. This table records the ratio of submitted code statuses in 4 languages.

**Table2.xlsx**: Performance of Copilot in Easy, Medium, Hard Problems. This table records the ratio of submitted code statuses in 4 languages in 3 difficulties.

**TypePerformance.xlsx**: Copilot's Performance on the Code Problems in Different Types. This table records the ratio of correct code suggestion in 4 Languages on 12 problem types(*Array, String, Hash Table, Dynamic Programming, Math, Sorting, Greedy, DFS, Binary Search, BFS, Matrix, Binary Tree*).

**json:** this folder contains all JSON files related to our reasearch questions. Each JSON file records the questions id(see *SubmissionResult.xlsx*) corresponding to its submission status and problem difficulty. Its structure is as follows:

```powershell
├── type                       :json files in this folder records solved/unsolved id-difficulty pairs(RQ3)
   ├── array.json
   ├── bfs.json
   ├── binary_search.json
   ├── binary_tree.json
   ├── dfs.json
   ├── dynamic_programming.json
   ├── greedy.json
   ├── hash_table.json
   ├── math.json
   ├── matrix.json
   ├── sorting.json
   ├── string.json  
├── c_id.json                    :record id-difficulty-status pairs in C(RQ1,2)                
├── HasAccepted.json             :record id-difficulty pairs in HasAccepted status
├── java_id.json                 :record id-difficulty-status pairs in Java
├── js_id.json                   :record id-difficulty-status pairs in JavaScript
├── py_id.json                   :record id-difficulty-status pais in Python
├──README.md                     :guidance 
```

