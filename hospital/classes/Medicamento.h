#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

class Medicamento : public Object
{
    public:
        string descricao;
        int quantidadeEstoque;
        int estoqueMinimo;
        int estoqueMaximo;
        float precoUnitario;

        Medicamento()
        {
            Object::setCodigo(0);
            Object::setStatus(0);
            this->descricao = "";
            this->quantidadeEstoque = 0;
            this->estoqueMaximo = 0;
            this->estoqueMinimo = 0;
            this->precoUnitario = 0.0;
        }

        void listarAtributos()
        {
            cout << "\nLISTANDO MEDICAMENTO\n" << endl;
            cout << "CÓDIGO          : " << Object::getCodigo() << endl;
            cout << "DESCRIÇÃO       : " << this->descricao << endl;
            cout << "QTDE. ESTOQUE   : " << this->quantidadeEstoque << endl;
            cout << "ESTOQUE MÁX.    : " << this->estoqueMaximo << endl;
            cout << "ESTOQUE MIN.    : " << this->estoqueMinimo << endl;
            cout << "PREÇO UN.       : R$ " << this->precoUnitario << endl;
        }

        void leitura(
            Indice* indiceMedicamentos[],
            Object* listaMedicamentos[],
            int contador
        )
		{
            int codigo;
            string descricao;

            int quantidadeEstoque = 0;
            int estoqueMinimo = 0;
            int estoqueMaximo = 0;

            float precoUnitario;

            bool result;

			cout << "\nLEITURA DO MEDICAMENTO\n" << endl;

            do {

                cout << "Informe o CÓDIGO        : ";
                cin >> codigo;
                cin.ignore();

                result = Utils::isCodigoDuplicado(
                    indiceMedicamentos,
                    listaMedicamentos,
                    contador,
                    codigo
                );
           
            } while (result);

            cout << "\nInforme a DESCRIÇÃO     : ";
            getline(cin, descricao);

            cout << "Informe o ESTOQUE MÁX.  : ";
            cin >> estoqueMaximo;

            do {

                if (estoqueMinimo > estoqueMaximo) 
                    cout << "\nO ESTOQUE MÍN. NÃO PODE SER MAIOR QUE O ESTOQUE MÁX.\n" << endl;
            
                cout << "\nInforme o ESTOQUE MÍN.  : ";
                cin >> estoqueMinimo;

            } while (estoqueMinimo > estoqueMaximo);

            cout << "Informe a QTDE. ESTOQUE : ";
            cin >> quantidadeEstoque;

            cout << "Informe o PREÇO UN.     : ";
            cin >> precoUnitario;

            Object::setCodigo(codigo);
            this->descricao = descricao;

            this->quantidadeEstoque = quantidadeEstoque;

            this->estoqueMaximo = estoqueMaximo;
            this->estoqueMinimo = estoqueMinimo;
            this->precoUnitario = precoUnitario;
		}

        static void listarMedicamentoEstoque(
            Indice* indiceMedicamentos[],
            Object* listaMedicamentos[],
            int contadorMedicamentos
        )
        {
            cout << "\nConsulta de Estoque - MEDICAMENTO\n";

            int codigoPesquisa;

            cout << "\nDigite o código do MEDICAMENTO: ";
            cin >> codigoPesquisa;

            int endereco = Operations::binarySearch(
                indiceMedicamentos,
                listaMedicamentos,
                contadorMedicamentos,
                codigoPesquisa
            );

            if (endereco != -1) {

                cout << "\nResultados da consulta de " << listaMedicamentos[0]->getTypeName() << "!\n";
                listaMedicamentos[endereco]->listarAtributos();

                Medicamento* medicamento = dynamic_cast<Medicamento*>(listaMedicamentos[endereco]);

                // Exibindo valor do estoque atual
                int valorEstoque = medicamento->quantidadeEstoque * medicamento->precoUnitario;

                cout << "VALOR DO ESTOQ. : R$ " << valorEstoque << endl;
                return;
            }

            cout << "\nSem resultados para a consulta de " << listaMedicamentos[0]->getTypeName() << "!\n"; 
        }

        static void listarMedicamentoAbaixoEstoqueMin(
            Indice* indiceMedicamentos[],
            Medicamento* listaMedicamentos[],
            int contadorMedicamentos
        )
        {
            cout << "\nRELATÓRIO DE MEDICAMENTOS ABAIXO DO ESTOQUE MÍNIMO\n";

            int contadorListagem = 0;
            int endereco;

            // Variaveis de controle de verificação do estoque
            bool isAbaixoEstoqueMin;

            int quantidadeEstoqueAtual;
            int estoqueMinimo;
            int estoqueMaximo;

            float precoUnitario;

            float valorCompraMedicamento;
            int quantidadeCompra;

            float valorTotalCompra;

            for (int i = 0; i < contadorMedicamentos; i++) {

                endereco = indiceMedicamentos[i]->getEndereco();

                quantidadeEstoqueAtual = listaMedicamentos[endereco]->quantidadeEstoque;
                
                estoqueMinimo = listaMedicamentos[endereco]->estoqueMinimo;
                estoqueMaximo = listaMedicamentos[endereco]->estoqueMaximo;
                precoUnitario = listaMedicamentos[endereco]->precoUnitario;

                isAbaixoEstoqueMin = (quantidadeEstoqueAtual < estoqueMinimo);

                // Verificando STATUS do Objeto (se foi excluído ou não)
                if (listaMedicamentos[endereco]->getStatus() == 1 || !isAbaixoEstoqueMin) continue;

                listaMedicamentos[endereco]->listarAtributos();

                // Listando valor de compra para o produto
                quantidadeCompra = estoqueMaximo - quantidadeEstoqueAtual;
                cout << "\nQUANTIDADE A SER COMPRADA : " << quantidadeCompra << endl;

                valorCompraMedicamento = quantidadeCompra * listaMedicamentos[endereco]->precoUnitario;
                cout << "TOTAL COMPRA DO MEDICAMENTO : R$ " << valorCompraMedicamento << endl;

                // Atualizando valor total da compra
                valorTotalCompra += valorCompraMedicamento;

                contadorListagem++;
            }

            if (contadorListagem == 0) {
                cout << "\nSem resultados de " << listaMedicamentos[0]->getTypeName() << "\n";
                return;
            }

            // Exibindo valor total da compra
            cout << "\nVALOR TOTAL DA COMPRA       : R$ " << valorTotalCompra << endl;
        }

        string getTypeName() const override
        {
            return "Medicamento";
        }

        Object* createObject() const override
        {
            return new Medicamento();
        }
};

#endif
