vector<int> Solution::solve(vector<vector<int> > &A) {

    int k = A.size();
    vector<int> ans;

    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > pq;

    for(int i = 0; i < k; i++) {
        if(A[i].size() > 0) {
            pq.push({A[i][0], i, 0});
        }
    }

    while(!pq.empty()) {

        vector<int> v = pq.top();
        pq.pop();

        int val = v[0];
        int r = v[1];
        int c = v[2];

        ans.push_back(val);

        if(c + 1 < A[r].size()) {
            pq.push({A[r][c + 1], r, c + 1});
        }
    }

    return ans;
}
