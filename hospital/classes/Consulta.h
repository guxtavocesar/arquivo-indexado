#ifndef CONSULTA_H
#define CONSULTA_H

class Consulta : public Object
{
    private:
        int codigoPaciente;
        int codigoMedico;

    public:
        string data;
        string horario;

        int codigoCID;
        int codigoMedicamento;
        int quantidadeMedicamento;

        Consulta()
        {
            Object::setCodigo(0);
            Object::setStatus(0);
            this->codigoPaciente = 0;
            this->codigoMedico = 0;

            this->data = "";
            this->horario = "";

            this->codigoCID = 0;
            this->codigoMedicamento = 0;

            this->quantidadeMedicamento = 0;
        }

        void listarAtributos(
            Indice* indicePacientes[],
            Object* listaPacientes[],
            int contadorPacientes,

            Indice* indiceCidades[],
            Object* listaCidades[],
            int contadorCidades,

            Indice* indiceMedicos[],
            Object* listaMedicos[],
            int contadorMedicos,

            Indice* indiceEspecialidades[],
            Object* listaEspecialidades[],
            int contadorEspecialidades,

            Indice* indiceCIDs[],
            Object* listaCIDs[],
            int contadorCIDs,
            
            Indice* indiceMedicamentos[],
            Object* listaMedicamentos[],
            int contadorMedicamentos
        )
        {
            cout << "\nLISTANDO CONSULTA\n" << endl;
            cout << "CÓDIGO     : " << Object::getCodigo() << endl;
            cout << "HORÁRIO    : " << this->horario << endl;
            cout << "DATA       : " << this->data << endl;

            // Recuperando endereco
            int enderecoPaciente = Operations::binarySearch(
                indicePacientes,
                listaPacientes, 
                contadorPacientes,
                this->codigoPaciente
            );

            // Listando atributos do PACIENTE
            listaPacientes[enderecoPaciente]->listarAtributos(
                indiceCidades,
                listaCidades,
                contadorCidades
            );

            // Recuperando endereco
            int enderecoMedico = Operations::binarySearch(
                indiceMedicos,
                listaMedicos, 
                contadorMedicos,
                this->codigoMedico
            );
            
            // Listando atributos do MÉDICO
            listaMedicos[enderecoMedico]->listarAtributos(
                indiceEspecialidades,
                listaEspecialidades,
                contadorEspecialidades,
                
                indiceCidades,
                listaCidades,
                contadorCidades
            );

            // Recuperando endereco
            int enderecoCID = Operations::binarySearch(
                indiceCIDs,
                listaCIDs, 
                contadorCIDs,
                this->codigoCID
            );

            // Listando atributos do CID
            listaCIDs[enderecoCID]->listarAtributos();

            // Recuperando endereco
            int enderecoMedicamento = Operations::binarySearch(
                indiceMedicamentos,
                listaMedicamentos, 
                contadorMedicamentos,
                this->codigoMedicamento
            );

            // Listando atributos do MEDICAMENTO
            listaMedicamentos[enderecoMedicamento]->listarAtributos();

            cout << "\nQTDE. MED. CONSULTA : " << this->quantidadeMedicamento << endl;
        }

