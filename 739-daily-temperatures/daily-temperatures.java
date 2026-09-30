class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        Stack<Integer>st = new Stack<>();
        int ans[] = new int[n];
        st.push(0);
        for(int i =0; i<n;i++){
            while(!st.isEmpty() && temperatures[i] >temperatures[st.peek()]){
            int diff = i - st.peek();
            ans[st.peek()] = diff;
            st.pop();
        }
        st.push(i);
        }  
        return ans; 
    }    

}