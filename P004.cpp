/* P004 | Upcasting implícito
Implementa la siguiente jerarquía de clases:
Empleado (clase base): Contiene los atributos nombre y salario, además del método virtual double calcularPago() = 0 (haciéndola una 
clase abstracta que no puede instanciarse por sí sola).
EmpleadoTC (clase hija): Representa a un empleado a tiempo completo y calcula su salario mensual fijo.
EmpleadoFL (clase hija): Representa a un empleado freelance. Recibe las horas trabajadas y la tarifa por hora, calculando su pago mediante la operación: pago=horas×tarifa.
Escribe una función libre:
void mostrarPago(Empleado* e) → Imprime el nombre del empleado junto al resultado obtenido de calcularPago().
En el main, crea un puntero de tipo Empleado* apuntando a cada tipo de clase hija (EmpleadoTC y EmpleadoFL), y llama a la función mostrarPago() para demostrar
que el mecanismo funciona correctamente con ambos tipos de objetos.
Salida esperada (utilizando tus propios valores de prueba):
Plaintext
Ana [TC]: $3500.00
Luis [FL]: $1200.00 */ 

#include <iostream>
using namespace std;

class Empleado {
protected:
    string nombre;
    double salario;

public:
    Empleado(string n, double s) : nombre(n), salario(s) {}
    virtual double calcularPago() = 0;
    string getNombre() {
        return nombre;
    }

    virtual ~Empleado() {}
};

class EmpleadoTC : public Empleado {
public:
    EmpleadoTC(string n, double s)
        : Empleado(n, s) {}

    double calcularPago() override {
        return salario;
    }
};

class EmpleadoFL : public Empleado {

    double horas;
    double tarifa;

public:

    EmpleadoFL(string n,double h,double t)
    : Empleado(n,0), horas(h), tarifa(t){}

    double calcularPago() override{
        return horas*tarifa;
    }
};

void mostrarPago(Empleado* e){
    cout<<e->getNombre()<<" $"<<e->calcularPago()<<endl;
}

int main(){

    Empleado* a=new EmpleadoTC("Ana",3500);
    Empleado* b=new EmpleadoFL("Luis",40,30);

    mostrarPago(a);
    mostrarPago(b);

    delete a;
    delete b;
}