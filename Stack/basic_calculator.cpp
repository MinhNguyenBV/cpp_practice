class Solution {
public:
    struct Operator {
        int precedence;
        std::function<int(int, int)> operation;
    };

    void applyTopOperation(std::stack<int>& nums,
                           std::stack<char>& ops,
                           const std::unordered_map<char, Operator>& operators)
    {
        char op = ops.top(); ops.pop();
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        nums.push(operators.at(op).operation(a, b));
    }

    int calculate(string s) {
        std::unordered_map<char, Operator> operators = {
            {'+', {1, [](int a, int b) { return a + b; }}},
            {'-', {1, [](int a, int b) { return a - b; }}},
            {'*', {2, [](int a, int b) { return a * b; }}},
            {'/', {2, [](int a, int b) { return a / b; }}}
        };

        std::stack<int> nums;
        std::stack<char> ops;
        size_t n = s.size();

        for (int i = 0; i < n; ++i)
        {
            char ch = s[i];

            if (isdigit(ch)) {
                auto it = std::find_if(s.begin() + i, s.end(), 
                                       [](char c) { return !isdigit(c); });

                auto num = std::stoi(std::string(s.begin() + i, it));
                nums.push(num);
                i = std::distance(s.begin(), it) - 1;
            }
            else if (ch == ')')
            {
                while (!ops.empty() && ops.top() != '(')
                    applyTopOperation(nums, ops, operators);

                ops.pop();
            }
            else if (operators.count(ch))
            {
                while (!ops.empty() && ops.top() != '(' &&
                   operators[ops.top()].precedence >= operators[ch].precedence) {
                    applyTopOperation(nums, ops, operators);
                }
                ops.push(ch);
            }
            else if (ch == '(') {
                ops.push(ch);
            }
        }

        while (!ops.empty())
            applyTopOperation(nums, ops, operators);

        return nums.top();
    }
};


