//Time Limit Exceeded
/*
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int ns=s.size();
        int nw=words.size();
        if(ns<=0||nw<=0)
            return res;
        int i=0;
        int j=0;
        unordered_map<string,int> sentences;
        permute(words, 0, nw-1, sentences);
        int len=sentences.begin()->first.size();
        string subS;
        unordered_map<string,vector<int>> smap;
        for(i=0;i<ns-len+1;i++)
        {
            subS="";
            subS.append(s,i,len);
            smap[subS].push_back(i);
        }
        for(auto it=smap.begin();it!=smap.end();it++)
            if(sentences.find(it->first)!=sentences.end())
                res.insert(res.end(),it->second.begin(),it->second.end());
        return res;
    }
    
    void permute(vector<string> words, int l, int r, unordered_map<string,int>& sentences)
    {
        int i;
        if(l==r)
        {
            string tmp="";
            for(int i=0;i<words.size();i++)
                tmp+=words[i];
            sentences[tmp]=1;
        }
        else
        {
            for(i=l;i<=r;i++)
            {
                swap(words[l],words[i]);
                permute(words,l+1,r,sentences);
                swap(words[l],words[i]);
            }
        }
    }
    
};
*/

//Just AC with much time cost.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string,int> wmp;
        unordered_map<string,int> smp;
        for(string w:words)
            wmp[w]++;
        int wlen=words[0].size();
        int wcnt=words.size();
        string subS;
        for(int i=0;i<s.size()-wlen*wcnt+1;i++){
            for(int j=0;j<wcnt;j++){
                subS="";
                subS.append(s,i+j*wlen,wlen);
                smp[subS]++;
            }
            auto it=smp.begin();
            for(;it!=smp.end();it++)
                if(wmp.find(it->first)==wmp.end()||wmp.find(it->first)->second!=it->second)
                    break;
            if(it==smp.end())
                res.push_back(i);
            smp.clear();
        }
        return res;
    }
};