        void leitura(
            Indice* indiceConsultas[],
            Object* listaConsultas[],
            int contadorConsultas,

            Indice* indicePacientes[],
            Object* listaPacientes[],
            int contadorPacientes,

            Indice* indiceCidades[],
            Object* listaCidades[],
            int contadorCidades,

            Indice* indiceMedicos[],
            Object* listaMedicos[],
            int contadorMedicos,

            Indice* indiceEspecialidades[],
            Object* listaEspecialidades[],
            int contadorEspecialidades,

            Indice* indiceCIDs[],
            Object* listaCIDs[],
            int contadorCIDs,
            
            Indice* indiceMedicamentos[],
            Object* listaMedicamentos[],
            int contadorMedicamentos
        )
		{
            int codigo;

            string data;
            string horario;
            int quantidadeMedicamento;

            int codigoMedico;
            int codigoPaciente;
            int codigoMedicamento;
            int codigoCID;

            bool resultConsulta;
            bool resultMedico;
            bool resultPaciente;
            bool resultMedicamento;
            bool resultCID;

			cout << "\nAGENDAR CONSULTA\n" << endl;

            do {

                cout << "Informe o CÓDIGO   : ";
                cin >> codigo;
                cin.ignore();

                resultConsulta = Utils::isCodigoDuplicado(
                    indiceConsultas,
                    listaConsultas,
                    contadorConsultas,
                    codigo
                );
           
            } while (resultConsulta);

            cout << "\nInforme a DATA (D/M/Y)  : ";
            getline(cin, data);

            cout << "Informe o HORÁRIO (H:M) : ";
            getline(cin, horario);

            do {

                cout << "\nInforme o CÓDIGO DO PACIENTE    : ";
                cin >> codigoPaciente;

                resultPaciente = Utils::isCodigoExist(
                    indicePacientes,
                    listaPacientes,
                    contadorPacientes,
                    codigoPaciente
                );

            } while (!resultPaciente);

            // Recuperando endereco
            int enderecoPaciente = Operations::binarySearch(
                indicePacientes,
                listaPacientes, 
                contadorPacientes,
                codigoPaciente
            );

            // Listando atributos de PACIENTE
            listaPacientes[enderecoPaciente]->listarAtributos(
                indiceCidades,
                listaCidades,
                contadorCidades
            );

            do {

                cout << "\nInforme o CÓDIGO DO MÉDICO      : ";
                cin >> codigoMedico;

                cout << codigoMedico;

                resultMedico = Utils::isCodigoExist(
                    indiceMedicos,
                    listaMedicos,
                    contadorMedicos,
                    codigoMedico
                );

            } while (!resultMedico);

            // Recuperando endereco
            int enderecoMedico = Operations::binarySearch(
                indiceMedicos,
                listaMedicos,
                contadorMedicos,
                codigoMedico
            );

            // Listando atributos de MÉDICO
            listaMedicos[enderecoMedico]->listarAtributos(
                indiceEspecialidades,
                listaEspecialidades,
                contadorEspecialidades,
                
                indiceCidades,
                listaCidades,
                contadorCidades
            );

            do {

                cout << "\nInforme o CÓDIGO CID            : ";
                cin >> codigoCID;

                resultCID = Utils::isCodigoExist(
                    indiceCIDs,
                    listaCIDs,
                    contadorCIDs,
                    codigoCID
                );

            } while (!resultCID);

            // Recuperando endereco
            int enderecoCID = Operations::binarySearch(
                indiceCIDs,
                listaCIDs,
                contadorCIDs,
                codigoCID
            );

            // Listando atributos da CID
            listaCIDs[enderecoCID]->listarAtributos();

            do {

                cout << "\nInforme o CÓDIGO DO MEDICAMENTO : ";
                cin >> codigoMedicamento;

                resultMedicamento = Utils::isCodigoExist(
                    indiceMedicamentos,
                    reinterpret_cast<Object**>(listaMedicamentos),
                    contadorMedicamentos,
                    codigoMedicamento
                );

            } while (!resultMedicamento);

            // Recuperando endereco
            int enderecoMedicamento = Operations::binarySearch(
                indiceMedicamentos,
                reinterpret_cast<Object**>(listaMedicamentos),
                contadorMedicamentos,
                codigoMedicamento
            );

            // Listando atributos de MÉDICO
            listaMedicamentos[enderecoMedicamento]->listarAtributos();

            // Leitura da quantidade do medicamento
            bool isQuantidadeInsuficiente;

            Medicamento* medicamento = dynamic_cast<Medicamento*>(listaMedicamentos[enderecoMedicamento]);

            do {

                if (isQuantidadeInsuficiente) 
                    cout << "\nA QUANTIDADE do MEDICAMENTO não pode ser maior que o ESTOQUE ATUAL!\n";

                cout << "\nInforme a QTDE. DO MEDICAMENTO  : ";
                cin >> quantidadeMedicamento;

                isQuantidadeInsuficiente = quantidadeMedicamento > medicamento->quantidadeEstoque;

            } while (isQuantidadeInsuficiente);

            Object::setCodigo(codigo);
            this->data = data;
            this->horario = horario;

            this->codigoPaciente = codigoPaciente;
            this->codigoMedico = codigoMedico;
            this->codigoCID = codigoCID;
            this->codigoMedicamento = codigoMedicamento;
            
            this->quantidadeMedicamento = quantidadeMedicamento;

            // Atualizando estoque do medicamento
            medicamento->quantidadeEstoque -= quantidadeMedicamento;
		}

