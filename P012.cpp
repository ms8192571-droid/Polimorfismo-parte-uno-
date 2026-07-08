/* P012 | Diseñar una interfaz desde un enunciado
Se te da el siguiente enunciado de dominio:
"Un sistema de pagos debe poder procesar distintos medios: tarjeta de crédito, transferencia bancaria y pago en efectivo. Todos deben poder procesar un monto,
verificar si el pago fue exitoso, e imprimir un comprobante."
a) Diseña la clase abstracta MedioPago con los métodos virtuales puros que representan ese contrato.
b) Implementa las tres clases concretas (TarjetaCredito, TransferenciaBancaria y Efectivo).
c) En el main, crea un arreglo de punteros MedioPago* con los tres tipos de medios de pago y llama a los tres métodos 
en cada uno de ellos. Libera la memoria correctamente al finalizar.
d) ¿Qué ventaja da tener MedioPago como interfaz si mañana se agrega un cuarto medio de pago (como una criptomoneda)?
Salida esperada (con tus propios mensajes de prueba):
[Tarjeta] Procesando $150.00... Aprobado.
Comprobante: TC-****1234 $150.00
[Transferencia] Procesando $500.00... Aprobado.
Comprobante: TR-001 $500.00
[Efectivo] Procesando $20.00... Aprobado.
Comprobante: EF-001 $20.00 */ 

#include <iostream>
using namespace std;

class MedioPago {
public:
    virtual void procesarPago(double monto) = 0;
    virtual bool pagoExitoso() = 0;
    virtual void imprimirComprobante(double monto) = 0;
    virtual ~MedioPago() {}
};

class Tarjeta : public MedioPago {
public:
    void procesarPago(double monto) override {
        cout << "[Tarjeta] Procesando $" << monto << "... Aprobado." << endl;
    }

    bool pagoExitoso() override {
        return true;
    }

    void imprimirComprobante(double monto) override {
        cout << "Comprobante: TC-****1234 $" << monto << endl;
    }
};

class Transferencia : public MedioPago {
public:
    void procesarPago(double monto) override {
        cout << "[Transferencia] Procesando $" << monto << "... Aprobado." << endl;
    }

    bool pagoExitoso() override {
        return true;
    }

    void imprimirComprobante(double monto) override {
        cout << "Comprobante: TR-001 $" << monto << endl;
    }
};

class Efectivo : public MedioPago {
public:
    void procesarPago(double monto) override {
        cout << "[Efectivo] Procesando $" << monto << "... Aprobado." << endl;
    }

    bool pagoExitoso() override {
        return true;
    }

    void imprimirComprobante(double monto) override {
        cout << "Comprobante: EF-001 $" << monto << endl;
    }
};

int main() {

    MedioPago* pagos[3];

    pagos[0] = new Tarjeta();
    pagos[1] = new Transferencia();
    pagos[2] = new Efectivo();

    double montos[3] = {150,500,20};

    for(int i=0;i<3;i++){
        pagos[i]->procesarPago(montos[i]);
        pagos[i]->pagoExitoso();
        pagos[i]->imprimirComprobante(montos[i]);
    }

    for(int i=0;i<3;i++)
        delete pagos[i];

    return 0;
}