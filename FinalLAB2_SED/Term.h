class Term {
private:
	string initialTerm;
	string differentiatedTerm;

	bool validateTerm() {
		switch (findNumOfChar('x'))
		{
		case 0:
			if (Util::isNumber(initialTerm))
			{
				return true;
			}
			else
			{
				return false;
			}
		case 1:

		default:
			return false;
			break;
		}
	}

	int findNumOfChar(char character) {
		int numOfChar = 0;
		for (int i = 0; i < initialTerm.length; i++)
		{
			if (initialTerm[i] == character)
			{
				numOfChar++;
			}
		}
	}

	//Validate x, a*x, b*x
	bool validateUnitExpression(string input) {
		if (input.length == 1)
		{
			return true;
		}
		else if (input.find_first_of('x') == input.length - 1 && input.length >= 3)
		{
			if (input[input.length - 2] == '*')
			{
				string b = input.substr(0, input.length - 3);
				if (Util::isNumber(b))
				{
					return true;
				}
			}
		}
		return false;
	}

	bool isLog(string* minusA) {
		if ((*minusA).find("log10") == 0) 
		{
			(*minusA) = (*minusA).substr(6, (*minusA).length - 1);
			return true;
		}
		else if ((*minusA).find("loge") == 0)
		{
			(*minusA) = (*minusA).substr(5, (*minusA).length - 1);
			return true;
		}
		return false;
 	}

	bool isSin(string* minusA) {
		if ((*minusA).find("sin") == 0 || (*minusA).find("cos") == 0)
		{
			(*minusA) = (*minusA).substr(4, (*minusA).length - 1);
			return true;
		}
		return false;
	}

	bool isExpo(string* minusA) {
		if ((*minusA).find("e^") == 0)
		{
			(*minusA) = (*minusA).substr(3, (*minusA).length - 1);
			return true;
		}
		return false;
	}

	//Validate a*x^(b)
	bool validatePowerFunction() {
		if (initialTerm.find_first_of('x') < initialTerm.length - 5)
		{
			if (Util::isParentheses(initialTerm)) {
				int unitIndex[2];
				Util::getParentheses(initialTerm,unitIndex);
				string b = initialTerm.substr(unitIndex[0], unitIndex[1]);
				if (Util::isNumber(b))
				{
					//Tinh power cua initialTerm
					return true;
				}
			}
		}
		return false;
	}

	//Validate a*log10(b*x)/a*cos(b*x)/a*sin(b*x)/a*log10(b*x)/a*loge(b*x)/a*e^(b*x)
	bool validateSpecialFunction() {
		if (initialTerm.find_first_of('*') && (initialTerm.find_first_of('*') != initialTerm.length - 1))
		{
			string holder = initialTerm.substr(0, initialTerm.find_first_of('*'));
			if (Util::isNumber(holder))
			{
				holder = initialTerm.substr(initialTerm.find_first_of('*')+1);
				if (isLog(&holder)) {
					if (validateUnitExpression(holder)) {
						// Tinh log cua initialTerm
						return true;
					}
				}
				else if (isExpo(&holder)) {
					if (validateUnitExpression(holder)) {
						// Tinh exponential cua initialTerm
						return true;
					}
				} 
				else if (isSin(&holder))
				{
					if (validateUnitExpression(holder)) {
						// Tinh sin cua initialTerm
						return true;
					}
				}
			}
		}
		else
		{
			string holder = initialTerm;
			if (isLog(&holder)) {
				if (validateUnitExpression(holder)) {
					// Tinh log cua initialTerm
					return true;
				}
			}
			else if (isExpo(&holder)) {
				if (validateUnitExpression(holder)) {
					// Tinh exponential cua initialTerm
					return true;
				}
			}
			else if (isSin(&holder))
			{
				if (validateUnitExpression(holder)) {
					// Tinh sin cua initialTerm
					return true;
				}
			}
		}
		return false;
	}

	bool validateLinearFunction() {
		return validateUnitExpression(initialTerm);
	}

public:
	Term(string term) {
		initialTerm = term;
		validateTerm();
	};

	~Term() {};

	string getDifferentiatedTerm() {
		return differentiatedTerm;
	}
};