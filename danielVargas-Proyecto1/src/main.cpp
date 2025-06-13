#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// clase para representar una tarea
class Tarea {
public:
    int codigo_de_tarea;
    string nombre_de_tarea;
    string fecha_de_vencimiento;
    string hora_de_inicio;
    string hora_de_finalizacion;     

    Tarea(int codigo, const string& nombre, const string& fecha, const string& hora_inicio, const string& hora_finalizacion)
        : codigo_de_tarea(codigo), nombre_de_tarea(nombre), fecha_de_vencimiento(fecha), hora_de_inicio(hora_inicio), hora_de_finalizacion(hora_finalizacion) {}

    // validacion del codigo de la tarea (4 digitos)
    static bool validar_codigo(const string& codigo) {
        return codigo.size() == 4 && all_of(codigo.begin(), codigo.end(), ::isdigit);
    }

    // formato fecha (dd/mm/aaaa)
    static bool validar_fecha(const string& fecha) {
        if (fecha.size() != 10 || fecha[2] != '/' || fecha[5] != '/')
            return false;
        string dia = fecha.substr(0,2), mes = fecha.substr(3,2), anno = fecha.substr(6,4);
        return all_of(dia.begin(), dia.end(), ::isdigit) &&
               all_of(mes.begin(), mes.end(), ::isdigit) &&
               all_of(anno.begin(), anno.end(), ::isdigit);
    }

    // formato hora (hh:mm)
    static bool validar_hora(const string& hora) {
        // verifica que la entrada sea exactamente 4 digitos
        return hora.size() == 4;
    }

    // calculo de duracion de la tarea (en minutos)
    int calcular_duracion() const {
        int hora_inicio = stoi(hora_de_inicio.substr(0,2)), minuto_inicio  = stoi(hora_de_inicio.substr(3,2));
        int hora_fin = stoi(hora_de_finalizacion.substr(0,2)), minuto_fin = stoi(hora_de_finalizacion.substr(3,2));
        return (hora_fin * 60 + minuto_fin) - (hora_inicio * 60 + minuto_inicio);
    }
};


// clase para manejar la lista de tareas y las operaciones del menu
class MenuPrincipal {
    vector<Tarea> lista_de_tareas;

    // conversion a mayusculas (para respuestas S/N)
    static string convertir_a_mayusculas(const string& respuesta_usuario) {
        string respuesta = respuesta_usuario;
        transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);
        return respuesta;
    }

    // encontrar tarea por indice, retorna -1 si no se encuentra
    int get_tarea_por_indice(int codigo_de_tarea) {
        for (size_t i = 0; i < lista_de_tareas.size(); ++i)
            if (lista_de_tareas[i].codigo_de_tarea == codigo_de_tarea)
                return i;
        return -1;
    }

    // solicita al usuario un numero entero y valida que dicho entero este en el rango esperado
    int numero_entero_en_rango(const string& numero_ingresado_por_usuario, int rango_minimo, int rango_maximo) {
        string numero_ingresado;
        int valor_numerico;
        while (true) {
            cout << numero_ingresado_por_usuario;
            getline(cin, numero_ingresado);
            stringstream ss(numero_ingresado);
            if (ss >> valor_numerico && valor_numerico >= rango_minimo && valor_numerico <= rango_maximo)
                return valor_numerico;
            cout << "Opción inválida, vuelva a intentarlo" << endl;
        }
    }

    // solicita al usuario un string que no este vacio
    string string_no_vacio(const string& string_ingresado_por_usuario) {
        string string_ingresado;
        do {
            cout << string_ingresado_por_usuario;
            getline(cin, string_ingresado);
            if (string_ingresado.empty())
                cout << "Este campo es requerido." << endl;
        } while (string_ingresado.empty());
        return string_ingresado;
    }

    // convierte la hora de formato hhmm a hh:mm
    string mostrar_hora(const string& hora) {
        return hora.substr(0,2) + ":" + hora.substr(2,2);
    }

