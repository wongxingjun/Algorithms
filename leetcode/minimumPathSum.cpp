/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> path(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0)
                {
                    if(j==0)
                        path[i][j]=grid[i][j];
                    else
                        path[i][j]=path[i][j-1]+grid[i][j];
                }
                else if(j==0)
                    path[i][j]=path[i-1][j]+grid[i][j];
                else
                    path[i][j]=min(path[i][j-1],path[i-1][j])+grid[i][j];
            }
        }
        return path[m-1][n-1];
    }
};