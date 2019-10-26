#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

double read_and_evaluate(istream& is);
void evaluate_stack(stack<double>& numbers, stack<char>& operations);
bool check_right_blacket(stack<char>& operations);

int main() {
	for (int i = 0; i < 5; i++) {
		cout << read_and_evaluate(cin) << endl;
	}
}

void evaluate_stack(stack<double>& numbers, stack<char>& operations) {
	double operand1, operand2;

	operand2 = numbers.top();
	numbers.pop();
	operand1 = numbers.top();
	numbers.pop();

	switch (operations.top())
	{
	case '+':
		numbers.push(operand1 + operand2);
		break;
	case '-':
		numbers.push(operand1 - operand2);
		break;
	case '*':
		numbers.push(operand1 * operand2);
		break;
	case '/':
		numbers.push(operand1 / operand2);
		break;
	default:
		break;
	}
	operations.pop();
}


bool check_right_blacket(stack<char>& operations)
{
	char check;
	
	while (!operations.empty())
	{
		if (strchr("({[", operations.top()) != NULL)
		{
			cout << "";
		}
	}

	return true;
}

double read_and_evaluate(istream& is) {
	const char DECIMAL = '.';
	const char LEFT_PARENTHESIS = '(';
	const char LEFT_CURLY_BRACKET = '{';
	const char LEFT_SQUARE_BRACKET = '[';
	const char RIGHT_PARENTHESIS = ')';
	const char RIGHT_CURLY_BRACKET = '}';
	const char RIGHT_SQUARE_BRACKET = ']';

	stack<double> numbers;
	stack<char> operations;
	double number;
	char symbol;

	while (is&&is.peek() != '\n') {
		if (isdigit(is.peek()) || is.peek() == DECIMAL) {
			is >> number;
			numbers.push(number);
		}
		else if (strchr("+-", is.peek()) != NULL) {
			is >> symbol;
			if (operations.empty() == false && strchr("+-*/", operations.top()) != NULL)
					evaluate_stack(numbers, operations);

			operations.push(symbol);
		}
		else if (strchr("*/", is.peek()) != NULL) {
			is >> symbol;
			if (operations.empty() == false && strchr("*/", operations.top()) != NULL)
					evaluate_stack(numbers, operations);

			operations.push(symbol);
		}
		else if (is.peek() == LEFT_PARENTHESIS) {
			is >> symbol;
			operations.push(symbol);
		}
		else if (is.peek() == LEFT_CURLY_BRACKET) {
			is >> symbol;
			operations.push(symbol);
		}
		else if (is.peek() == LEFT_SQUARE_BRACKET) {
			is >> symbol;
			operations.push(symbol);
		}
		else if (is.peek() == RIGHT_PARENTHESIS) {
			is.ignore();
			while (operations.top()!=LEFT_PARENTHESIS)
			{
				evaluate_stack(numbers, operations);
			}
			operations.pop();
		}
		else if (is.peek() == RIGHT_CURLY_BRACKET) {
			is.ignore();
			while (operations.top() != LEFT_CURLY_BRACKET)
			{
				evaluate_stack(numbers, operations);
			}
			operations.pop();
		}
		else if (is.peek() == RIGHT_SQUARE_BRACKET) {
			is.ignore();
			while (operations.top() != LEFT_SQUARE_BRACKET)
			{
				evaluate_stack(numbers, operations);
			}
			operations.pop();
		}
		else {
			is.ignore();
		}
	}
	while (!operations.empty())
	{
		evaluate_stack(numbers, operations);
	}
	is.ignore(); // '\n' ¹«½Ã
	return numbers.top();
}
