class Solution {
public:
    int myAtoi(string str) {
        if(str.size()==0)
            return 0;
        int i=0;
        long num=0;
        int sig=1;
        int flag=0;
        for(i=0;i<str.size();)
        {
            if(str[i]==' ')
                i++;
            if(str[i]!=' ')
                break;
        }
        string new_str;
        for(;i<str.size();i++)
            new_str.push_back(str[i]);
        str=new_str;
        i=0;
        if(str[0]=='+')
        {
            sig=1;
            flag=1;
            i++;
        }
        else if(str[0]=='-')
        {
            sig=-1;
            flag=1;
            i++;
        }
        if(i==str.size()-1&&flag==1)
            return (str[i]-48)*sig;
        else if(str[i]<48||str[i]>57)
            return 0;
        for(;i<str.size();i++)
        {
            if(str[i]>=48&&str[i]<=57)
            {
                num+=str[i]-48;
                num*=10;
            }
            else break;
            if(num/10>INT_MAX&&sig==1)
                return INT_MAX;
            else if(num/10+INT_MIN>0&&sig==-1)
                return -INT_MIN;
        }
        num=num/10;
        return num*sig;
    }
};