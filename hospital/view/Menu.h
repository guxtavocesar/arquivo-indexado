#ifndef MENU_H
#define MENU_H

class Menu
{
    public:
        static void cidade(
            Indice* indiceCidades[],
            Cidade* listaCidades[],
            int &contadorCidades
        )
        {
            int opcao;

            cout << "\n\nLeitura de cidades [1] | Listagem de cidades [2]\n\n";
            cout << "Digite a opção: ";
            cin >> opcao;

            switch (opcao) {
                case 1:
                    Operations::read(
                        indiceCidades,
                        (Object**)listaCidades,
                        contadorCidades
                    );
                    break;
                case 2:
                    Operations::list(
                        indiceCidades,
                        (Object**)listaCidades,
                        contadorCidades
                    );
                    break;
            }
        }

        static void especialidade(
            Indice* indiceEspecialidade[],
            Especialidade* listaEspecialidades[],
            int &contadorEspecialidades
        )
        {
            int opcao;

            cout << "\n\nLeitura de especialidades [1] | Listagem de especialidades [2]\n\n";
            cout << "Digite a opção: ";
            cin >> opcao;

            switch (opcao) {
                case 1:
                    Operations::read(
                        indiceEspecialidade,
                        (Object**)listaEspecialidades,
                        contadorEspecialidades
                    );
                    break;
                case 2:
                    Operations::list(
                        indiceEspecialidade,
                        (Object**)listaEspecialidades,
                        contadorEspecialidades
                    );
                    break;
            }
        }

        static void cid(
            Indice* indiceCIDs[],
            CID* listaCIDs[],
            int &contadorCIDs
        )
        {
            int opcao;

            cout << "\n\nLeitura de CIDs [1] | Listagem de CIDs [2]\n\n";
            cout << "Digite a opção: ";
            cin >> opcao;

            switch (opcao) {
                case 1:
                    Operations::read(
                        indiceCIDs,
                        (Object**)listaCIDs,
                        contadorCIDs
                    );
                    break;
                case 2:
                    Operations::list(
                        indiceCIDs,
                        (Object**)listaCIDs,
                        contadorCIDs
                    );
                    break;
            }
        }

        static void medicamento(
            Indice* indiceMedicamentos[],
            Medicamento* listaMedicamentos[],
            int &contadorMedicamentos
        )
        {
            int opcao;

            cout << "\n\nLeitura de medicamentos [1] | Listagem de medicamentos [2] | Consulta estoque de medicamento [3] | Medicamentos abaixo do estoque min. [4]\n\n";
            cout << "Digite a opção: ";
            cin >> opcao;

            switch (opcao) {
                case 1:
                    Operations::read(
                        indiceMedicamentos,
                        (Object**)listaMedicamentos,
                        contadorMedicamentos
                    );
                    break;
                case 2:
                    Operations::list(
                        indiceMedicamentos,
                        (Object**)listaMedicamentos,
                        contadorMedicamentos
                    );
                    break;
                case 3:
                    Medicamento::listarMedicamentoEstoque(
                        indiceMedicamentos,
                        (Object**)listaMedicamentos,
                        contadorMedicamentos
                    );
                    break;
                case 4:
                    Medicamento::listarMedicamentoAbaixoEstoqueMin(
                        indiceMedicamentos,
                        listaMedicamentos,
                        contadorMedicamentos
                    );
                    break;
            }
        }

        static void paciente(
            Indice* indicePacientes[],
            Paciente* listaPacientes[],
            int &contadorPacientes,

            Indice* indiceCidades[],
            Cidade* listaCidades[],
            int contadorCidades,

            Indice* indiceConsultas[],
            Consulta* listaConsultas[],
            int contadorConsultas
        )
        {
            int opcao;

            cout << "\n\nLeitura de paciente [1] | Listagem de paciente [2] | Reorganizar lista de pacientes [3] | Excluir paciente [4]\n\n";
            cout << "Digite a opção: ";
            cin >> opcao;

            switch (opcao) {
                case 1:
                    Operations::read(
                        indicePacientes,
                        (Object**)listaPacientes,
                        contadorPacientes,

                        indiceCidades,
                        (Object**)listaCidades,
                        contadorCidades
                    );
                    break;
                case 2:
                    Operations::list(
                        indicePacientes,
                        (Object**)listaPacientes,
                        contadorPacientes,

                        indiceCidades,
                        (Object**)listaCidades,
                        contadorCidades
                    );
                    break;
                case 3:
                    Operations::rearrangeFile(
                        indicePacientes,
                        (Object**) listaPacientes,
                        contadorPacientes
                    );
                    break;
                case 4:
                    Paciente::excluir(
                        indicePacientes,
                        (Object**) listaPacientes,
                        contadorPacientes,

                        indiceConsultas,
                        listaConsultas,
                        contadorConsultas
                    );
                    break;
            }
        }

