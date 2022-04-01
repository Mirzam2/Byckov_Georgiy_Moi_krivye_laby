#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long green = 0;
	long long div = 2;
    int i = 0;
	while (i < 62){
		green += ((n / div) - (n / (2 * div))) * (i + 1);
		div *= 2;
        i++;
	}
	cout << green << endl;

	return 0;
}