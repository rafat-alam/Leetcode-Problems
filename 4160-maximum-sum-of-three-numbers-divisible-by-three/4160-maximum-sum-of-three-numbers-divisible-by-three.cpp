class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> zer, one, two;

        for(auto &aa : nums) {
            if(aa % 3 == 0) zer.push_back(aa);
            if(aa % 3 == 1) one.push_back(aa);
            if(aa % 3 == 2) two.push_back(aa);
        }

        sort(zer.rbegin(), zer.rend());
        sort(one.rbegin(), one.rend());
        sort(two.rbegin(), two.rend());

        int ma = 0;
        if(zer.size() >= 3) {
            ma = max(ma, zer[0] + zer[1] + zer[2]);
        }
        if(one.size() >= 3) {
            ma = max(ma, one[0] + one[1] + one[2]);
        }
        if(two.size() >= 3) {
            ma = max(ma, two[0] + two[1] + two[2]);
        }
        if(zer.size() >= 1 && one.size() >= 1 && two.size() >= 1) {
            ma = max(ma, zer[0] + one[0] + two[0]);
        }

        return ma;
    }
};