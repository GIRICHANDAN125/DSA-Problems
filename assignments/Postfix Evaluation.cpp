class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        
        stack<int> st;
        
        for(int i = 0; i < arr.size(); i++) {
            string s = arr[i];
            if(s == "+" || s == "-" || s == "*" || s == "/" || s == "^") {
                int b = st.top(); 
                st.pop();
                int a = st.top(); 
                st.pop();
                if(s == "+") st.push(a + b);
                else if(s == "-") st.push(a - b);
                else if(s == "*") st.push(a * b);
                else if(s == "/") {
                    double val = (double)a / b;
                    st.push(floor(val));
                }
                else if(s == "^") {
                    st.push(pow(a, b));
                }
            }
            else {
                st.push(stoi(s));
            }
        }
        
        return st.top();
    }
};
