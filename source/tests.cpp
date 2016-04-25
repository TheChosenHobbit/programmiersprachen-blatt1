#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>


const double pi = 2*acos(0.0);

int gcd (int a, int b)
{
	//Euklidischer Algorithmus rekursiv
	if(b == 0)
	{
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int checksum (int a)
{
	int summe = 0;

	while ( 0 != a)
	{
		//addiere letzte Zahl dazu
		summe = summe + (a % 10);
		//entferne die letzte Zahl
		a = a /10;
	}

	return summe;
}

int sumMultiples ()
{
	int summe = 0;

	for (int i = 1; i <= 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			summe = summe + i;
		}
	}
	return summe;
}

double fract (double a)
{
	int abziehen = a;
	return a-abziehen;
}

double calculateVol(int radius, int hoehe)
{
	double Volumen = 0;
	//Volumen = Grundfläche * Höhe
	//Grundfläche ist gleich pi*r²
	Volumen = pi*radius*radius*hoehe;
	return Volumen;
}

double calculateSurface(int radius, int hoehe)
{
	double Surface = 0;
	//Oberfläche = 2 * Grundfläche + Mantelfläche
	//Grundfläche ist gleich pi*r²
	//Mantelfläche hat den Flächeninhalt 2*pi*r*h
	Surface = 2* pi*radius*radius + 2*pi*radius*hoehe;
	return Surface;
}

double mileToKilometer(double a)
{
	double converted = 0;
	converted = a / 0.621371;
	return converted;
}

TEST_CASE("describe_gcd", "[gcd]")
{
	REQUIRE(gcd(2,4) == 2);
	REQUIRE(gcd(6,9) == 3);
	REQUIRE(gcd(3,7) == 1);
}

TEST_CASE("describe_checksum", "[checksum]")
{
	REQUIRE(checksum(116680) == 22);
	REQUIRE(checksum(42) == 6);
}

TEST_CASE("describe_sumMultiples", "[sumMultiples]")
{
	REQUIRE(sumMultiples() == 234168);
}

TEST_CASE("describe_fract", "[fract]")
{
	REQUIRE(fract(5.23) == Approx(0.23));
	REQUIRE(fract(15.42) == Approx(0.42));
}

TEST_CASE("describe_calculateVol","[calculateVol]")
{
	REQUIRE(calculateVol(3,2) == Approx(18*pi));
	REQUIRE(calculateVol(4,2) == 32*pi);
}

TEST_CASE("describe_calculateSurface","[calculateSurface]")
{
	REQUIRE(calculateSurface(4,2) == 48*pi);
}

TEST_CASE("describe_mileToKilometer","[mileToKilometer]")
{
	REQUIRE(mileToKilometer(42) == Approx(67.5924));
	REQUIRE(mileToKilometer(24) == Approx(38.6243));
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}