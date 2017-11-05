#include <iostream>

using namespace std;

int main()
{ 
  cout << "Operation: + - * /" << endl;
  cout << "To get result click 'j'!" << endl;  
  int a;
  int b;
  char op;

  cin >> a;
 
  if (!cin)
  {
    cout << "Error! It is not correct, repeat again." << endl;
  }
  for (char op; cin >> op; )
  {
    if (op != 'j')
    {
      cin >> b;
    }

    if (!cin)
    {
      cout << "Error! It is not correct, repeat again." << endl;
    }  
    switch (op) 
    {
     case '+':
       a += b;
       break;
     case '-':
       a -= b;
       break;
     case '*':
       a *= b;
       break;
     case '/':
       a /= b;
       break;
     default:
       cout << "Results: " << a << '\n';
       return 0;
    }
  }
}
