class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        
        int modulo = (int)1e9+7; 
        vector<vector<int>> uq_paths(n, vector<int>(m, 0)); 
        
        if (grid[0][0] == 1){
            uq_paths[0][0] = 1; }
        
        for(int i = 1; i < n; i++)
        {  
        if (grid[i][0] == 1) {
            uq_paths[i][0] = uq_paths[i-1][0]; }
        } 
        
        for(int j = 1; j < m; j++) 
        {
        if (grid[0][j] == 1) {
            uq_paths[0][j] = uq_paths[0][j - 1]; }
        } 
        
        for(int i = 1; i < n; i++) 
        { 
            for(int j = 1; j < m; j++) 
            {  
                if (grid[i][j] == 1) {
                    uq_paths[i][j] = (uq_paths[i - 1][j] % modulo + uq_paths[i][j - 1] % modulo) % modulo; }
                
            } 
        } 
        return uq_paths[n - 1][m-1]%modulo;
 
       
    }
};