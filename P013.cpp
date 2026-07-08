/* P013 | Extender con Base::metodo()
Implementa la jerarquía de un sistema de logging:
Logger (clase base):
virtual void log(string mensaje) → Imprime: [LOG] mensaje
LoggerFecha (clase hija de Logger):
void log(string mensaje) override
→ Llama a Logger::log(mensaje) primero.
→ Luego imprime: [FECHA] 2024-01-01
LoggerCompleto (clase hija de LoggerFecha):
void log(string mensaje) override
→ Llama a LoggerFecha::log(mensaje) primero.
→ Luego imprime: [NIVEL] INFO
En el main, crea los tres tipos de objetos y llama a log("Sistema iniciado") en cada uno de ellos.
Observa cómo cada nivel agrega información de forma incremental sin reemplazar el comportamiento del nivel anterior.
Salida esperada:
-- Logger base:
[LOG] Sistema iniciado

-- LoggerFecha:
[LOG] Sistema iniciado
[FECHA] 2024-01-01

-- LoggerCompleto:
[LOG] Sistema iniciado
[FECHA] 2024-01-01
[NIVEL] INFO */ 

#include <iostream>
using namespace std;

class Logger {
public:
    virtual void log(string mensaje) {
        cout << "[LOG] " << mensaje << endl;
    }

    virtual ~Logger() {}
};

class LoggerFecha : public Logger {
public:
    void log(string mensaje) override {

        Logger::log(mensaje);

        cout << "[FECHA] 2024-01-01" << endl;
    }
};

class LoggerCompleto : public LoggerFecha {
public:
    void log(string mensaje) override {

        LoggerFecha::log(mensaje);

        cout << "[NIVEL] INFO" << endl;
    }
};

int main() {

    Logger base;
    LoggerFecha fecha;
    LoggerCompleto completo;

    cout << "-- Logger base:" << endl;
    base.log("Sistema iniciado");

    cout << endl;

    cout << "-- LoggerFecha:" << endl;
    fecha.log("Sistema iniciado");

    cout << endl;

    cout << "-- LoggerCompleto:" << endl;
    completo.log("Sistema iniciado");

    return 0;
}