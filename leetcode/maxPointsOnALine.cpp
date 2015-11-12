/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n=points.size();
        if(n<=2)
            return n;
        int maxnum=0;
        double k;
        unordered_map<double,int> kmap;
        int i,j;
        unordered_map<double,int>::iterator it;
        for(i=0;i<n;i++)
        {
            kmap[INT_MAX]=0;
            for(j=0;j<n;j++)
            {
                it=kmap.begin();
                if(j==i)
                    continue;
                if(points[j].x==points[i].x)
                {
                    if(points[j].y==points[i].y)
                    {
                        while(it!=kmap.end())
                        {
                            it->second++;
                            it++;
                        }
                    }
                    else kmap[INT_MAX]++;
                }
                else
                {
                    k=(double)(points[j].y-points[i].y)/(points[j].x-points[i].x);
                    if(kmap.find(k)==kmap.end())
                        kmap[k]=1;
                    else
                        kmap[k]++;
                }
            }
            it=kmap.begin();
            for(;it!=kmap.end();it++)
            {
                if(it->second>maxnum)
                    maxnum=it->second;
            }
            kmap.erase(kmap.begin(),kmap.end());
        }
        return maxnum+1;
    }
};