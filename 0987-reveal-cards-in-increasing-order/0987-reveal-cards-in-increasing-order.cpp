class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());

        vector<int> ans(n);
        deque<int> dq;

        for (int i = 0; i < n; i++) dq.push_back(i);

        int idx = 0;
        while (!dq.empty()) {
            ans[dq.front()] = deck[idx++];
            dq.pop_front();

            if (!dq.empty()) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        return ans;
    }
};