public:
    // ejecutador del menu para manejar las tareas
    void run() {
        int opcion_en_menu_elegida;
        do {
            mostrar_menu();
            opcion_en_menu_elegida = numero_entero_en_rango("Seleccione una opción: ", 1, 5);
            switch (opcion_en_menu_elegida) {
                case 1: agregar_tareas(); break;
                case 2: buscar_tarea(); break;
                case 3: mostrar_todas_las_tareas(); break;
                case 4: eliminar_tarea(); break;
                case 5: cout << "Saliendo del programa..." << endl; break;
            }
        } while (opcion_en_menu_elegida != 5);
    }

    // muestra el menu principal con las opciones disponibles
    void mostrar_menu() {
        cout << "\nMenú Principal\n"
             << "1. Agregar Tareas\n"
             << "2. Buscar Tarea\n"
             << "3. Mostrar todas las tareas\n"
             << "4. Eliminar Tarea\n"
             << "5. Salir del Programa\n";
    }

    // controlador de "Agregar Tareas" del menu
    void agregar_tareas() {
        if (lista_de_tareas.size() >= 5) {
            cout << "Ya ha alcanzado el máximo de 5 tareas." << endl;
            return;
        }
        int max_tareas_permitidas = 5 - lista_de_tareas.size();
        int numero_ingresado_por_usuario = numero_entero_en_rango("Ingrese la cantidad de tareas que desea agregar: ", 1, max_tareas_permitidas);

        for (int i = 0; i < numero_ingresado_por_usuario; ++i) {
            // solicita al usuario el codigo de la tarea y asegura que sea unico y valido
            cout << "Número de código tarea " << (i+1) << " (4 dígitos): ";
            string codigo_de_tarea_ingresado_por_usuario;
            do {
                getline(cin, codigo_de_tarea_ingresado_por_usuario);
                if (!Tarea::validar_codigo(codigo_de_tarea_ingresado_por_usuario))
                    cout << "El código debe ser numérico de 4 dígitos. Intente de nuevo: ";
            } while (!Tarea::validar_codigo(codigo_de_tarea_ingresado_por_usuario));
            int codigo_de_tarea = stoi(codigo_de_tarea_ingresado_por_usuario);

            if (get_tarea_por_indice(codigo_de_tarea) != -1) {
                cout << "El código ya existe. Intente con otro código." << endl;
                --i; // control para repetir la iteracion
                continue;
            }

            // solicita al usuario el resto de los campos de la tarea
            string nombre_de_tarea = string_no_vacio("Nombre de la tarea: ");

            string fecha_de_vencimiento;
            do {
                cout << "Fecha de vencimiento (dd/mm/aaaa): ";
                getline(cin, fecha_de_vencimiento);
                if (!Tarea::validar_fecha(fecha_de_vencimiento))
                    cout << "Formato de fecha inválido." << endl;
            } while (!Tarea::validar_fecha(fecha_de_vencimiento));

            string hora_de_inicio;
            do {
                cout << "Hora de inicio en formato hhmm (ejemplo 1245 ~ 12:45): ";
                getline(cin, hora_de_inicio);
                if (!Tarea::validar_hora(hora_de_inicio))
                    cout << "Formato de hora inválido. Debe ser 4 dígitos, por ejemplo 1245." << endl;
            } while (!Tarea::validar_hora(hora_de_inicio));

            string hora_de_finalizacion;
            do {
                cout << "Hora de finalización en formato hhmm (ejemplo 1245 ~ 12:45): ";
                getline(cin, hora_de_finalizacion);
                if (!Tarea::validar_hora(hora_de_finalizacion))
                    cout << "Formato de hora inválido. Debe ser 4 dígitos, por ejemplo 1245." << endl;
            } while (!Tarea::validar_hora(hora_de_finalizacion));

            // agrega la nueva tarea a la lista
            lista_de_tareas.emplace_back(codigo_de_tarea, nombre_de_tarea, fecha_de_vencimiento, hora_de_inicio, hora_de_finalizacion);
            cout << "Tarea agregada exitosamente" << endl;
        }

        // solicita al usuario si desea regresar al menu principal o agregar mas tareas
        string respuesta_usuario;
        do {
            cout << "Desea regresar al menú principal (S/N): ";
            getline(cin, respuesta_usuario);
            respuesta_usuario = convertir_a_mayusculas(respuesta_usuario);
        } while (respuesta_usuario != "S" && respuesta_usuario != "N");

        if (respuesta_usuario == "N")
            agregar_tareas();
    }

    // controlador de la opcion "Buscar Tarea" del menu
    void buscar_tarea() {
        if (lista_de_tareas.empty()) {
            cout << "Debe ingresar primero la tarea" << endl;
            return;
        }
        string codigo_de_tarea;
        do {
            cout << "Ingrese el código de la tarea a buscar: ";
            getline(cin, codigo_de_tarea);
            if (!Tarea::validar_codigo(codigo_de_tarea))
                cout << "El código debe ser numérico de 4 dígitos." << endl;
        } while (!Tarea::validar_codigo(codigo_de_tarea));
        int indice_de_tarea = get_tarea_por_indice(stoi(codigo_de_tarea));
        if (indice_de_tarea == -1) {
            cout << "Tarea no encontrada" << endl;
            return;
        }
        const Tarea& tarea_encontrada = lista_de_tareas[indice_de_tarea];
        cout << "+------------+----------------------------+----------------------------+---------------------------+\n";
        cout << "| Código     | Nombre                     | Fecha Vencimiento          | Minutos invertidos        |\n";
        cout << "+------------+----------------------------+----------------------------+---------------------------+\n";
        cout << "| " << setw(10) << setfill(' ') << tarea_encontrada.codigo_de_tarea
             << " | " << setw(26) << tarea_encontrada.nombre_de_tarea
             << " | " << setw(26) << tarea_encontrada.fecha_de_vencimiento
             << " | " << setw(25) << tarea_encontrada.calcular_duracion()
             << " |\n";
        cout << "+------------+----------------------------+----------------------------+---------------------------+\n";
        cout << "Hora de inicio: " << mostrar_hora(tarea_encontrada.hora_de_inicio) << endl;
    }

    // controlador de la opcion "Mostrar todas las tareas" del menu
    void mostrar_todas_las_tareas() {
        if (lista_de_tareas.empty()) {
            cout << "No hay tareas registradas" << endl;
            return;
        }
        cout << "Lista de todas las tareas:\n";
        cout << "+------------+----------------------------+----------------------------+--------------------------+\n";
        cout << "| Código     | Nombre                     | Fecha Vencimiento          | Minutos invertidos       |\n";
        cout << "+------------+----------------------------+----------------------------+--------------------------+\n";
        for (const auto& tarea : lista_de_tareas) {
            cout << "| " << setw(10) << setfill(' ') << tarea.codigo_de_tarea
                 << " | " << setw(26) << tarea.nombre_de_tarea
                 << " | " << setw(26) << tarea.fecha_de_vencimiento
                 << " | " << setw(24) << tarea.calcular_duracion()
                 << " |\n";
        }
        cout << "+------------+----------------------------+----------------------------+--------------------------+\n";
    }

    // controlador de la opcion "Eliminar Tarea" del menu
    void eliminar_tarea() {
        if (lista_de_tareas.empty()) {
            cout << "Debe ingresar primero la tarea" << endl;
            return;
        }

        string codigo_de_tarea;
        do {
            cout << "Ingrese el código de la tarea a eliminar: ";
            getline(cin, codigo_de_tarea);
            if (!Tarea::validar_codigo(codigo_de_tarea))
                cout << "El código debe ser numérico de 4 dígitos." << endl;
        } while (!Tarea::validar_codigo(codigo_de_tarea));
        int indice_de_tarea = get_tarea_por_indice(stoi(codigo_de_tarea));
        if (indice_de_tarea == -1) {
            cout << "Tarea no encontrada" << endl;
            return;
        }

        string respuesta_usuario;
        do {
            cout << "¿Está seguro de que desea eliminar la tarea [" << lista_de_tareas[indice_de_tarea].nombre_de_tarea << "]? (S/N): ";
            getline(cin, respuesta_usuario);
            respuesta_usuario = convertir_a_mayusculas(respuesta_usuario);
        } while (respuesta_usuario != "S" && respuesta_usuario != "N");

        if (respuesta_usuario == "S") {
            lista_de_tareas.erase(lista_de_tareas.begin() + indice_de_tarea);
            cout << "Tarea eliminada exitosamente" << endl;
        } else {
            cout << "Acción cancelada." << endl;
        }
    }
};

// punto de entrada del programa
int main() {
    MenuPrincipal menu_principal;
    menu_principal.run();
    return 0;
} 