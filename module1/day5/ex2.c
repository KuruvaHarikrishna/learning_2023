#include <stdio.h>

typedef struct {
    float real;
    float imaginary;
} Complex;

Complex read_complex() {
    Complex c;
    printf("Enter the real part: ");
    scanf("%f", &c.real);
    printf("Enter the imaginary part: ");
    scanf("%f", &c.imaginary);
    return c;
}

void write_complex(Complex c) {
    if (c.imaginary >= 0) {
        printf("Complex number: %.2f + %.2fi\n", c.real, c.imaginary);
    } else {
        printf("Complex number: %.2f - %.2fi\n", c.real, -c.imaginary);
    }
}

Complex add_complex(Complex c1, Complex c2) {
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.imaginary = c1.imaginary + c2.imaginary;
    return sum;
}

Complex multiply_complex(Complex c1, Complex c2) {
    Complex product;
    product.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    product.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return product;
}

int main() {
    Complex c1, c2, sum, product;

    printf("Reading complex number 1:\n");
    c1 = read_complex();
    printf("Reading complex number 2:\n");
    c2 = read_complex();

    printf("\n");

    printf("Complex number 1:\n");
    write_complex(c1);
    printf("Complex number 2:\n");
    write_complex(c2);

    printf("\n");

    sum = add_complex(c1, c2);
    printf("Addition:\n");
    write_complex(sum);

    product = multiply_complex(c1, c2);
    printf("Multiplication:\n");
    write_complex(product);

    return 0;
}
