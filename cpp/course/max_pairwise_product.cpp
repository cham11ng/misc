// input 1: - 2 <= n <= 2 . 10^5
// input 2: n non-negative integers

#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::vector;

int MaxPairwiseProduct(const vector<int> &numbers)
{
    int result = 0;
    int n = numbers.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (numbers[i] * numbers[j] > result)
            {
                result = numbers[i] * numbers[j];
            }
        }
    }

    return result;
}

int main()
{
    int n;

    cout << "Enter total number of digits you want to enter: ";
    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int result = MaxPairwiseProduct(numbers);

    cout << "Product of max pair is: " << result << "\n";

    return 0;
}
