int calculate(const std::string& str) {
    std::stack<int> numbers;
    int result = 0;
    EXP prev_exp = EXP::NO_EXP;

    auto begin = str.begin();

    while (begin != str.end()) {
        auto end = std::find_if(begin, str.end(), [](char c) {
            return c == '+' || c == '-' || c == '*' || c == '/';
            });

        int curr_num = std::stoi(std::string(begin, end));
        curr_num *= (prev_exp != EXP::SUB) ? 1 : -1;

        if (prev_exp == EXP::MUL || prev_exp == EXP::DIV)
        {
            int prev_num = numbers.top();
            numbers.pop();

            if (prev_exp == EXP::MUL)
                curr_num *= prev_num;
            else
                curr_num = prev_num / curr_num;
        }

        numbers.push(curr_num);

        if (end != str.end())
        {
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

    while (!numbers.empty())
    {
        result += numbers.top();
        numbers.pop();
    }

    return result;
}
