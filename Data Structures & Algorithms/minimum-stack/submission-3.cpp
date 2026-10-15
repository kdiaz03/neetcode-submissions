class MinStack {
public:

    long min;
    stack<long> minStack;

    MinStack() { }
    
    void push(int val) {
        if( minStack.empty() ) {
            minStack.push(0);
            min = val;
        } else {
            minStack.push( val - min );
            if( val < min ) {
                min = val;
            }
        }
    }
    
    void pop() {
        if( minStack.empty() ) {
            return;
        }

        long top = minStack.top();
        minStack.pop();

        if( top < 0 ) {
            min = min - top;
        }
    }
    
    int top() {
        long top = minStack.top();
        if( top > 0 ) {
            return (top + (int)min);
        } else {
            return (int)min;
        }
    }
    
    int getMin() {
        return (int)min;
    }
};
