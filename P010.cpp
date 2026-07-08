/* P010 | Downcasting seguro con dynamic_cast
Implementa la siguiente jerarquía de clases:
Empleado (clase base): Atributo nombre y el método virtual void trabajar().
Programador (clase hija): Atributo lenguaje y el método void escribirCodigo().
Disenador (clase hija): Atributo herramienta y el método void crearMockup().
Gerente (clase hija): Atributo departamento — solo tiene el método trabajar() heredado, sin ningún método propio adicional.
Escribe la función libre:
void asignarTarea(Empleado* e)
Intenta un dynamic_cast a Programador* — si tiene éxito, llama a escribirCodigo().
Intenta un dynamic_cast a Disenador* — si tiene éxito, llama a crearMockup().
Si ninguno de los anteriores funciona, imprime "Tarea generica." (el Gerente caerá aquí debido a que no cumple con 
las condiciones anteriores).
En el main, crea un arreglo de punteros Empleado* que contenga un Programador, un Disenador y un Gerente, 
y llama a la función asignarTarea() con cada uno de ellos. Libera la memoria de forma adecuada.
Salida esperada (utilizando tus propios valores de prueba):
[Nombre] escribe codigo en [lenguaje]
[Nombre] crea mockup en [herramienta]
Tarea generica. */ 

#include <iostream>
using namespace std;

class Empleado {

protected:
    string nombre;

public:

    Empleado(string n):nombre(n){}

    virtual void trabajar(){
        cout<<nombre<<" trabaja."<<endl;
    }

    virtual ~Empleado(){}
};

class Programador:public Empleado{

private:
    string lenguaje;

public:

    Programador(string n,string l)
        :Empleado(n),lenguaje(l){}

    void escribirCodigo(){
        cout<<nombre <<" escribe codigo en " <<lenguaje <<endl;
    }
};

class Disenador:public Empleado{

private:
    string herramienta;

public:

    Disenador(string n,string h)
        :Empleado(n),herramienta(h){}

    void crearMockup(){
        cout<<nombre <<" crea mockup en " <<herramienta <<endl;
    }
};

class Gerente:public Empleado{

public:

    Gerente(string n):Empleado(n){}
};

void asignarTarea(Empleado* e){

    Programador* p=dynamic_cast<Programador*>(e);

    if(p!=nullptr){
        p->escribirCodigo();
        return;
    }

    Disenador* d=dynamic_cast<Disenador*>(e);

    if(d!=nullptr){
        d->crearMockup();
        return;
    }

    cout<<"Tarea generica."<<endl;
}

int main(){

    Empleado* empleados[3];

    empleados[0]=new Programador("Cristian","C++");
    empleados[1]=new Disenador("Maribel","Figma");
    empleados[2]=new Gerente("Jorge");

    for(int i=0;i<3;i++)
        asignarTarea(empleados[i]);

    for(int i=0;i<3;i++)
        delete empleados[i];

    return 0;
}