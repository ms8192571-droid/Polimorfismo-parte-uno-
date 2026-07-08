/* P006 | Polimorfismo por referencia
Implementa la siguiente jerarquía de clases:
Instrumento (clase base): Contiene el método virtual void tocar() y su destructor virtual ~Instrumento() {}.
Guitarra (clase hija): tocar() imprime "Tañe las cuerdas".
Piano (clase hija): tocar() imprime "Presiona las teclas".
Bateria (clase hija): tocar() imprime "Golpea los parches".
Escribe DOS funciones libres sobrecargadas:
void concierto(Instrumento* i) → Versión por puntero.
void concierto(Instrumento& i) → Versión por referencia.
En el main, demuestra el funcionamiento de ambas versiones utilizando los tres tipos de instrumentos. 
Para la versión por referencia, crea los objetos en el stack (memoria estática, sin usar new ni delete).
Salida esperada:
[puntero]    Tañe las cuerdas
[puntero]    Presiona las teclas
[puntero]    Golpea los parches
[referencia] Tañe las cuerdas
[referencia] Presiona las teclas
[referencia] Golpea los parches */ 

#include <iostream>
using namespace std;

class Instrumento{

public:

    virtual void tocar(){
        cout<<"Instrumento"<<endl;
    }

    virtual ~Instrumento(){}
};

class Guitarra:public Instrumento{

public:

    void tocar() override{
        cout<<"Tañe las cuerdas"<<endl;
    }
};

class Piano:public Instrumento{

public:

    void tocar() override{
        cout<<"Presiona las teclas"<<endl;
    }
};

class Bateria:public Instrumento{

public:

    void tocar() override{
        cout<<"Golpea los parches"<<endl;
    }
};

void concierto(Instrumento* i){
    cout<<"[puntero] ";
    i->tocar();
}

void concierto(Instrumento& i){
    cout<<"[referencia] ";
    i.tocar();
}

int main(){

    Instrumento* g=new Guitarra();
    Instrumento* p=new Piano();
    Instrumento* b=new Bateria();

    concierto(g);
    concierto(p);
    concierto(b);

    Guitarra g2;
    Piano p2;
    Bateria b2;

    concierto(g2);
    concierto(p2);
    concierto(b2);

    delete g;
    delete p;
    delete b;
}