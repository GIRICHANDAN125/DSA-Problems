class Solution {
  public:
    int sumOfMax(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
        
        // Previous Greater
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            
            if(st.empty()) left[i] = i + 1;
            else left[i] = i - st.top();
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        // Next Greater
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            
            if(st.empty()) right[i] = n - i;
            else right[i] = st.top() - i;
            
            st.push(i);
        }
        
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans += 1LL * arr[i] * left[i] * right[i];
        }
        
        return ans;
    }
};