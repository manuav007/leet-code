class Solution {
public:
    void solve(int col,int& ans,vector<string> d, vector<int> row,vector<int> upperdig,vector<int> lowerdig,int n){
        if(col == n){
            ++ans;
            return;
        }
        for(int i=0; i<n;i++){
            if(row[i] == 0 && upperdig[i + col] == 0 && lowerdig[n - 1 + col - i] == 0){
                d[i][col] == 'Q';
                row[i] = 1;
                upperdig[i + col] = 1; 
                lowerdig[n - 1 + col - i] = 1;
                solve(col+1,ans,d,row,upperdig,lowerdig,n);
                d[i][col] == '.';
                row[i] = 0;
                upperdig[i + col] = 0; 
                lowerdig[n - 1 + col - i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> d(n);
        string s(n,'.');
        for(int i=0; i<n; i++){
            d[i] = s;
        } 
        vector<int> row(n,0);
        vector<int> upperdig(2*n-1,0);
        vector<int> lowerdig(2*n-1,0);
        solve(0,ans,d,row,upperdig,lowerdig,n);
        return ans;
    }
};
