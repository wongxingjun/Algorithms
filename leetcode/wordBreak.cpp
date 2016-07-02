class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        queue<int> bfs;
        unordered_set<int> visited;
        bfs.push(0);
        while(bfs.size()>0)
        {
            int start = bfs.front();
            bfs.pop();
            if(visited.find(start) == visited.end())
            {
                visited.insert(start);
                for(int j = start;j < s.size();j++)
                {
                    string w(s, start, j-start+1);
                    if(wordDict.find(w) != wordDict.end())
                    {
                        bfs.push(j+1);
                        if(j+1 == s.size())
                            return true;
                    }
                }
            }
        }
        return false;
    }
};