#include <iostream>
#include <cmath>
#include <iomanip>

double calcAtan(double* x, int* N_steps)
{
    double xx = *x;
    int N = *N_steps;
    if (N <= 0) return 0.0;

    // Taylor series: arctan(x) = sum_{k=0..inf} (-1)^k * x^(2k+1) / (2k+1)
    double term = xx;            // k = 0 -> x^(1)
    double sum = term / 1.0;    // prvi term
    for (int k = 1; k < N; ++k) {
        // multiply by -x^2 to go from x^(2k-1+1) to x^(2k+1) with alternating sign
        term *= -(xx * xx);     // now term = (-1)^k * x^(2k+1)
        sum += term / (2.0 * k + 1.0);
    }
    return sum;
}

int main()
{
    // obmoèje integrala
    const double a = 0.0;
    const double PI = std::acos(-1.0);
    const double b = PI / 4.0;

    // vnos uporabnika
    int n_intervals;
    int tayl_terms;
    std::cout << "Vnesi stevilo trapeznih podintervalov (n): ";
    std::cin >> n_intervals;
    std::cout << "Vnesi stevilo clenov Taylorjeve vrste za arctan (N_steps): ";
    std::cin >> tayl_terms;

    if (n_intervals <= 0 || tayl_terms <= 0) {
        std::cerr << "Neveljavni parametri.\n";
        return 1;
    }

    double h = (b - a) / n_intervals;

    auto f = [&](double x)->double {
        double arg = x / 2.0;
        // calcAtan zahteva double* in int*, zato pripravimo lokalni dvojnik
        double arg_copy = arg;
        int Ncopy = tayl_terms;
        double at = calcAtan(&arg_copy, &Ncopy);
        return std::exp(3.0 * x) * at;
        };

    // trapezna formula
    double sum = f(a) + f(b);
    for (int i = 1; i < n_intervals; ++i) {
        double xi = a + i * h;
        sum += 2.0 * f(xi);
    }
    double integral = (h / 2.0) * sum;

    std::cout << std::fixed << std::setprecision(12);
    std::cout << "\nOcena integrala = " << integral << "\n";
    return 0;

}
