class Solution {
public:
    int minAllOneMultiple(int num) {
        if(num % 2 == 0 || num % 5 == 0) return -1;
        
        long long ans = 0;
        for(int i = 1; i <= num; i++) {
            ans = (ans * 10 + 1) % num;
            if(ans == 0) return i;
        }

        return -1;
    }
};