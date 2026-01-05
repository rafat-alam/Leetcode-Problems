class Solution {
public:
    int minPartitions(string n) {
        int ma = 0;
        for(auto &ch : n) {
            ma = max(ma, ch - '0');
        }
        return ma;
    }
};