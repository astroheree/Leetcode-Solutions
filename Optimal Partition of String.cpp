class Solution {
public:
    int partitionString(string s) {
        int n = s.size(), hp = 0, cnt = 1;
        int freq[26] = {0};
        while(hp < n)
        {
            if(freq[s[hp]-'a'] <= 0)
            {
                freq[s[hp]-'a']++;
                hp++;
            }
            else
            {
                cnt++;
                for(int i = 0 ; i < 26 ; i++) freq[i] = 0;
            }
        }   
        return cnt;
    }
};
