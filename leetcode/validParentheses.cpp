class Solution {
public:
    bool isValid(string s) {
        if(s==" ")
            return false;
        int i=0;
        stack<char> st;
        while(s[i])
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                st.push(s[i]);
            else
            {
                if(st.empty())
                    return false;
                if(compare(s[i],st.top()))
                    st.pop();
                else
                    return false;
            }
            i++;
        }
        if(st.empty())
            return true;
        return false;
    }
    
    bool compare(char si, char t)
    {
        if((t=='('&&si==')')||(t=='['&&si==']')||(t=='{'&&si=='}'))
            return true;
        return false;
    }
};