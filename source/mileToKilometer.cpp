#include <cmath>
#include <iostream>

double mileToKilometer(double a)
{
	double converted = 0;
	converted = a / 0.621371;
	return converted;
}

int main()
{
	std::cout << "Geben sie die Meilen ein: " << std::endl;
	double miles;
	std::cin >> miles;

	std::cout << "Die Meilen in Kilometer sind: " << mileToKilometer(miles) << " km" << std::endl;
	return 0;
}
