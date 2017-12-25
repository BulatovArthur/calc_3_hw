#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
void shift(int i, int count, double arrayint[], char arrayop[])
{
    for (int j = i + 1; j < count - 1; j++)
        arrayint[j] = arrayint[j + 1];
    for (int j = i; j < count - 2; j++)
        arrayop[j] = arrayop[j + 1];
}
double pow(double a, double b)
{
    double rez = 1;
    for (int i = 0; i < (int)b; i++)
        rez = rez * a;
    return rez;
}
double mod(double a, double b)
{ 
    return (int)a % (int)b; 
}
double add(double a, double b)
{
    return a + b; 
}
double sub(double a, double b)
{ 
    return a - b; 
}
double mul(double a, double b) 
{ 
    return a * b; 
}
double div(double a, double b) 
{ 
    return a / b; 
}
int main(int argc, char* argv[]) 
{
    string Array;
    string ch1;
    string ch2;
    string ch = "";
    double numbers[20];
    char signs[20];
    Array = argv[1];
    int flag = 1;
    int Ear = -1;
    int Last = Array.length();
    int counter = 0;
    int k = 0;
    while (flag == 1) 
    {
        for (int i = 0; i < Array.length(); i++) 
        {
            if (Array[i] == '(') Ear = i;
        }  //нашли самую внутреннюю скобку
        counter = Ear;
        if (Ear != -1) 
        {
            while ((Array[counter]) != ')') 
                counter++;
            Last = counter;
        };  //нашли соответсвующую ей закрывающуюся скобку
        for (int i = (Ear + 1); i < Last; i++) 
        {
            if ((Array[i] != '+') && (Array[i] != '-') && (Array[i] != '*') &&
                (Array[i] != '/') && (Array[i] != '^') && (Array[i] != '%'))
                ch = ch + Array[i]; //выделяем число
            else 
            {
                
                k++;
                numbers[k - 1] = atof(ch.c_str());
                ch = "";
                signs[k - 1] = Array[i];
            }
        }
        k++;
        numbers[k - 1] = atof(ch.c_str());
        ch = "";  //сформировали два массива (массив знаков внутри скобок и чисел
        //внутри скобок)
        for (int i = 0; i < k - 1; i++) 
        {
            if (signs[i] == '^') 
            {
                numbers[i] = pow(numbers[i], numbers[i + 1]);
                shift(i, k, numbers, signs);
                k--;
            }
        }

        for (int i = 0; i < k - 1; i++) 
        {
            if (signs[i] == '*') 
            {
                numbers[i] = mul(numbers[i], numbers[i + 1]);
                shift(i, k, numbers, signs);
                k--;
            }
        }
        for (int i = 0; i < k - 1; i++) 
        {
            if (signs[i] == '/') 
            {
                numbers[i] = div(numbers[i], numbers[i + 1]);
                shift(i, k, numbers, signs);
                k--;
            }
        }
        for (int i = 0; i < k - 1; i++) 
        {
            if (signs[i] == '%') 
            {
                numbers[i] = mod(numbers[i], numbers[i + 1]);
                shift(i, k, numbers, signs);
                k--;
            }
        }

        for (int i = 0; i < k - 1; i++) 
        {
            if (signs[i] == '+') 
            {
                numbers[i] = add(numbers[i], numbers[i + 1]);
                shift(i, k, numbers, signs);
                k--;
            }
        }
        for (int i = 0; i < k - 1; i++) 
        {
            if (signs[i] == '-') 
            {
                numbers[i] = sub(numbers[i], numbers[i + 1]);
                shift(i, k, numbers, signs);
                k--;
            }
        }
        k = 0;
        ostringstream strstr; //для преобразования целых и дробных чисел в обычную std:string.
        strstr << numbers[0];
        string rez = strstr.str();
        string nach;
        for (int i = 0; i < Ear; i++)
            nach = nach + Array[i];
        string end;
        int j = 0;
        for (int i = Last + 1; i < Array.length(); i++)
            end = end + Array[i];
        Array = nach + rez + end;
        Ear = -1;
        Last = Array.length();
        flag = 0;
        for (int i = 0; i < Array.length(); i++)
        {
            if ((Array[i] == '+') || (Array[i] == '-') || (Array[i] == '*') ||
                (Array[i] == '/') || (Array[i] == '^') || (Array[i] == '%'))
                flag = 1;
        }
    }
    cout << Array << endl;
}
