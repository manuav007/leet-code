class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(N); 
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]); 
        }
        vector<int> indig(N, 0);
        for(int i = 0; i < N; i++){
            for(auto it : adj[i]){
                indig[it]++;  
            }
        }
        queue<int> qu;
        for(int i = 0; i < N; i++){
            if(indig[i] == 0){
                qu.push(i);
            }
        }
        vector<int> vn;
        while(!qu.empty()){
            int node = qu.front();
            vn.push_back(node);
            qu.pop();
            for(auto it : adj[node]){
                indig[it]--;  
                if(indig[it] == 0) {  
                    qu.push(it);
                }
            }
        }
        if(vn.size() == N) 
            return true;
        else 
            return false;
    }
};
