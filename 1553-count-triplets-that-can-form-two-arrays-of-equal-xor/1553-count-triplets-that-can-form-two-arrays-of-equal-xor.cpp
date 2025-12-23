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
            for(int j = i + 1; j < n; j++) {
                for(int k = j; k < n; k++) {
                    if(pf[j] ^ pf[i] == pf[k + 1] ^ pf[j]) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};