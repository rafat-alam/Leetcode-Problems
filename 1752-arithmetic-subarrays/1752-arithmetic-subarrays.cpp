class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size());
        for(int i = 0; i < l.size(); i++) {
            int mi = *min_element(nums.begin() + l[i], nums.begin() + r[i] + 1);
            int ma = *max_element(nums.begin() + l[i], nums.begin() + r[i] + 1);

            int len = r[i] - l[i] + 1;

            if(len < 3 || ma == mi) {
                ans[i] = true;
                continue;
            }

            if((ma - mi) % (len - 1) != 0) {
                ans[i] = false;
                continue;
            }

            int cd = (ma - mi) / (len - 1);

            bool is = true;
            vector<int> cor(len, -1);

            for(int j = l[i]; j <= r[i]; j++) {
                if((nums[j] - mi) % cd) {
                    is = false;
                    break;
                }
                int idx = (nums[j] - mi) / cd;
                if(cor[idx] != -1) {
                    is = false;
                    break;
                } else {
                    cor[idx] = nums[j];
                }
            }

            ans[i] = is;
        }
        return ans;
    }
};