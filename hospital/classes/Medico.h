#ifndef MEDICO_H
#define MEDICO_H

#include "Consulta.h"

class Medico : public Object
{
    private:
        int codigoEspecialidade;
        int codigoCidade;

    public:
        string nome;
        string endereco;
        int telefone;

        Medico()
        {
            Object::setCodigo(0);
            Object::setStatus(0);
            this->nome = "";
            this->endereco = "";
            this->telefone = 0;

            this->codigoEspecialidade = 0;
            this->codigoCidade = 0;
        }

        void listaAtributos()
        {
            cout << "\nLISTANDO MÉDICO\n" << endl;
            cout << "CÓDIGO   : " << Object::getCodigo() << endl;
            cout << "NOME     : " << this->nome << endl;
        }

        void listarAtributos(
            Indice* indiceEspecialidades[],
            Object* listaEspecialidades[],
            int contadorEspecialidades,

            Indice* indiceCidades[],
            Object* listaCidades[],
            int contadorCidades
        )
        {
            cout << "\nLISTANDO MÉDICO\n" << endl;
            cout << "CÓDIGO   : " << Object::getCodigo() << endl;
            cout << "NOME     : " << this->nome << endl;

            // Recuperando endereco da especialidade
            int enderecoEspecialidade = Operations::binarySearch(
                indiceEspecialidades,
                listaEspecialidades, 
                contadorEspecialidades,
                this->codigoEspecialidade
            );

            // Listando atributos da especialidade do médico
            listaEspecialidades[enderecoEspecialidade]->listarAtributos();

            cout << "ENDEREÇO  : " << this->endereco << endl;
            cout << "TELEFONE  : " << this->telefone << endl;

            // Recuperando endereco da cidade
            int enderecoCidade = Operations::binarySearch(
                indiceCidades,
                listaCidades, 
                contadorCidades,
                this->codigoCidade
            );

            // Listando atributos da especialidade de cidade
            listaCidades[enderecoCidade]->listarAtributos();
        }

        void leitura(
            Indice* indiceMedicos[],
            Object* listaMedicos[],
            int contadorMedicos,

            Indice* indiceEspecialidades[],
            Object* listaEspecialidades[],
            int contadorEspecialidades,
            
            Indice* indiceCidades[],
            Object* listaCidades[],
            int contadorCidades
        )
		{
            int codigo;
            string nome;
            string endereco;
            int telefone;
            int codigoEspecialidade;
            int codigoCidade;

            bool resultMedico;
            bool resultCidade;
            bool resultEspecialidade;

			cout << "\nLEITURA DE MEDICO\n" << endl;

            do {

                cout << "Informe o CÓDIGO   : ";
                cin >> codigo;
                cin.ignore();

                resultMedico = Utils::isCodigoDuplicado(
                    indiceMedicos,
                    listaMedicos,
                    contadorMedicos,
                    codigo
                );
           
            } while (resultMedico);

            cout << "\nInforme o NOME     : ";
            getline(cin, nome);

            cout << "Informe o ENDEREÇO : ";
            getline(cin, endereco);

            cout << "Informe o TELEFONE : ";
            cin >> telefone;

            do {

                cout << "\nInforme o CÓDIGO DA ESPECIALIDADE : ";
                cin >> codigoEspecialidade;

                resultEspecialidade = Utils::isCodigoExist(
                    indiceEspecialidades,
                    listaEspecialidades,
                    contadorEspecialidades,
                    codigoEspecialidade
                );

            } while (!resultEspecialidade);

            // Recuperando endereco da especialidade
            int enderecoEspecialidade = Operations::binarySearch(
                indiceEspecialidades,
                listaEspecialidades, 
                contadorEspecialidades,
                codigoEspecialidade
            );

            // Listando atributos da especialidade do médico
            listaEspecialidades[enderecoEspecialidade]->listarAtributos();

            do {

                cout << "\nInforme o CÓDIGO DA CIDADE        : ";
                cin >> codigoCidade;

                resultCidade = Utils::isCodigoExist(
                    indiceCidades,
                    listaCidades,
                    contadorCidades,
                    codigoCidade
                );

            } while (!resultCidade);

            // Recuperando endereco da cidade
            int enderecoCidade = Operations::binarySearch(
                indiceCidades,
                listaCidades,
                contadorCidades,
                codigoCidade
            );

            // Listando atributos da cidade do médico
            listaCidades[enderecoCidade]->listarAtributos();

            Object::setCodigo(codigo);
            this->nome = nome;
            this->endereco = endereco;
            this->telefone = telefone;
            this->codigoEspecialidade = codigoEspecialidade;
            this->codigoCidade = codigoCidade;
		}

        static void excluir(
            Indice* indiceMedicos[],
            Object* listaMedicos[],
            int contadorMedicos,

            Indice* indiceConsultas[],
            Consulta* listaConsultas[],
            int contadorConsultas
        )
        {
            int codigoPesquisa = 0;

            cout << "\nEXCLUSÃO DE MÉDICO\n";

            cout << "\nDigite o codigo a ser excluido: ";
            cin >> codigoPesquisa;

            int endereco = Operations::binarySearch(
                indiceMedicos,
                listaMedicos,
                contadorMedicos,
                codigoPesquisa
            );

            if (endereco != - 1) {

                string confirmaExclusao;

                Medico* medico = dynamic_cast<Medico*>(listaMedicos[endereco]);
                medico->listaAtributos();

                cout << "\nDeseja realmente excluir o registro? (S/N): ";
                cin >> confirmaExclusao;

                if (confirmaExclusao == "S") {

                    // Verificando se paciente não possui consultas
                    bool isConsultaAtiva = Consulta::isMedicoPossuiConsulta(
                        indiceConsultas,
                        listaConsultas,
                        contadorConsultas,
                        codigoPesquisa
                    );

                    if (isConsultaAtiva) {

                        cout << "\nNão é possível excluir um MÉDICO com CONSULTA ativa\n";
                        return;
                    }

                    listaMedicos[endereco]->setStatus(1);
                    cout << "\nRegistro excluído com SUCESSO!\n";

                    return;
                }

                cout << "\nOperação CANCELADA!\n";
                
            } else {
                
                cout << "\nO código pesquisado não existe\n";
            }
        }

        string getTypeName() const override
        {
            return "Medico";
        }

        Object* createObject() const override
        {
            return new Medico();
        }
};

#endif