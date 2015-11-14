class Solution {
public:
    string addBinary(string a, string b) {
        int lenA=a.size();
        int lenB=b.size();
        string res="0";
        if(lenA==0)
        {
            if(lenB==0) return res;
            else return b;
        }
        if(lenB==0) return a;
        string longS=lenA>=lenB?a:b;
        string shortS=lenA<lenB?a:b;
        int i=longS.size()-shortS.size();
        for(;i>0;i--)
            shortS.insert(0,"0");
        i=longS.size()-1;
        int cnt=0;
        int tmp;
        for(;i>=0;i--)
            longS[i]=add(longS[i],shortS[i],cnt);
        if(cnt!=0)
            longS.insert(0,"1");
        return longS;
    }
    
    char add(char a,char b,int& cnt)
    {
        int ia=a-'0';
        int ib=b-'0';
        int sum=ia+ib+cnt;
        switch(sum){
            case 0: {cnt=0;break;}
            case 1: {cnt=0;break;}
            case 2: {cnt=1;break;}
            case 3: {cnt=1;break;}
        }
        return sum%2+'0';
    }
};