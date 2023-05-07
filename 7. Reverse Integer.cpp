class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        bool check = true;
        if(x<0) check = false;
        x = abs(x);

        while(x>0)
        {
            int dig = x % 10;
            ans = ans* 10 + dig;
            x = x/10;
            if(ans > pow(2,31) || ans < pow(-2,31)-1) return 0;
        }
        if(!check) return -1*ans;
        return ans;
    }
};
