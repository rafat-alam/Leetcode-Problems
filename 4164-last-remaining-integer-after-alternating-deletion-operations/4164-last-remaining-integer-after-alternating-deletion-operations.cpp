class Solution {
public:
    long long lastInteger(long long n) {
        long long f = 1, l = n;

        long long ch = 0;
        
        long long ans = 0;
        long long i = 1;

        while(f <= l) {
            if(ch == 0) {
                if(f % 2 == 1) {
                    ans += i;
                    if(l % 2 == 0) {
                        l--;
                    }
                } else {
                    if(l % 2 == 1) {
                        l--;
                    }
                }
                i *= 2;
                l /= 2;
                f /= 2;
            } else {
                if(l % 2 == 1) {
                    ans += i;
                    if(f % 2 == 0) {
                        f++;
                    }
                } else {
                    if(f % 2 == 1) {
                        f++;
                    }
                }
                i *= 2;
                f /= 2;
                l /= 2;
            }
            
            if(l == f && l == 0) {
                break;
            }

            ch = 1 - ch;
        }

        return ans;
    }
};