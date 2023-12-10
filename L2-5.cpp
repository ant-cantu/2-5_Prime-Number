#include <iostream>

using namespace std;

bool isPrime(int num);
bool isTwinPrime(int numOne, int numTwo);

int main()
{
	int numOne,				//User input for first number
		numTwo,				//User input for second number
		twinPrimeTotal = 0, //Total number of twin primes found
		primeSum = 0;		//Total sum of all prime numbers

	int x = 0,				//Variable used to store lower number from user input
		y = 0;				//Variable used to store higher number from user input

	char q;

	cout << "Anthony Cantu\t" << "L2-5\t" << "L2-5.exe" << endl;
	cout << endl; //Line Break

	cout << "Enter two positive integers <1,000,000,000: ";

	cin >> numOne >> numTwo;
	cout << endl; //Line Break;
	if (cin)
	{
		if ((numOne > 0 && numOne <= 1000000000) &&
			(numTwo > 0 && numTwo <= 1000000000))
		{
			//Determine which number is higher.
			if (numOne < numTwo)
			{
				x = numOne;
				y = numTwo;
			}
			else if (numOne > numTwo)
			{
				x = numTwo;
				y = numOne;
			}
		}
		else
		{
			//Throw error if numbers entered are not between 1 and 1 billion
			cout << "ERROR: Please enter a numeric value between 1 and 1,000,000,000" << endl;
			cout << "Press any key to Exit.";
			cin.ignore(2, '\n');
			cin.get(q);
			return 1;
		}

		for (int i = x; i <= y; i++)
		{
			if (isPrime(i))
			{
				primeSum += i;
				if (isPrime(i + 2))
				{
					if (isTwinPrime(i, i + 2))
					{
						cout << i << " and " << i + 2
							<< " are twin primes." << endl;
						++twinPrimeTotal;
					}
				}
				
			}
		}
	}
	else
	{
		cout << "ERROR: Invalid entry, please enter only numeric values." << endl;
		cin.ignore(2, '\n');
		cin.get(q);
		return 1;
	}

	cout << "The sum of prime numbers between " << numOne
		<< " and " << numTwo << " = " << primeSum << endl;
	cout << "The number of twin primes between " << numOne
		<< " and " << numTwo << " = " << twinPrimeTotal << endl;

	cout << "Press any key to Exit.";

	cin.ignore(2, '\n');
	cin.get(q);

	return 0;
}

bool isPrime(int num)
{
	if (num <= 1)
		return false;

	for (int i = 2; i * i <= num; i++)
		if (num % i == 0)
			return false;

	return true;
}

bool isTwinPrime(int numOne, int numTwo)
{
	if (isPrime(numOne) && isPrime(numTwo))
	{
		if (abs(numOne - numTwo) == 2)
		{
			return true;
		}
		else
			return false;
	}
	return false;
}