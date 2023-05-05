class Solution {
public:
    bool isVowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o'  || c == 'u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int maxCount = 0, vowel = 0, loopCounter = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(loopCounter<k)
            {
                if(isVowel(s[i])) vowel++;
                loopCounter++;
            }
            else
            {
                if(isVowel(s[i-k])) vowel--;
                if(isVowel(s[i])) vowel++;
            }
            maxCount = max(vowel,maxCount);
            if(maxCount == k) break;
        }
        return maxCount;
    }
};
