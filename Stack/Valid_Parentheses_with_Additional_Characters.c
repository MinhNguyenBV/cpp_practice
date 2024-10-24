/*
	Mô tả: Kiểm tra tính hợp lệ của chuỗi dấu ngoặc nhưng chuỗi có thể bao gồm cả các ký tự
	không phải là dấu ngoặc, ví dụ như chữ cái hoặc chữ số. Bạn cần bỏ qua các ký tự không phải dấu ngoặc.

	Ví dụ:
	Input: "a(b)c[d]{e}", Output: true
	Input: "a)b(c", Output: false
*/

bool isValid(const std::string& str)
{
	std::stack<char> stack;
	std::unordered_map<char, char> brackets = {
		{ ')', '(' },{ ']', '[' },{ '}', '{' }
	};

	for (const auto c : str)
	{
		if (!isalpha(c) && !brackets.count(c)) {
			stack.push(c);
		}
		else if (brackets.count(c)) {
			if (stack.empty() || stack.top() != brackets[c])
				return false;

			stack.pop();
		}
	}

	return stack.empty();
}
