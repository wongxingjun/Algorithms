class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0)
            return 0;
        else if(n==1)
            return heights[0];
        stack<int> st;
        int area,maxArea=heights[0];
        st.push(0);
        heights.insert(heights.end(),-1);
        int i=1;
        while(i<n+1)
        {
            if(st.empty()||heights[i]>=heights[st.top()])
            {
                st.push(i);
                i++;
            }
            else
            {
                int right=st.top();
                st.pop();
                if(st.empty())
                    area=heights[right]*i;
                else
                    area=heights[right]*(i-st.top()-1);
                maxArea=maxArea>area?maxArea:area;
            }
        }
        return maxArea;
    }
};