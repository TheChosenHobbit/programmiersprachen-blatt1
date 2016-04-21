#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

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

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}