//Polynomial.h

#include <iostream>
using namespace std;
#define MAX_DEGREE 20
class Polynomial {
private:
    int Coefficient[MAX_DEGREE + 1];
    int degree[MAX_DEGREE + 1];
    void Standardize();
    void sort();
public:
    Polynomial();
    Polynomial(const Polynomial& obj);
    void operator=(const Polynomial& obj);

    Polynomial operator+(const Polynomial& obj);
    Polynomial operator+(const int var);
    friend Polynomial operator+(const int var, Polynomial obj);

    friend Polynomial operator-(Polynomial obj);
    Polynomial operator-(Polynomial obj);
    Polynomial operator-(const int var);
    friend Polynomial operator-(const int var, Polynomial obj);

    Polynomial operator*(Polynomial obj);
    Polynomial operator*(const int var);
    friend Polynomial operator*(const int var, Polynomial obj);

    Polynomial& operator++();
    Polynomial& operator++(int);

    Polynomial operator/(Polynomial obj);

    Polynomial operator%(Polynomial obj);

    friend istream& operator>>(istream&, Polynomial&);
    friend ostream& operator<<(ostream&, const Polynomial&);
};
