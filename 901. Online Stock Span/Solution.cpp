
// Time: O(1) amortized
// Space: O(n)
class StockSpanner {

private:
    stack<pair<int, int>> m_stack;

public:
    StockSpanner() {}

    int next(int price) {
        int count = 1;

        while (!m_stack.empty() && m_stack.top().first <= price) {
            count += m_stack.top().second;
            m_stack.pop();
        }
        m_stack.emplace(price, count);
        return count;
    }
};
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
