/*
    Mô tả: Cho một biểu thức toán học chứa các dấu ngoặc tròn (), dấu ngoặc vuông [],
    dấu ngoặc nhọn {}, và các phép toán cộng, trừ, nhân, chia. Bạn cần kiểm tra xem biểu thức 
    đó có hợp lệ không (dấu ngoặc phải đóng mở đúng cách).

    Ví dụ:
    Input: "{(2 + 3) * [4 / (1 + 1)]}", Output: true
    Input: "{2 + (3 * [4 - 5]}", Output: false
*/

bool validate_brackets_expression(const std::string& str)
{
	std::stack<char> stack;
	std::unordered_map<char, char> brackets = {
		{ ')', '(' },{ ']', '[' },{ '}', '{' }
	};

	for (const auto c : str)
	{
		if ((c == '{' || c == '[' || c == '(')) {
			stack.push(c);
		}
		else if (brackets.count(c)){
			if (stack.empty() || stack.top() != brackets[c])
				return false;

			stack.pop();
		}
	}

	return stack.empty();
}
