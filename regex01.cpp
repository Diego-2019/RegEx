#include <iostream>
#include <regex>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("./ExerciseInputFiles/regex01.txt");
    string line;
    regex pattern("fooa*bar");

    // !match almacena una lista, match[0] es la coincidencia completa
    // !y los demas son los grupos de captura definidos en la regex.
    smatch match;

    if(file.is_open()) {
        // Leectura del archivo linea por linea
        while(getline(file, line)) {
            if(!line.empty()) {
                // Si hay coincidencia la imprime
                if (regex_search(line, match, pattern)) {
                    cout << match[0] << endl;
                }
            }
        }
    }
    else {
        cout << "Error al abrir el archivo";
    }
    
    return 0;
}