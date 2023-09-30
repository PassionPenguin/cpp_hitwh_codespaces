#include <iostream>
#include <string>
using namespace std;

///add(a, b) takes two strings representing numbers and returns a string representing the sum of the two numbers. For example, add("123", "456") returns
string add(string a, string b)
{
    int a_len = a.length(),
        b_len = b.length(),
        max_len = a_len > b_len ? a_len : b_len,
        len_diff = abs(a_len - b_len);
    bool a_is_longer = max_len == a_len;

    cout << a_len << " " << b_len << " " << max_len << " " << len_diff << endl;

    for (int i = 0; i < a_len; i++)
    {
        a[i] = a[i] - '0';
    }
    for (int i = 0; i < b_len; i++)
    {
        b[i] = b[i] - '0';
    }

    /// Store the carry num
    /// 存储进位
    int carry = 0;
    string result = "";

    for (int i = 0; i < max_len; i++)
    {
        /// [a_digit] and [b_digit] represent the digit of [a] and [b] at the same position from the end.
        /// For example, at the first run, if given [a] = 123 and [b] = 456, then [a_digit] = 3 and [b_digit] = 6.
        char a_digit, b_digit;

        if (a_is_longer)
        {
            a_digit = a[a_len - i - 1];
            if (i > b_len)
            {
                b_digit = 0;
            } else
            {
                b_digit = b[b_len - i - 1];
            }
        }
        else
        {
            b_digit = b[b_len - i - 1];
            if (i > a_len)
            {
                a_digit = 0;
            } else
            {
                a_digit = a[a_len - i - 1];
            }
        }

        /// sum up the digits and the carry
        int sum = a_digit + b_digit + carry;
        /// if sum >= 10, then we should add up the carry in the next run
        /// for example, if [a_digit] = 4, [b_digit] = 6, [carry] = 1, then [sum] = 11, and [carry] should be set to 1
        carry = sum / 10;
        /// add the digit to the result
        result = (char)(sum % 10 + '0') + result;
    }

    /// if the last carry is not 0, then we should add it to the result
    if (carry > 0)
    {
        result = (char)(carry + '0') + result;
    }

    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;

    cout << add(a, b) << endl;
}