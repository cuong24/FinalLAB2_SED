class Util
{
public:
	static bool isNumber(string input) {
		if (input.length() < 1) { return false; }
		else {
			if (!isdigit(input[1]) && input[1] != '(')
			{
				return false;
			}
			for (int i = 1; i < input.length()-1; ++i) {
				if (!isdigit(input[i])) { return false; }
			}
			if (!isdigit(input[input.length-1]) && input[input.length-1] != ')') {
				return false;
			}
		}
		return true;
	}

	static bool isParentheses(string input) {
		int unitIndex[2];
		getParentheses(input, unitIndex);
		if (unitIndex[0] * unitIndex[1] < 0) {
			return false;
		}
		else if (unitIndex[0] == -1 && unitIndex[1] == -1) {
			return false;
		}
		else if (unitIndex[1] - unitIndex[0] < 1) {
			return false;
		}
		return true;
	}

	static void getParentheses(string input, int* unitIndex) {
		unitIndex[0] = -1;
		unitIndex[1] = -1;
		for (int i = 0; i < input.length; ++i) {
			if (input[i] == '(') {
				unitIndex[0] = i;
			}
			else if (input[i] == ')') {
				input[1] = i;
				break;
			}
		}
	}

private:

};

