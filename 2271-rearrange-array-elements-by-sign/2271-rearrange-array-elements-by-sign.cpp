class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos, neg;
        for(auto &num : nums) {
            if(num < 0) neg.push(num);
            if(num > 0) pos.push(num);
        }

        int i = 0;
        while(pos.size()) {
            nums[i] = pos.front();
            pos.pop();
            i++;
            nums[i] = neg.front();
            neg.pop();
            i++;
        }

        return nums;
    }
};