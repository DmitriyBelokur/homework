#include <cmath>
#include <iostream>

// Global Constants
constexpr int kMinValueRange(1);
constexpr int kMaxValueRange(255);

constexpr int kZero(0);
constexpr int kTwo(2);
constexpr int kFour(4);

// User Communication 
bool TheQuestionIsToContinueTheProgram() {

	std::cout << "Do you want to continue running the program?\n"
		<< "Yes, enter - 1 \n"
		<< "No - 2\n";
	
	short Answer;
	std::cin >> Answer;

	switch (Answer) {
	case 1:
		return true;
	case 2:
		return false;
	default:
		std::cout << "Wrong choice!";
		TheQuestionIsToContinueTheProgram();
	}
}

bool QuestionEnteringNewProgramParameters() {

	std::cout << "You want to enter new values ​​for variables?\n"
		<< "Yes, enter - 1 \n"
		<< "No - 2\n";
	
	short Answer;
	std::cin >> Answer;

	switch (Answer) {
	case 1:
		return true;
	case 2:
		return false;
	default:
		std::cout << "Wrong choice!";
		QuestionEnteringNewProgramParameters();
	}
}

// Range Check Functions
bool CheckingTheNumberIsZero(long Value) {

	if (Value == kZero) {
		return true;
	}

	return false;
}

bool CheckingTheNumberLessThanZero(long Value) {

	if (Value < kZero) {
		return true;
	}

	return false;
}

bool CheckingTheNumberIsInThePositiveRage(long Value) {

	if ((Value < kMinValueRange) || (Value > kMaxValueRange)){
		return true;
	}

	return false;
}

bool CheckingTheNumberIsInTheNegativeRage(long Value) {

	if ((Value < -kMaxValueRange) || (Value > -kMinValueRange)){
		return true;
	}

	return false;
}

// Main Functions
int main() {
		
	// User enter number 'a' which should not be zero
	long a;
	std::cout << "Enter a (integer that does not equal to "
		<< kZero << ")\n";
	std::cin >> a;

	for (; CheckingTheNumberIsZero(a);) {

		std::cout << "You entered " << kZero << "!\n";

		if (TheQuestionIsToContinueTheProgram()) {
			std::cout << "Enter any nonzero integer:\n";
			std::cin >> a;
		}
		else {
			std::cout << "Program Completed.\n";
			return 0;
		}
	}

	// The user enters the number "b" which is in the positive range
	long b;
	std::cout << "Enter b (in range from " << kMinValueRange << " to " << kMaxValueRange << "):\n";
	std::cin >> b;

	for (; CheckingTheNumberIsInThePositiveRage(b);) {

		std::cout << "You entered a number outside the given range!\n";

		if (TheQuestionIsToContinueTheProgram()) {
			std::cout << "Enter any nonzero integer:\n";
			std::cin >> b;
		}
		else {
			std::cout << "Program Completed.\n";
			return 0;
		}
	}

	// The user enters the number "c" which is in the negativ range
	long c;
	std::cout << "Enter c (in range from " << -kMaxValueRange << " to " << -kMinValueRange << "):\n";
	std::cin >> c;

	for (; CheckingTheNumberIsInTheNegativeRage(c);) {

		std::cout << "You entered a number outside the given range!\n";

		if (TheQuestionIsToContinueTheProgram()) {
			std::cout << "Enter any nonzero integer:\n";
			std::cin >> c;
		}
		else {
			std::cout << "Program Completed.\n";
			return 0;
		}
	}

	// We calculate the values ​​of x1 and x2
	long d = b * b - (kFour * a * c);
	long doubleA = kTwo * a;

	if (CheckingTheNumberLessThanZero(d)) {
		
		std::cout << "The discriminant is negative. No real square roots can be taken!\n";
		
	}
	else if (CheckingTheNumberIsZero(d)) {
		
		std::cout << "The square root is " << -(static_cast<double>(b) / doubleA) << "\n";
		
	}
	else {
		
		std::cout << "The square roots are: \n";
		
		double x1 = (-(static_cast<double>(b)) + sqrt(d)) / doubleA;
		double x2 = (-(static_cast<double>(b)) - sqrt(d)) / doubleA;
		
		std::cout << "x1 = " << x1 << "\n";
		std::cout << "x2 = " << x2 << "\n";
	}

	if (QuestionEnteringNewProgramParameters()) {
		
		std::cout << "\n//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//* \n\n";
		main();
	}
	return 0;
}