#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

#define T 100

#include <typeinfo>

#include "model/Indice.h"
#include "model/Object.h"
#include "model/Operations.h"

#include "utils/Utils.h"

#include "classes/CID.h"
#include "classes/Cidade.h"
#include "classes/Especialidade.h"

#include "classes/Medicamento.h"
#include "classes/Medico.h"
#include "classes/Paciente.h"

#include "classes/Consulta.h"

#include "view/Menu.h"

int main(){

    // Configura o console para permitir saídas em UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // Configura o console para permitir entradas em UTF-8
    SetConsoleCP(CP_UTF8);
    
    Medicamento* listaMedicamentos[T];
    listaMedicamentos[0] = new Medicamento();

    Indice* indiceMedicamentos[T];
    int contadorMedicamentos = 0;

    Medico* listaMedicos[T];
    listaMedicos[0] = new Medico();

    Indice* indiceMedicos[T];
    int contadorMedicos = 0;

    CID* listaCIDs[T];
    listaCIDs[0] = new CID();

    Indice* indiceCIDs[T];
    int contadorCIDs = 0;
    
    Cidade* listaCidades[T];
    listaCidades[0] = new Cidade();

    Indice* indiceCidades[T];
    int contadorCidades = 0;

    Especialidade* listaEspecialidades[T];
    listaEspecialidades[0] = new Especialidade();

    Indice* indiceEspecialidades[T];
    int contadorEspecialidades = 0;

    Consulta* listaConsultas[T];
    listaConsultas[0] = new Consulta();

    Indice* indiceConsultas[T];
    int contadorConsultas = 0;

    Paciente* listaPacientes[T];
    listaPacientes[0] = new Paciente();

    Indice* indicePacientes[T]; 
    int contadorPacientes = 0;

    // Inicio da interface
    int opcao;

    while (true) {

        cout << "\n-------------------------------------------------------- HOSPITAL ROGÉRIO SGANZERLA LTDA -----------------------------------------------------\n\n";
        cout << "Cidade [1] | Especialidade [2] | CID [3] | Medicamento [4] | Paciente [5] | Médico [6] | Consulta [7]\n\n";
        cout << "Digite a opção: ";
        cin >> opcao;

        switch (opcao) {

            case 1:
                Menu::cidade(
                    indiceCidades,
                    listaCidades,
                    contadorCidades
                );
                break;
            case 2:
                Menu::especialidade(
                    indiceEspecialidades,
                    listaEspecialidades,
                    contadorEspecialidades
                );
                break;
            case 3:
                Menu::cid(
                    indiceCIDs,
                    listaCIDs,
                    contadorCIDs
                );
                break;
            case 4:
                Menu::medicamento(
                    indiceMedicamentos,
                    listaMedicamentos,
                    contadorMedicamentos
                );
                break;
            case 5:
                Menu::paciente(
                    indicePacientes,
                    listaPacientes,
                    contadorPacientes,

                    indiceCidades,
                    listaCidades,
                    contadorCidades,

                    indiceConsultas,
                    listaConsultas,
                    contadorConsultas
                );
                break;
            case 6:
                Menu::medico(
                    indiceMedicos,
                    listaMedicos,
                    contadorMedicos,

                    indiceEspecialidades,
                    listaEspecialidades,
                    contadorEspecialidades,

                    indiceCidades,
                    listaCidades,
                    contadorCidades,

                    indiceConsultas,
                    listaConsultas,
                    contadorConsultas
                );
                break;
            case 7:
                Menu::consulta(
                    indiceConsultas,
                    listaConsultas,
                    contadorConsultas,

                    indicePacientes,
                    listaPacientes,
                    contadorPacientes,

                    indiceCidades,
                    listaCidades,
                    contadorCidades,

                    indiceMedicos,
                    listaMedicos,
                    contadorMedicos,

                    indiceEspecialidades,
                    listaEspecialidades,
                    contadorEspecialidades,

                    indiceCIDs,
                    listaCIDs,
                    contadorCIDs,

                    indiceMedicamentos,
                    listaMedicamentos,
                    contadorMedicamentos
                );
                break;
        }

        Utils::clearConsole();
    }
}