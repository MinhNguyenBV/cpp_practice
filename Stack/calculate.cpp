enum class EXP
    {
        ADD,
        SUB,
        MUL,
        DIV,
        NO_EXP,
    };

    int calculate(const string& str) {
        std::stack<int> numbers;
        int result = 0;
        EXP prev_exp = EXP::ADD;

        auto begin = str.begin();

        while (begin != str.end()) {
            auto end = std::find_if(begin, str.end(), [](char c) {
                return c == '+' || c == '-' || c == '*' || c == '/';
            });

            int curr_num = std::stoi(std::string(begin, end));

            if (prev_exp == EXP::SUB) curr_num = -curr_num;
            else if (prev_exp == EXP::MUL) {
                curr_num *= numbers.top();
                numbers.pop();
            }
            else if (prev_exp == EXP::DIV) {
                curr_num = numbers.top() / curr_num;
                numbers.pop();
            }

            numbers.push(curr_num);

            if (end != str.end()) {
                switch (*end) {
                    case '+': prev_exp = EXP::ADD; break;
                    case '-': prev_exp = EXP::SUB; break;
                    case '*': prev_exp = EXP::MUL; break;
                    case '/': prev_exp = EXP::DIV; break;
                }
                begin = end + 1;
            }
            else break;
        }

        while (!numbers.empty()) {
            result += numbers.top();
            numbers.pop();
        }

        return result;
    }
