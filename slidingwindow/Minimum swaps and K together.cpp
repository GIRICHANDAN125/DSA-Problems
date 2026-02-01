class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        int n = arr.size();
        int g = 0;
        for(int i = 0; i < n; i++)
            if(arr[i] <= k)
                g++;
        int b = 0;
        for(int i = 0; i < g; i++)
            if(arr[i] > k)
                b++;
        int ans = b;
        for(int i = 0, j = g; j < n; i++, j++) {
            if(arr[i] > k) b--;
            if(arr[j] > k) b++;
            ans = min(ans, b);
        }
        return ans;
    }
};