        static void medico(
            Indice* indiceMedicos[],
            Medico* listaMedicos[],
            int &contadorMedicos,

            Indice* indiceEspecialidades[],
            Especialidade* listaEspecialidades[],
            int contadorEspecialidades,

            Indice* indiceCidades[],
            Cidade* listaCidades[],
            int contadorCidades,

            Indice* indiceConsultas[],
            Consulta* listaConsultas[],
            int contadorConsultas
        )
        {
            int opcao;

            cout << "\n\nLeitura de médicos [1] | Listagem de médicos [2] | Excluir médico [3]\n\n";
            cout << "Digite a opção: ";
            cin >> opcao;

            switch (opcao) {
                case 1:
                    Operations::read(
                        indiceMedicos,
                        (Object**) listaMedicos,
                        contadorMedicos,

                        indiceEspecialidades,
                        (Object**) listaEspecialidades,
                        contadorEspecialidades,

                        indiceCidades,
                        (Object**) listaCidades,
                        contadorCidades
                    );
                    break;
                case 2:
                    Operations::list(
                        indiceMedicos,
                        (Object**) listaMedicos,
                        contadorMedicos,

                        indiceEspecialidades,
                        (Object**) listaEspecialidades,
                        contadorEspecialidades,

                        indiceCidades,
                        (Object**) listaCidades,
                        contadorCidades
                    );
                    break;
                case 3:
                    Medico::excluir(
                        indiceMedicos,
                        (Object**) listaMedicos,
                        contadorMedicos,

                        indiceConsultas,
                        listaConsultas,
                        contadorConsultas
                    );
                    break;
            }
        }

        static void consulta(
            Indice* indiceConsultas[],
            Consulta* listaConsultas[],
            int &contadorConsultas,

            Indice* indicePacientes[],
            Paciente* listaPacientes[],
            int &contadorPacientes,

            Indice* indiceCidades[],
            Cidade* listaCidades[],
            int &contadorCidades,

            Indice* indiceMedicos[],
            Medico* listaMedicos[],
            int &contadorMedicos,

            Indice* indiceEspecialidades[],
            Especialidade* listaEspecialidades[],
            int &contadorEspecialidades,

            Indice* indiceCIDs[],
            CID* listaCIDs[],
            int &contadorCIDs,

            Indice* indiceMedicamentos[],
            Medicamento* listaMedicamentos[],
            int &contadorMedicamentos
        )
        {
            int opcao;

            cout << "\n\nAgendar consulta [1] | Listagem de consultas [2] | Total valor arrecadado consulta [3] \n\n";
            cout << "Digite a opção: ";
            cin >> opcao;

            switch (opcao) {
                case 1:
                    Operations::read(
                        indiceConsultas,
                        (Object**) listaConsultas,
                        contadorConsultas,

                        indicePacientes,
                        (Object**) listaPacientes,
                        contadorPacientes,

                        indiceCidades,
                        (Object**) listaCidades,
                        contadorCidades,

                        indiceMedicos,
                        (Object**) listaMedicos,
                        contadorMedicos,

                        indiceEspecialidades,
                        (Object**) listaEspecialidades,
                        contadorEspecialidades,

                        indiceCIDs,
                        (Object**) listaCIDs,
                        contadorCIDs,

                        indiceMedicamentos,
                        (Object**) listaMedicamentos,
                        contadorMedicamentos
                    );
                    break;
                case 2:
                    Operations::list(
                        indiceConsultas,
                        (Object**) listaConsultas,
                        contadorConsultas,

                        indicePacientes,
                        (Object**) listaPacientes,
                        contadorPacientes,

                        indiceCidades,
                        (Object**) listaCidades,
                        contadorCidades,

                        indiceMedicos,
                        (Object**) listaMedicos,
                        contadorMedicos,

                        indiceEspecialidades,
                        (Object**) listaEspecialidades,
                        contadorEspecialidades,

                        indiceCIDs,
                        (Object**) listaCIDs,
                        contadorCIDs,

                        indiceMedicamentos,
                        (Object**) listaMedicamentos,
                        contadorMedicamentos
                    );
                    break;
                case 3:
                    Consulta::consultarValorTotalConsultas(
                        indiceConsultas,
                        listaConsultas,
                        contadorConsultas,
                        
                        indiceMedicamentos,
                        (Object**) listaMedicamentos,
                        contadorMedicamentos
                    );
                    break;
            }
        }
};

#endif