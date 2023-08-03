class StockSpanner {
public:
    stack<pair<int, int>> st;
    int index;
    StockSpanner() {
        st.push(make_pair(-1, INT_MAX)); //插入pair的时候用emplace或者make_pair
        index = -1;
    }
    
    int next(int price) {
        index++;
        while(price >= st.top().second){
            st.pop();
        }
        int ans = index - st.top().first;
        st.push(make_pair(index, price));
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */