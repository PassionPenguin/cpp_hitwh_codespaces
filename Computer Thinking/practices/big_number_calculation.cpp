#include <iostream>
#include <string>
#include <chrono>
#define BENCHMARK_COUNT 10000

using namespace std;

/// cleanup(s) takes a string representing a number and returns a string representing the same number without leading zeros.
string cleanup(string s)
{
    int i = 0;
    while (s[i] == '0' && i < s.length() - 1)
    {
        i++;
    }
    return s.substr(i);
}

/// add(a, b) takes two strings representing numbers and returns a string representing the sum of the two numbers.
string add(string a, string b)
{
    /// Remove the leading zeros
    a = cleanup(a);
    b = cleanup(b);

    if (a == "0")
        return b;
    if (b == "0")
        return a;

    int a_len = a.length(),
        b_len = b.length(),
        max_len = a_len > b_len ? a_len : b_len,
        len_diff = abs(a_len - b_len);
    bool a_is_longer = max_len == a_len;

    for (int i = 0; i < a_len; i++)
    {
        a[i] = a[i] - '0';
    }
    for (int i = 0; i < b_len; i++)
    {
        b[i] = b[i] - '0';
    }

    /// Store the carry num
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
            }
            else
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
            }
            else
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

/// multiply(a, b) takes two strings representing numbers and returns a string representing the product of the two numbers.
string multiply(string a, string b)
{
    /// Remove the leading zeros
    a = cleanup(a);
    b = cleanup(b);

    if (a == "0" || b == "0")
        return "0";

    int a_len = a.length(),
        b_len = b.length(),
        max_len = a_len > b_len ? a_len : b_len,
        min_len = a_len < b_len ? a_len : b_len,
        len_diff = abs(a_len - b_len);
    bool a_is_longer = max_len == a_len;

    for (int i = 0; i < a_len; i++)
    {
        a[i] = a[i] - '0';
    }
    for (int i = 0; i < b_len; i++)
    {
        b[i] = b[i] - '0';
    }

    /// Store the carry num
    int carry = 0;
    string result = "";

    for (int i = 0; i < min_len; i++)
    {
        /// get the current digit of the smaller number
        char smaller_num_digit, larger_num_digit;
        if (a_is_longer)
        {
            smaller_num_digit = b[b_len - i - 1];
        }
        else
        {
            smaller_num_digit = a[a_len - i - 1];
        }

        string tmp_result = "";
        for (int j = 0; j < max_len; j++)
        {
            /// get the current digit of the larger number
            if (a_is_longer)
            {
                larger_num_digit = a[a_len - j - 1];
            }
            else
            {
                larger_num_digit = b[b_len - j - 1];
            }

            int sum = smaller_num_digit * larger_num_digit + carry;
            carry = sum / 10;
            tmp_result = (char)(sum % 10 + '0') + tmp_result;
        }

        if (carry > 0)
        {
            tmp_result = (char)(carry + '0') + tmp_result;
        }

        string zeros = "";
        for (int j = 0; j < i; j++)
        {
            zeros += "0";
        }

        result = add(result, tmp_result + zeros);
    }

    return result;
}

int main()
{
    long long ms1 = 0, ms2 = 0;
    for (int i = 0; i < BENCHMARK_COUNT; i++)
    {
        string a, b;

        /// Generate two unsigned int numbers in int range
        a = to_string(rand());
        b = to_string(rand());

        auto start1 = chrono::high_resolution_clock::now();
        add(a, b);
        auto stop1 = chrono::high_resolution_clock::now();
        ms1 += chrono::duration_cast<chrono::microseconds>(stop1 - start1).count();
        auto start2 = chrono::high_resolution_clock::now();
        multiply(a, b);
        auto stop2 = chrono::high_resolution_clock::now();
        ms2 += chrono::duration_cast<chrono::microseconds>(stop2 - start2).count();
    }

    ms1 /= BENCHMARK_COUNT;
    ms2 /= BENCHMARK_COUNT;
    cout << "Add complete in " << (ms1) << "ms" << endl;
    cout << "Multiply complete in " << (ms2) << "ms" << endl;
}