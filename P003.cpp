/* P003 | Reescribir con polimorfismo

Se te da el siguiente sistema SIN polimorfismo. Tu trabajo es reescribirlo CON polimorfismo dinámico.
// VERSIÓN SIN polimorfismo — NO modifiques esto, solo léelo para entender qué hace:
C++
#include <iostream>
using namespace std;

void emitirSonido(string tipo) {
    if (tipo == "perro")  cout << "Guau!"  << endl;
    else if (tipo == "gato")  cout << "Miau!"  << endl;
    else if (tipo == "vaca")  cout << "Muuu!"  << endl;
    else cout << "Sonido desconocido." << endl;
}

int main() {
    string animales[] = {"perro","gato","vaca","perro"};
    for (int i = 0; i < 4; i++)
        emitirSonido(animales[i]);
    return 0;
}
Implementa la versión CON polimorfismo:
Clase base Animal con virtual void hacerSonido()
Clases Perro, Gato, Vaca con override
main con arreglo Animal* de 4 elementos con la misma secuencia original (perro, gato, vaca, perro)
Misma salida que el original
Agrega la clase Pato con hacerSonido() → "Cuac!" pero NO la agregues al arreglo del main — el objetivo es demostrar que el código existente NO necesita cambiar para que el nuevo tipo exista y funcione
Salida esperada (misma que el original):
Guau!
Miau!
Muuu!
Guau!
Responde también:
¿Qué tendrías que modificar en la versión SIN polimorfismo para agregar el Pato? 
¿Y en tu versión CON polimorfismo? ¿Por qué la clase Pato puede existir sin tocar el main?

*/ 


#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() {
        cout << "Sonido desconocido." << endl;
    }

    virtual ~Animal() {}
};

class Perro : public Animal {
public:
    void hacerSonido() override {
        cout << "Guau!" << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() override {
        cout << "Miau!" << endl;
    }
};

class Vaca : public Animal {
public:
    void hacerSonido() override {
        cout << "Muuu!" << endl;
    }
};

class Pato : public Animal {
public:
    void hacerSonido() override {
        cout << "Cuac!" << endl;
    }
};

int main() {

    Animal* animales[4];

    animales[0] = new Perro();
    animales[1] = new Gato();
    animales[2] = new Vaca();
    animales[3] = new Perro();

    for (int i = 0; i < 4; i++)
        animales[i]->hacerSonido();

    for (int i = 0; i < 4; i++)
        delete animales[i];

    return 0;
}