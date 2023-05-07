class Solution {
public:
    string predictPartyVictory(string s) {        
        int i = 0;
        int rBans = 0, dBans = 0;
        while(s.size()!=1)
        {
            i = i % s.size();
            if(dBans == s.size() || rBans == s.size()) break;
            if(s[i] == 'R')
            {
                if(rBans>0)
                {
                    s.erase(i,1);
                    rBans--;
                }
                else
                {
                    dBans++;
                    i++; 
                } 
            }
            else
            {
                if(dBans>0)
                {
                    s.erase(i,1);
                    dBans--;
                }
                else
                {
                    rBans++;
                    i++;
                }   
            }
            
        }
        if(s[0] == 'D') return "Dire";
        if(s[0] == 'R') return "Radiant";
        return "";
    }
};
