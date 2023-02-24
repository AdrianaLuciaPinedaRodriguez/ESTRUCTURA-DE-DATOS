#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int num_corredores;
    float *tiempos;
    string *nombres;

  
    cout << "Ingrese el numero de corredores: ";
    cin >> num_corredores;

 
    tiempos = new float[num_corredores];
    nombres = new string[num_corredores];
    for (int i = 0; i < num_corredores; i++) {
        cout << "Ingrese el nombre del corredor " << i+1 << ": ";
        cin >> nombres[i];
        cout << "Ingrese el tiempo de carrera en minutos: ";
        cin >> tiempos[i];
    }

  
    for (int i = 0; i < num_corredores-1; i++) {
        for (int j = i+1; j < num_corredores; j++) {
            if (tiempos[i] > tiempos[j]) {
                swap(tiempos[i], tiempos[j]);
                swap(nombres[i], nombres[j]);
            }
        }
    }

   
    cout << "Clasificación:\n";
    for (int i = 0; i < num_corredores; i++) {
        cout << i+1 << ". " << nombres[i] << ": " << tiempos[i] << " minutos\n";
    }

    
    float promedio = 0;
    float mediana;
    for (int i = 0; i < num_corredores; i++) {
        promedio += tiempos[i];
    }
    promedio /= num_corredores;
    if (num_corredores % 2 == 0) {
        mediana = (tiempos[num_corredores/2-1] + tiempos[num_corredores/2]) / 2;
    } else {
        mediana = tiempos[num_corredores/2];
    }

    
    cout << "Promedio de tiempo utilizado: " << promedio << " minutos\n";
    cout << "Mediana de tiempo utilizado: " << mediana << " minutos\n";

    delete [] tiempos;
    delete [] nombres;

    return 0;
}

