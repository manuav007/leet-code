class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<vector<int>> ind(N);  
        for(const auto& prerequisite : prerequisites){  
            ind[prerequisite[1]].push_back(prerequisite[0]); 
        }
        vector<int> mark(N, 0); 
        for(int i = 0; i < N; i++){
            for(auto it : ind[i]){
                mark[it]++;  
            }
        }
        queue<int> qu;
        for(int i = 0; i < N; i++){
            if(mark[i] == 0){
                qu.push(i);
            }
        }
        vector<int> topo;
        while(!qu.empty()){ 
            int node = qu.front();
            qu.pop();
            topo.push_back(node);
            for(auto it : ind[node]){  
                mark[it]--; 
                if(mark[it] == 0) qu.push(it); 
            }
        }
        if(topo.size() == N) return topo;
        else return {};
    }
};
