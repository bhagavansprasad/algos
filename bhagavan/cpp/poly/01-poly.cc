#include <iostream>

class Distance
{
	private:
		int k;
		int m;

	public:
		void set_distance(int km, int meter)
		{
			std::cout << __LINE__ << "-->" << __FUNCTION__ << "\n";
			k = km;
			m = meter;

			return;
		}

		void set_distance(int km, int meter, int e1)
		{
			std::cout << __LINE__ << "-->" << __FUNCTION__ << "\n";
			k = km;
			m = meter + e1;

			return;
		}


		Distance get_distance(void)
		{
			std::cout << __LINE__ << "-->" << __FUNCTION__ << "\n";
			Distance t;
			t.k = k;
			t.m = m;

			return t;
		}

		int add_distance(Distance t)
		{
			std::cout << __LINE__ << "-->" << __FUNCTION__ << "\n";
			return k + t.k + m + t.m;
		}

		float operator + (Distance x)
		{
			std::cout << __LINE__ << "-->" << __FUNCTION__ << "\n";
			Distance t;
			return k + x.k + m + x.m;
		}
};

int main()
{
	Distance a, b;
	int t;

	a.set_distance(12, 340);
	a.set_distance(12, 340, 100);
	b.set_distance(5, 750);

	t = a.add_distance(b);
	std::cout << t << "\n";

	t = a + b;
	std::cout << t << "\n";
}

