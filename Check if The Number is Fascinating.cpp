class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) + to_string(2*n) + to_string(3*n);
        if(s.size() != 9) return false;
        int freq[10] = {0};
        for(int i = 0 ; i < s.size() ; i++) freq[s[i] - '0']++;
        if(freq[0] != 0) return false;
        for(int i = 1 ; i < 10 ; i++)
            if(freq[i] != 1) return false;
        return true;
    }
};
