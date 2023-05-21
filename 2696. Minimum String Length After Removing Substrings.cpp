class Solution {
public:
    int minLength(string s) {
        stack <char> st;
        int n = s.size();
        for(int i = 0 ; i < n ; i++)
        {
            if((st.empty() == false) && ((s[i] == 'B' && st.top() == 'A') || (s[i] == 'D' && st.top() == 'C')))
            {
                st.pop();
            }   
            else
            st.push(s[i]);
        }
        return st.size();
    }
};
