class Solution {
public:
    int largestRectangleInHistogram(vector<int>& h) {
        stack<int> st;
        int maxArea = 0, n = h.size();
        for(int i = 0; i <= n; i++) {
            int cur = i == n ? 0 : h[i];
            while(!st.empty() && h[st.top()] > cur) {
                int height = h[st.top()]; st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++)
                heights[j] = matrix[i][j] == '1' ? heights[j]+1 : 0;
            maxArea = max(maxArea, largestRectangleInHistogram(heights));
        }
        return maxArea;
    }
};