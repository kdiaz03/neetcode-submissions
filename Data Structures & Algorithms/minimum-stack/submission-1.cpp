class MinStack {
public:
    std::vector<int> mainStack;
    std::vector<int> minStack; 
    
    MinStack() {

    }
    
    void push(int val) {
        mainStack.push_back(val);

        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        } else {
            minStack.push_back(minStack.back());
        }
    }
    
    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop_back();
            minStack.pop_back();
        }
    }
    
    int top() {
        return mainStack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};