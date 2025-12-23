class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> pf(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pf[i + 1] = pf[i] ^ arr[i];
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int k = i + 1; k < n; k++) {
                if(pf[i] == pf[k + 1]) {
                    cnt += k - i;
                }
            }
        }

        return cnt;
    }
};