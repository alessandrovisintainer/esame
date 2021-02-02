#include <iostream>

using namespace std;

struct Complex
{
    double re;
    double im;
};

// Sum of complex numbers
Complex add(Complex a, Complex b)
{
    Complex sum;
    sum.re = a.re + b.re; // compute real part
    sum.im = a.im + b.im; // compute imaginary part
    return sum;
}

// Difference of complex numbers
Complex sub(Complex a, Complex b)
{
    Complex difference;
    difference.re = a.re - b.re; // compute real part
    difference.im = a.im - b.im; // compute imaginary part
    return difference;
}

// Product of complex numbers
Complex mul(Complex a, Complex b)
{
    Complex product;
    product.re = (a.re*b.re) - (a.im*b.im); // Compute real part
    product.im = (a.re*b.im) + (a.im*b.re); // Compute imaginary part
    return product;
}

int main()
{
    char op;
    double r1, r2, c1, c2;
    
    // leggere i dati da stdin
    cin >> op >> r1 >> c1 >> r2 >> c2;
    Complex n1 = {r1, c1};
    Complex n2 = {r2, c2};
    
    if (op == 'a')
    {   
        Complex sum = add(n1, n2);
        cout << sum.re << " ";
        if (sum.im > 0)  // An operation sign is necessary between real and complex part
        {
            cout << "+";
        }
        cout << sum.im << "i";
        
    }

    else if (op == 's')
    {
        Complex difference = sub(n1, n2);
        cout << difference.re << " ";
        if (difference.im > 0)
        {
            cout << "+";
        }
        cout << difference.im << "i";
    }

    else if (op == 'm')
    {
        Complex product = mul(n1, n2);
        cout << product.re << " ";
        if (product.im > 0)
        {
            cout << "+";
        }
        cout << product.im << "i";
    }
    
    else
    {
        cout << "errore";
    }
    

    return 0;
}