/* P007 | Arreglo polimórfico
Implementa la siguiente jerarquía de clases:
Figura (clase base abstracta):
virtual double area() = 0
virtual double perimetro() = 0
virtual void imprimir() const = 0
virtual ~Figura() {}
Circulo (clase hija): Atributo radio.
Cuadrado (clase hija): Atributo lado.
TrianguloR (clase hija): Representa un triángulo rectángulo. Contiene los atributos cateto1 y cateto2. Calcula la hipotenusa automáticamente usando el teorema de Pitágoras 
(o pídela como parámetro en el constructor).
metro=cateto1+cateto2+hipotenusa
En el main, crea un arreglo de punteros Figura* de 5 elementos que contenga una combinación de distintas figuras.
Recorre el arreglo una sola vez mediante un ciclo para calcular e imprimir el área y el perímetro de cada una de ellas utilizando el método imprimir().
Al finalizar, asegúrate de liberar la memoria dinámica correctamente.
Salida esperada (utilizando tus propios valores de prueba):
Plaintext
Circulo    : area=78.54  perim=31.42
Cuadrado   : area=25.00  perim=20.00
Triangulo : area=6.00   perim=12.00
Circulo    : area=12.57  perim=12.57
Cuadrado   : area=9.00   perim=12.00 */ 

#include <iostream>
#include <cmath>

using namespace std;

class Figura {
public:
    virtual double area() = 0;
    virtual double perimetro() = 0;
    virtual void imprimir() const = 0;
    virtual ~Figura() {}
};

class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {}

    double area() override {
        return M_PI * radio * radio;
    }

    double perimetro() override {
        return 2 * M_PI * radio;
    }

    void imprimir() const override {
        cout << "Circulo    : ";
    }
};

class Cuadrado : public Figura {
private:
    double lado;

public:
    Cuadrado(double l) : lado(l) {}

    double area() override {
        return lado * lado;
    }

    double perimetro() override {
        return 4 * lado;
    }

    void imprimir() const override {
        cout << "Cuadrado   : ";
    }
};

class TrianguloR : public Figura {
private:
    double cateto1;
    double cateto2;
    double hipotenusa;

public:
    TrianguloR(double c1, double c2) : cateto1(c1), cateto2(c2) {
        hipotenusa = sqrt((cateto1 * cateto1) + (cateto2 * cateto2));
    }

    double area() override {
        return (cateto1 * cateto2) / 2.0;
    }

    double perimetro() override {
        return cateto1 + cateto2 + hipotenusa;
    }

    void imprimir() const override {
        cout << "TrianguloR : ";
    }
};

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);

    Figura* figuras[5] = {
        new Circulo(5.0),
        new Cuadrado(5.0),
        new TrianguloR(3.0, 4.0),
        new Circulo(2.0),
        new Cuadrado(3.0)
    };

    for (int i = 0; i < 5; i++) {
        figuras[i]->imprimir();
        cout << "area=" << figuras[i]->area() 
             << "  perimetro=" << figuras[i]->perimetro() << endl;
    }

    for (int i = 0; i < 5; i++) {
        delete figuras[i];
    }

    return 0;
}