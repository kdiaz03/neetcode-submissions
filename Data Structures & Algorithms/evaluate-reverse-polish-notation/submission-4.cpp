class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> operands;

        for( string s : tokens ) {
            int op1;
            int op2;

            if( (s.size() == 1) && !(std::isdigit(s[0])) ) {
                op2 = operands.top();
                operands.pop();
                op1 = operands.top();
                operands.pop();

                switch(s[0]) {
                    case '+':
                        operands.push( op1 + op2 );
                        break;

                    case '-':
                        operands.push( op1 - op2 );
                        break;

                    case '*':
                        operands.push( op1 * op2 );
                        break;

                    case '/':
                        operands.push( op1 / op2 );
                        break;
                }
            } else {
                int operand = std::stoi(s);
                operands.push(operand);
            }
        }

        return operands.top();
    }
};
