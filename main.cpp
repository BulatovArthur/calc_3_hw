#include <iostream>

using namespace std;

int ADD(int a, int b)
 { 
  return a + b;
 }
int SUB(int a, int b)
 { 
  return a - b;
 }
int MUL(int a, int b)
 { 
  return a * b; 
 }
double DIV(double a, int b) 
 {
  double rez;
  if (b != 0)
   {
    rez = a / b; 
    return rez;
   }
  else
   {
    cout << "Error";
   }
 }

int main() {
  char m;
  do 
   {
    cout << "calc" << endl;
    
    int a, b;
    char operation;
    
    cin >> a >> operation >> b;

    switch (operation) {
     case '+':
       cout << ADD(a, b) << endl;
       break;
     case '-':
       cout << SUB(a, b) << endl;
       break;
     case '*':
       cout << MUL(a, b) << endl;
       break;
     case '/':
       cout << DIV(double(a), b) << endl;
       break;
     default:
       cerr << "Error!" << endl;
    }
    cout << "Repeat? (p/n)" << endl;
    cin >> m;
   } 
  while (m == 'p');
return 0;
}
