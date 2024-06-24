class Solution {
public:
    void dfa(int src, vector<vector<int>>& isConnected, int vis[]){
        vis[src] = 1;
        for(int i = 0; i < isConnected.size(); i++){
            if(i != src && isConnected[src][i] == 1 && !vis[i]){
                dfa(i, isConnected, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int vis[isConnected.size()];
        memset(vis, 0, sizeof(vis));
        
        for(int i = 0; i < isConnected.size(); i++){
            if(!vis[i]){
                dfa(i, isConnected, vis);
                count++;
            }
        }
        return count;
    }
};
