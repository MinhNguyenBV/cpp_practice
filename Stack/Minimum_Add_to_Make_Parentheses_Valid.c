/*
    Mô tả: Cho một chuỗi chỉ chứa các dấu ngoặc tròn () không hợp lệ. 
    Nhiệm vụ của bạn là thêm tối thiểu số dấu ngoặc để chuỗi trở thành hợp lệ.

    Ví dụ:
    Input: "())", Output: 1
    Input: "(((", Output: 3
*/

int extra_brackets(const std::string& str)
{
	std::stack<char> stack;
	std::unordered_map<char, char> brackets = {
		{ ')', '(' },{ ']', '[' },{ '}', '{' }
	};

	for (const auto c : str)
	{
		if (!brackets.count(c)) {
			stack.push(c);
		}
		else {
			if (stack.empty() && !brackets.count(c))
				stack.push(c);

			if (stack.top() == brackets[c])
				stack.pop();
		}
	}

	return stack.size();
}
