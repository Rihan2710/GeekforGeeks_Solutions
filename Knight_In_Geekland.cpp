/* Knight in Geekland */
Knight is at (start_x,start_y) in Geekland which is represented by an NxM 2D matrix.
Each cell in the matrix contains some points. In the ith step, the knight can collect all the points from all the cells that can be visited in exactly i steps without revisiting any cell.
Also, the knight has some magical powers that enable him to fetch coins from the future i.e. If the knight can collect y coins in the xth step he can fetch all the coins that he will collect in the (x + y)th step and if the knight can collect z coins in the yth step he can fetch all the coins that he will collect in the (y + z)th step and so on without increasing the step count i.e. knight will stay on xth step and will get all the coins of the future steps mentioned above((x + y)th step coins + (y+z)th steps + ...).
Find the minimum number of steps required to collect the maximum points.
Note: The knight moves exactly the same as the knight on a chess board. Please follow 0 indexing.

Example 1:

Input:
n = 9
m = 10
start_x = 4, start_y = 5
ar =
0 0 0 2 0 2 0 2 0 0
0 0 2 0 2 0 2 0 2 0
0 2 0 0 1 2 0 0 0 2
0 0 2 0 2 0 2 0 2 0
0 2 0 2 0 0 0 2 0 2
0 0 2 0 2 0 2 0 2 0
0 2 0 0 0 2 0 0 0 2
0 0 2 0 2 0 2 0 2 0
0 0 0 2 0 2 0 2 0 0
Output: 1
Explanation: minimum knight have to take 1 steps to gain maximum points.
Initially, the knight has 0 coins, he will take 1 step to collect 1 point (sum of cells denoted in red color).
Now in the second step, he can collect points from all the cells colored green i.e. 64 points.
But with his magical power, at the 1st step, he can fetch points from the (1 + 1)th step. Therefore he can collect 1 + 64 coins at step 1 only. Hence answer is 1.


Code:

class Solution{
public:
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &ar)
    {
        int n=ar.size();
        int m=ar[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        vis[start_x][start_y] = 1;
        queue<pair<int,int>> q;
        q.push({start_x, start_y});
        vector<int> list;
        int points = 0;
        int dx[8]={-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[8]={1, 2, 2, 1, -1, -2, -2, -1};
        auto isSafe=[&](int i, int j)
        {
            return (i>=0 and j>=0 and i<n and j<m);
        };
        while(q.size()){
            int size=q.size();
            points=0;
            for(int i=0;i<size;i++)
            {
                auto tmp = q.front();
                q.pop();
                int x = tmp.first, y = tmp.second;
                points += ar[x][y];
                for(int k = 0; k < 8; k++)
                {
                    int xi = x + dx[k];
                    int xj = y + dy[k];
                    if(isSafe(xi, xj) && !vis[xi][xj])
                    {
                        vis[xi][xj] = 1;
                        q.push({xi, xj});
                    }
                }
            }
            list.push_back(points);
        }
        int max = -1, ans = -1;
        
        for(int i=list.size()-1;i>=0;i--)
        {
            if(list[i] + i < list.size())
                list[i]+=list[i + list[i]];
        }
        for(int i = 0; i < list.size(); i++)
        {
            if(list[i] > max){
                max = list[i];
                ans = i;
            }
        }
        return ans;
    }
};