#include <bits/stdc++.h>

using namespace std;

/* Must be accurate to 8 decimal places */
#define ERROR 0.00000001

double e(double x)
{
  int n, n_bound = 0;
  double estimated_error = 1; /* arbitrary value > ERROR */
  /* Error <= M * x^(n+1) / (n+1)! , where M is the maximum value of the n-th derivative */
  while (abs(estimated_error) > ERROR)
  {
    n_bound++;
    estimated_error = pow(2.71, abs(x)); /* the absolute maximum value M between [0, x] of e^x is approximately 2.71^x */
    /* calculates x^(n+1) / (n+1)! while preventing overflow */
    for (n = n_bound + 1; n > 0; n--)
      estimated_error = estimated_error * x / n;
    estimated_error = abs(estimated_error);
  }

  int k;
  double term, sum = 1;
  /* begin at n = 1, since the 0th term ( e^0 / 0! ) is already added to sum */
  for (n = 1; n <= n_bound; n++)
  {
    term = 1;
    /* calculates the n-th term ( x^n / n! ) while preventing overflow */
    for (k = n; k > 0; k--)
      term *= x / k;
    sum += term;
  }
  return sum;
}

double sin(double x)
{
  int n, n_bound = 0;
  double estimated_error = 1; /* arbitrary value > ERROR */
  /* Error <= M * x^(n+1) / (n+1)! , where M is the maximum value of the n-th derivative */
  while (abs(estimated_error) > ERROR)
  {
    n_bound++;
    estimated_error = 1; /* the absolute maximum value M of any n-th derivative of sin x is 1 */
    /* calculates x^(n+1) / (n+1)! while preventing overflow */
    for (n = n_bound + 1; n > 0; n--)
      estimated_error = estimated_error * x / n;
    estimated_error = abs(estimated_error);
  }

  int k;
  double term, sum = 0;
  for (n = 0; n <= n_bound; n++)
  {
    /* if n is even, then (-1)^n = 1, else -1 */
    term = (n % 2 == 0) ? 1 : -1;
    /* calculates the n-th term ( x^(2*n+1) / (2*n+1)! ) while preventing overflow */
    for (k = 2 * n + 1; k > 0; k--)
      term *= x / k;
    sum += term;
  }
  return sum;
}

double cos(double x)
{
  int n, n_bound = 0;
  double estimated_error = 1; /* arbitrary value > ERROR */
  /* Error <= M * x^(n+1) / (n+1)! , where M is the maximum value of the n-th derivative */
  while (abs(estimated_error) > ERROR)
  {
    n_bound++;
    estimated_error = 1; /* the absolute maximum value M of any n-th derivative of cos x is 1 */
    /* calculates x^(n+1) / (n+1)! while preventing overflow */
    for (n = n_bound + 1; n > 0; n--)
      estimated_error = estimated_error * x / n;
  }

  int k;
  double term, sum = 0;
  for (n = 0; n <= n_bound; n++)
  {
    /* if n is even, then (-1)^n = 1, else -1 */
    term = (n % 2 == 0) ? 1 : -1;
    /* calculates the n-th term ( x^(2*n) / (2*n)! ) while preventing overflow */
    for (k = 2 * n; k > 0; k--)
      term *= x / k;
    sum += term;
  }
  return sum;
}

double estimate(int option, double x)
{
  switch (option)
  {
  case 1:
    return e(x);
  case 2:
    return sin(x);
  case 3:
    return cos(x);
  default:
    return -1;
  }
}

void display_menu(ostream &out, istream &in)
{
  out << "Select a function to approximate...\n"
      << "1. e^x\n"
      << "2. sin x\n"
      << "3. cos x\n";
  int option;
  in >> option;

  out << "Enter a real value of x on the interval [-5, 5]\n";
  double x;
  in >> x;

  out << setprecision(16); /* helps see 8 floating-point accuracy */
  out << estimate(option, x) << "\n";
}

int main()
{
  while (1)
  {
    display_menu(cout, cin);
  }
  return 0;
}
