/* P009 | Upcasting — qué se pierde y qué se conserva
Implementa la siguiente jerarquía de clases:
Vehiculo (clase base): Atributo marca, y el método virtual void describir(). (NOTA: describir() DEBE ser virtual para que el inciso c) demuestre polimorfismo).
Auto (clase hija): Atributo puertas, y el método void abrirMaletero().
Camion (clase hija): Atributo toneladas, y el método void cargarMercancia().
En el main realiza lo siguiente:
a) Crea un puntero de tipo Auto* y llama a los métodos describir() y abrirMaletero().
b) Haz upcasting a un puntero de tipo Vehiculo* y llama a describir(). ¿Puedes llamar a abrirMaletero() a través del puntero Vehiculo*? Intenta hacerlo
y anota el mensaje de error del compilador.
c) Crea un arreglo de punteros Vehiculo* que contenga un Auto y un Camion. Llama a describir() en ambos elementos mediante un ciclo. ¿A qué implementación
(Vehiculo, Auto o Camion) llega cada llamada?
Documenta detalladamente mediante comentarios dentro del código qué es accesible y qué no lo es a través del puntero de la clase base. */ 

#include <iostream>
using namespace std;

class Vehiculo {
protected:
    string marca;

public:
    Vehiculo(string m) : marca(m) {}

    virtual void describir() {
        cout << "Vehiculo marca " << marca << endl;
    }

    virtual ~Vehiculo() {}
};

class Auto : public Vehiculo {
private:
    int puertas;

public:
    Auto(string m, int p)
        : Vehiculo(m), puertas(p) {}

    void describir() override {
        cout << "Auto " << marca << " con " << puertas << " puertas" << endl;
    }

    void abrirMaletero() {
        cout << "Maletero abierto." << endl;
    }
};

class Camion : public Vehiculo {
private:
    double toneladas;

public:
    Camion(string m,double t)
        : Vehiculo(m), toneladas(t) {}

    void describir() override {
        cout << "Camion " << marca << " capacidad " << toneladas << " toneladas" << endl;
    }

    void cargarMercancia() {
        cout << "Mercancia cargada." << endl;
    }
};

int main() {

    Auto* a = new Auto("Toyota",4);

    a->describir();
    a->abrirMaletero();

    Vehiculo* v = a;

    v->describir();

    // v->abrirMaletero();
    // ERROR:
    // la clase Vehiculo no tiene ningún miembro llamado abrirMaletero
    Vehiculo* lista[2];

    lista[0] = new Auto("Mozan",4);
    lista[1] = new Camion("Volvo",15);

    for(int i=0;i<2;i++)
        lista[i]->describir();

    delete a;
    delete lista[0];
    delete lista[1];

    return 0;
}