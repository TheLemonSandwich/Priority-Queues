// Not sure if it's complete.
#include <iostream>
#include <string>

using namespace std;

int main()
{
	bool invalid = true;
	int size;
	while (invalid)
	{
		
		cout << "Enter the size of queue(size should be at least 3): ";
		cin >> size;
		if (size < 3)
		{
			cout << "Size is too small.\n";
		}
		else
			invalid = false;
	}
	size += 1;
	int* p = new int[size];

	// initializing
	for (int i = 1; i < size; i++)
	{
		cout << "\n>>\t";
		cin >> *(p + i);
	}
	// Making a min heap
	invalid = true;
	while (invalid)
	{

		int count1 = 0, count2 = 0;
		for (int i = size-1; i > 0; i--)
		{
			if (i == 1)
			{
				if (*(p + i) > * (p + i * 2))
					swap(*(p + i), *(p + i * 2));
				else if (*(p + i) > * (p + (i * 2 +1)))
					swap(*(p + i), *(p + (i * 2 +1)));
				count2 = 1;
			}
			if (*(p + i) < *(p + i/2))
			{
				swap(*(p + i), *(p + i/2));
				count1++;
			}
			if (*(p + i) < *(p + (i / 2 )+1))
			{
				swap(*(p + i), *(p + (i / 2) +1));
				count1++;
			}
		}
		if (count1 == 0 || count2 == 0)
		{
			invalid = false;
		}
	}
	for (int i = 1; i < size; i++)
		cout << *(p + i) << " ";

}

