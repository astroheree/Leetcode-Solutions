class Solution {
public:
    int minAddToMakeValid(string str) {
        stack<char> s;
        for(auto i: str)
        {
            if(!s.empty() && s.top() == '(' && i == ')') {s.pop(); continue;}
            s.push(i);
        }
        return s.size();
    }
};
