#ifndef PACIENTE_H
#define PACIENTE_H

#include "Consulta.h"

class Paciente: public Object
{
	public:
		string nome;
		string endereco;
		int codigoCidade;

		Paciente()
		{
			Object::setCodigo(0);
			Object::setStatus(0);
			this->nome = "";
			this->endereco = "";
			this->codigoCidade = 0;	
		}

		Paciente(int codigo, string nome, int codigoCidade, int status)
		{
			// Atributos da classe Object
			Object::setCodigo(codigo);
			Object::setStatus(status);
			
			// Atributos específicos da classe		
			this->nome = nome;
			this->endereco = endereco;
			this->codigoCidade = codigoCidade;	
		}

        void listaAtributos()
        {
            cout << "\nLISTANDO PACIENTE\n" << endl;
            cout << "CÓDIGO   : " << Object::getCodigo() << endl;
            cout << "NOME     : " << this->nome << endl;
            cout << "ENDERECO : " << this->endereco << endl;
        }

		void listarAtributos(
            Indice* indiceCidades[],
            Object* listaCidades[],
            int contadorCidades
        )
		{
			cout << "\nLISTANDO PACIENTE\n" << endl;
            cout << "CÓDIGO   : " << Object::getCodigo() << endl;
            cout << "NOME     : " << this->nome << endl;
            cout << "ENDERECO : " << this->endereco << endl;

            // Recuperando endereco da especialidade
            int enderecoCidade = Operations::binarySearch(
                indiceCidades,
                listaCidades, 
                contadorCidades,
                this->codigoCidade
            );

            // Listando atributos da especialidade do médico
            listaCidades[enderecoCidade]->listarAtributos();
		}

		void leitura(
			Indice* indicePacientes[],
			Object* listaPacientes[],
			int contadorPacientes,

			Indice* indiceCidades[],
			Object* listaCidades[],
			int contadorCidades
		)
		{
			int codigo;
            string nome;
            string endereco;
            int codigoCidade;

			bool resultPaciente;
            bool resultCidade;

			cout << "\nLEITURA DE PACIENTE\n" << endl;

            do {

                cout << "Informe o CÓDIGO   : ";
                cin >> codigo;
                cin.ignore();

                resultPaciente = Utils::isCodigoDuplicado(
                    indicePacientes,
                    listaPacientes,
                    contadorPacientes,
                    codigo
                );
           
            } while (resultPaciente);

            cout << "\nInforme o NOME     : ";
            getline(cin, nome);

            cout << "Informe o ENDEREÇO : ";
            getline(cin, endereco);

            do {

                cout << "\nInforme o CÓDIGO DA CIDADE : ";
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
            this->codigoCidade = codigoCidade;
		}

        static void excluir(
            Indice* indicePacientes[],
            Object* listaPacientes[],
            int contadorPacientes,

            Indice* indiceConsultas[],
            Consulta* listaConsultas[],
            int contadorConsultas
        )
        {
            int codigoPesquisa = 0;

            cout << "\nEXCLUSÃO DE PACIENTE\n";

            cout << "\nDigite o codigo a ser excluido: ";
            cin >> codigoPesquisa;

            int endereco = Operations::binarySearch(
                indicePacientes,
                listaPacientes,
                contadorPacientes,
                codigoPesquisa
            );

            if (endereco != - 1) {

                string confirmaExclusao;

                Paciente* paciente = dynamic_cast<Paciente*>(listaPacientes[endereco]);
                paciente->listaAtributos();

                cout << "\nDeseja realmente excluir o registro? (S/N): ";
                cin >> confirmaExclusao;

                if (confirmaExclusao == "S") {

                    // Verificando se paciente não possui consultas
                    bool isConsultaAtiva = Consulta::isPacientePossuiConsulta(
                        indiceConsultas,
                        listaConsultas,
                        contadorConsultas,
                        codigoPesquisa
                    );

                    if (isConsultaAtiva) {

                        cout << "\nNão é possível excluir um PACIENTE com CONSULTA ativa\n";
                        return;
                    }

                    listaPacientes[endereco]->setStatus(1);
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
			return "Paciente";
		}

		Object* createObject() const override
        {
            return new Paciente();
        }
};

#endif