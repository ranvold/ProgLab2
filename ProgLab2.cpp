//Lab2, var 12. Created by Shafran Volodymyr
#include <iostream>
#include <cmath>
#define eps 10.E-8

using namespace std;

bool entering_x(double& x);
double calc_lib(double x);
double recurr_calc(double x, double& n);
void header();
void values(double x, double f_lib, double f_sum, double difference, double n);

int main() {
	double x, f_lib, f_sum, difference, n;
	while (true) {
		if (!entering_x(x)) { // Checking for incorrect input of values.
			return 0;
		}
		else
		{
			f_lib = calc_lib(x);
			f_sum = recurr_calc(x, n);
			difference = fabs(f_lib - f_sum);
			header();
			values(x, f_lib, f_sum, difference, n);
		}
	}
}

bool entering_x(double& x) {
tryAgain:
	cout << "Enter the values of a real number(x) from the interval (-1, 1):" << endl;
	cin >> x;
	if (cin.eof()) // User entered CTRL-Z(Windows) / CTRL-D(Linux, MacOS)
	{
		cout << "<<<END OF WORK>>>" << endl;
		return false;
	}
	cin.clear();
	if (x <= -1 || x >= 1 || cin.get() != '\n') { //Checking if values ​​are entered correctly
		cin.ignore(255, '\n');
		cout << "Wrong value entered, please try again!" << endl;
		goto tryAgain;
	}
	else return true;
}

double calc_lib(double x) {
	return x = atanh(x); // Analytical formula for hyperbolic arctangent
}

double recurr_calc(double x, double& n) {
	double sum, check = 1, addition; // sum - To calculate the total amount./ check - To start a loop and as an auxiliary variable./ addition - To calculate the amount
	n = 0;
	addition = x;
	sum = addition;
	while (fabs(check) >= eps) {
		n++;
		addition *= x * x; // In this one we save only value of expression 1 * x^(2*n+1)
		check = addition;
		check /= (2 * n + 1); // We may not have only "addition" because of dividing on (2 * n + 1) (otherwise it would be factorial expression)
		sum += check;
	}
	return sum;
}

void header() { // Header output
	cout.width(15); cout << 'x';
	cout.width(15); cout << "f_lib(x)";
	cout.width(15); cout << "f_sum(x)";
	cout.width(15); cout << "difference";
	cout.width(15); cout << "N_adds" << endl;
}
void values(double x, double f_lib, double f_sum, double difference, double n) { // Displaying values ​​under the heading.
	cout.width(15); cout << x;
	cout.width(15); cout << f_lib;
	cout.width(15); cout << f_sum;
	cout.width(15); cout << difference;
	cout.width(15); cout << n << endl;
}