        static void consultarValorTotalConsultas(
            Indice* indiceConsultas[],
            Consulta* listaConsultas[],
            int contadorConsultas,

            Indice* indiceMedicamentos[],
            Object* listaMedicamentos[],
            int contadorMedicamentos
        )
        {
            int contadorListagem = 0;

            int enderecoConsulta;
            int enderecoMedicamento;

            float precoUnitarioMedicamento;
            int quantidadeMedicamentoConsulta;

            float valorTotalMedicamento;

            float valorTotalConsultas = 0.0;

            for (int i = 0; i < contadorConsultas; i++) {

                enderecoConsulta = indiceConsultas[i]->getEndereco();

                // Verificando STATUS do Objeto (se foi excluído ou não)
                if (listaConsultas[enderecoConsulta]->getStatus() == 1) continue;

                // Recuperando endereco do medicamento
                enderecoMedicamento = Operations::binarySearch(
                    indiceMedicamentos,
                    listaMedicamentos,
                    contadorMedicamentos,
                    listaConsultas[enderecoConsulta]->codigoMedicamento
                );

                Medicamento* medicamento = dynamic_cast<Medicamento*>(listaMedicamentos[enderecoMedicamento]);

                precoUnitarioMedicamento = medicamento->precoUnitario;
                quantidadeMedicamentoConsulta = listaConsultas[enderecoConsulta]->quantidadeMedicamento;

                valorTotalMedicamento = precoUnitarioMedicamento * quantidadeMedicamentoConsulta;

                valorTotalConsultas += valorTotalMedicamento + 100.00;

                contadorListagem++;
            }

            if (contadorListagem == 0) {
                cout << "\nSem resultados de " << listaConsultas[0]->getTypeName() << "\n";
                return;
            }

            // Exibindo valor total da compra
            cout << "\nVALOR TOTAL ARRECADADO PELAS CONSULTAS : R$ " << valorTotalConsultas << endl;
        }

        static bool isPacientePossuiConsulta(
            Indice* indiceConsultas[],
            Consulta* listaConsultas[],
            int contadorConsultas,
            int codigoPaciente
        )
        {
            int status;
            int endereco;

            for (int i = 0; i < contadorConsultas; i++) {

                endereco = indiceConsultas[i]->getEndereco();
                status = listaConsultas[endereco]->getStatus();

                if (status == 0 && listaConsultas[endereco]->codigoPaciente == codigoPaciente) return true;
            }

            return false;
        }

        static bool isMedicoPossuiConsulta(
            Indice* indiceConsultas[],
            Consulta* listaConsultas[],
            int contadorConsultas,
            int codigoMedico
        )
        {
            int status;
            int endereco;

            for (int i = 0; i < contadorConsultas; i++) {

                endereco = indiceConsultas[i]->getEndereco();
                status = listaConsultas[endereco]->getStatus();

                if (status == 0 && listaConsultas[endereco]->codigoMedico == codigoMedico) return true;
            }

            return false;
        }

        string getTypeName() const override 
		{
			return "Consulta";
		}

		Object* createObject() const override
        {
            return new Consulta();
        }
};

#endif