#include <iostream>

using namespace std;


int main()
{
    int a;
    int curr_value = 0;
    int curr_length = 0;
    int max_value = 0;
    int max_length = 0;

    cout << "Podaj liczby: "<< endl;

    while (true)
    {
        cin >> a;
        if (a == 0)
            break;


        if (a == curr_value)
        {
            curr_length++;
        } else
        {
            curr_value = a;
            curr_length = 1;
        }

        if (curr_length > max_length)
        {
            max_length = curr_length;
            max_value = curr_value;
        }
    }

    cout <<  "Longest sequence: " << max_length << " times " << max_value << endl;
}

