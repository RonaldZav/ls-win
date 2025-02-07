#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <filesystem>
#include <windows.h>

namespace fs = std::filesystem;

const int COLUMNS = 4; // Número de columnas a mostrar

// Función para determinar si un archivo es ejecutable
bool is_executable(const std::string &filename) {
    const std::vector<std::string> exts = {".exe", ".msi", ".bat", ".cmd", ".jar"};
    auto pos = filename.rfind('.');
    if (pos == std::string::npos)
        return false; // No tiene extensión

    std::string ext = filename.substr(pos);
    // Convertir a minúsculas para comparación
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    for (const auto &allowed : exts) {
        if (ext == allowed)
            return true;
    }
    return false;
}

// Función para obtener el ancho de la ventana de la consola
int get_console_width() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return 80; // Valor por defecto si falla
}

// Función para imprimir texto con un color específico y un ancho dado
void print_colored(const std::string &text, int color, int width) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    std::cout << std::left << std::setw(width) << text;
    SetConsoleTextAttribute(hConsole, 7); // Restaurar color por defecto
}

// Función para listar archivos y directorios
void list_files(const std::string &dirname, bool show_hidden) {
    std::vector<fs::directory_entry> entries;

    // Recorrer el directorio y guardar los elementos
    for (const auto &entry : fs::directory_iterator(dirname)) {
        // Filtrar archivos ocultos: se omiten si el nombre empieza con '.' 
        if (!show_hidden && entry.path().filename().string().front() == '.')
            continue;
        entries.push_back(entry);
    }

    // Ordenar alfabéticamente, similar a "alphasort"
    std::sort(entries.begin(), entries.end(), [](const fs::directory_entry &a, const fs::directory_entry &b) {
        return a.path().filename().string() < b.path().filename().string();
    });

    int console_width = get_console_width();
    int col_width = console_width / COLUMNS;
    int printed = 0;

    // Imprimir cada elemento con el formato y color adecuado
    for (const auto &entry : entries) {
        std::string name = entry.path().filename().string();
        if (fs::is_directory(entry.path())) {
            print_colored(name, 9, col_width);  // Azul para directorios
        } else if (is_executable(name)) {
            print_colored(name, 10, col_width); // Verde para ejecutables
        } else {
            std::cout << std::left << std::setw(col_width) << name;
        }
        printed++;
        if (printed % COLUMNS == 0)
            std::cout << "\n";
    }
    if (printed % COLUMNS != 0)
        std::cout << "\n";
}

int main(int argc, char *argv[]) {
    bool show_hidden = false;
    std::string dir = "."; // Directorio por defecto

    // Procesar argumentos: si se pasa "-a" se muestran los archivos ocultos
    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);
        if (arg == "-a") {
            show_hidden = true;
        } else {
            dir = arg;
        }
    }

    list_files(dir, show_hidden);
    return 0;
}
