class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size());

        set<int> set;
        map<int, int> mp;
        for(int i = 0; i < A.size(); i++) {
            mp[A[i]]++;
            if(mp[A[i]] == 1) set.insert(A[i]);
            if(mp[A[i]] == 0) set.erase(A[i]);
            mp[B[i]]--;
            if(mp[B[i]] == 0) set.erase(B[i]);
            if(mp[B[i]] == -1) set.insert(B[i]);

            ans[i] = (i + 1) - set.size() / 2;
        }

        return ans;
    }
};