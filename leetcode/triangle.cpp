class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         vector<int> minSum=triangle[triangle.size()-1];
         for(int i=triangle.size()-2;i>=0;i--)
         {
             for(int j=0;j<triangle[i].size();j++)
                minSum[j]=triangle[i][j]+min(minSum[j],minSum[j+1]);
         }
         return minSum[0];
    }
};