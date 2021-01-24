
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

double hexToDecimal(string hex, int len)
{

    size_t point = hex.find('.');

    if (point == string::npos)
        point = len;

    float intDecimal = 0, fracDecimal = 0;

    int c = 0;
    for (int i = point - 1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {

            intDecimal += (hex[i] - 48) * pow(16, c);
            c++;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {

            intDecimal += (hex[i] - 55) * pow(16, c);
            c++;
        }
    }

    int f = 1;
    for (int i = point + 1; i < len; i++)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {

            intDecimal += (hex[i] - 48) * pow(16, -f);
            f++;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {

            intDecimal += (hex[i] - 55) * pow(16, -f);
            f++;
        }
    }

    return intDecimal + fracDecimal;
}

double octalToDecimal(string octal, int len)
{

    size_t point = octal.find('.');

    if (point == string::npos)
        point = len;

    float intDecimal = 0, fracDecimal = 0;

    int c = 0;
    for (int i = point - 1; i >= 0; i--)
    {

        intDecimal += (octal[i] - '0') * pow(8, c);
        c++;
    }

    int f = 1;
    for (int i = point + 1; i < len; i++)
    {
        fracDecimal += (octal[i] - '0') * pow(8, -f);
        f++;
    }

    return intDecimal + fracDecimal;
}

double binaryToDecimal(string binary, int len)
{

    size_t point = binary.find('.');

    if (point == string::npos)
        point = len;

    float intDecimal = 0, fracDecimal = 0;

    int c = 0;
    for (int i = point - 1; i >= 0; i--)
    {

        intDecimal += (binary[i] - '0') * pow(2, c);
        c++;
    }

    int f = 1;
    for (int i = point + 1; i < len; i++)
    {
        fracDecimal += (binary[i] - '0') * pow(2, -f);
        f++;
    }

    return intDecimal + fracDecimal;
}
string decimalToHexadecimal(double num, int k_prec)
{
    string hexadecimal = "";

    int Integral = num;

    double fractional = num - Integral;

    while (Integral)
    {
        int rem = Integral % 16;

        if (rem < 10)
        {
            hexadecimal.push_back(rem + 48);
        }
        else
        {
            hexadecimal.push_back(rem + 55);
        }
        Integral /= 16;
    }

    reverse(hexadecimal.begin(), hexadecimal.end());

    hexadecimal.push_back('.');

    while (k_prec--)
    {

        fractional *= 16;
        int fract_bit = fractional;

        if (fract_bit <= 16)
        {
            if (fract_bit < 10)
            {
                fractional -= fract_bit;
                hexadecimal.push_back(fract_bit + 48);
            }
            else
            {
                fractional -= fract_bit;
                hexadecimal.push_back(fract_bit + 55);
            }
        }
        else
            hexadecimal.push_back(0 + '0');
    }

    return hexadecimal;
}

string decimalToOctal(double num, int k_prec)
{
    string octal = "";

    int Integral = num;

    double fractional = num - Integral;

    while (Integral)
    {
        int rem = Integral % 8;

        octal.push_back(rem + '0');

        Integral /= 8;
    }

    reverse(octal.begin(), octal.end());

    octal.push_back('.');

    while (k_prec--)
    {

        fractional *= 8;
        int fract_bit = fractional;

        if (fract_bit <= 7)
        {
            fractional -= fract_bit;
            octal.push_back(fract_bit + '0');
        }
        else
            octal.push_back(0 + '0');
    }

    return octal;
}

string decimalToBinary(double num, int k_prec)
{
    string binary = "";

    int Integral = num;

    double fractional = num - Integral;

    while (Integral)
    {
        int rem = Integral % 2;

        binary.push_back(rem + '0');

        Integral /= 2;
    }

    reverse(binary.begin(), binary.end());

    binary.push_back('.');

    while (k_prec--)
    {

        fractional *= 2;
        int fract_bit = fractional;

        if (fract_bit == 1)
        {
            fractional -= fract_bit;
            binary.push_back(1 + '0');
        }
        else
            binary.push_back(0 + '0');
    }

    return binary;
}
string binaryToOctal(string binary, int len)
{
    double decimal = binaryToDecimal(binary, len);

    return decimalToOctal(decimal, 5);
}
string binaryToHexadecimal(string binary, int len)
{
    double decimal = binaryToDecimal(binary, len);

    return decimalToHexadecimal(decimal, 5);
}
string octalToBinary(string octal, int len)
{
    float decimal = octalToDecimal(octal, len);
    return decimalToBinary(decimal, 5);
}
string octalToHexadecimal(string octal, int len)
{
    float decimal = octalToDecimal(octal, len);
    return decimalToHexadecimal(decimal, 5);
}
string hexToBinary(string hex, int len)
{
    float decimal = hexToDecimal(hex, len);
    return decimalToBinary(decimal, 5);
}
string hexToOctal(string hex, int len)
{
    float decimal = hexToDecimal(hex, len);
    return decimalToOctal(decimal, 5);
}
int main()
{
    cout << "************************************************" << endl
         << "*                                              *" << endl
         << "*     Welcome To Base Converter(Fractions)     *" << endl
         << "*                              by Sadman       *" << endl
         << "************************************************" << endl
         << endl;

    string binary, octal, hex;
    int choice;
    float n;

    do
    {
        cout << "Enter [1] to convert DECIMAL to BINARY (Fraction)" << endl;
        cout << "Enter [2] to convert DECIMAL to OCTAL (Fraction)" << endl;
        cout << "Enter [3] to convert DECIMAL to HEXADECIMAL (Fraction)" << endl;
        cout << "Enter [4] to convert BINARY to DECIMAL (Fraction)" << endl;
        cout << "Enter [5] to convert BINARY to OCTAl (Fraction)" << endl;
        cout << "Enter [6] to convert BINARY to HEXADECIMAL (Fraction)" << endl;
        cout << "Enter [7] to convert OCTAL to DECIMAL (Fraction)" << endl;
        cout << "Enter [8] to convert OCTAL to BINARY (Fraction)" << endl;
        cout << "Enter [9] to convert OCTAL to HEXADECIMAL (Fraction)" << endl;
        cout << "Enter [10] to convert HEXADECIMAL to DECIMAL (Fraction)" << endl;
        cout << "Enter [11] to convert HEXADECIMAL to BINARY (Fraction)" << endl;
        cout << "Enter [12] to convert HEXADECIMAL to OCTAL (Fraction)" << endl;

        cout << "Enter [13] to quit the program." << endl;
        cout << "Enter your choice...." << endl;
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter Fractional Decimal Number: ";
            cin >> n;
            cout << "Equivalent binary value: " << decimalToBinary(n, 5) << "\n";
            break;

        case 2:
            cout << "Enter Fractional Decimal Number: ";
            cin >> n;
            cout << "Equivalent Octal value: " << decimalToOctal(n, 5) << "\n";
            break;

        case 3:
            cout << "Enter Fractional Decimal Number: ";
            cin >> n;
            cout << "Equivalent hexadecimal value: " << decimalToHexadecimal(n, 5) << "\n";
            break;

        case 4:
            cout << "Enter Fractional Binary Number: ";
            cin >> binary;
            cout << "Equivalent Decimal value: " << binaryToDecimal(binary, binary.length()) << "\n";
            break;

        case 5:
            cout << "Enter Fractional Binary Number: ";
            cin >> binary;
            cout << "Equivalent Octal value: " << binaryToOctal(binary, binary.length()) << "\n";
            break;

        case 6:
            cout << "Enter Fractional Binary Number: ";
            cin >> binary;
            cout << "Equivalent Hexadecimal value: " << binaryToHexadecimal(binary, binary.length()) << "\n";
            break;

        case 7:
            cout << "Enter Fractional Octal Number: ";
            cin >> octal;
            cout << "Equivalent Decimal value: " << octalToDecimal(octal, octal.length()) << "\n";
            break;

        case 8:
            cout << "Enter Fractional Octal Number: ";
            cin >> octal;
            cout << "Equivalent Binary value: " << octalToBinary(octal, octal.length()) << "\n";
            break;

        case 9:
            cout << "Enter Fractional Octal Number: ";
            cin >> octal;
            cout << "Equivalent Hexadecimal value: " << octalToHexadecimal(octal, octal.length()) << "\n";
            break;

        case 10:
            cout << "Enter Fractional HexaDecimal Number: ";
            cin >> hex;
            cout << "Equivalent Decimal value: " << hexToDecimal(hex, hex.length()) << "\n";
            break;

        case 11:
            cout << "Enter Fractional HexaDecimal Number: ";
            cin >> hex;
            cout << "Equivalent Binary value: " << hexToBinary(hex, hex.length()) << "\n";
            break;

        case 12:
            cout << "Enter Fractional HexaDecimal Number: ";
            cin >> hex;
            cout << "Equivalent Octal value: " << hexToOctal(hex, hex.length()) << "\n";
            break;
            ;
        }
    } while (choice != 13);

    return 0;
}
