#include <iostream>
#include <cmath>
struct comp_lex {
	double r;
	double i;

};

void print_complex(comp_lex num) {
	std::cout << num.r << " + " << num.i << 'i' << std::endl;
}

comp_lex multiply_complex(comp_lex multiplied, comp_lex multiplicator) {
	comp_lex result;
	result.r = multiplied.r * multiplicator.r - (multiplied.i * multiplicator.i);
	result.i = multiplied.r * multiplicator.i + multiplicator.r * multiplied.i;
	return result;
}

comp_lex divide_complex(comp_lex divided, comp_lex divisor) {
	comp_lex result;
	result.r = (divided.r*divisor.r + divided.i*divisor.i) / (pow(divisor.i, 2) + (divisor.r, 2));
	result.i = (divided.i*divisor.r - divided.r*divisor.i) / (pow(divisor.i, 2) + pow(divisor.r, 2));

	return result;
}

comp_lex add_complex(comp_lex num1, comp_lex num2) {
	comp_lex result;
	result.r = num1.r + num2.r;
	result.i = num1.i + num2.i;
	return result;
}

comp_lex subtract_complex(comp_lex num1, comp_lex num2) {
	comp_lex result;
	result.r = num1.r - num2.r;
	result.i = num1.i - num2.i;
	return result;
}
int nmain() {
	comp_lex num1, num2;
	num1.r = 2;
	num1.i = 3;

	num2.r = 5;
	num2.i = -1;
	std::cout << "Number 1: ";
	print_complex(num1);
	std::cout << "Nummber 2:";
	print_complex(num2);
	std::cout << "Multiplication result: ";
	print_complex(multiply_complex(num1, num2));
	std::cout << "Division result : ";
	print_complex(divide_complex(num1, num2));
	std::cout << "Subtraction result: ";
	print_complex(subtract_complex(num1, num2));
	std::cout << "Addition result: ";
	print_complex(add_complex(num1, num2));

	return 0;
}



