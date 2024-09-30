#ifndef OPERATIONS_H
#define OPERATIONS_H

class Operations 
{
    public:
        static void read(
            Indice* indices[],
            Object* listaDados[],
            int &contador
        )
        {
            string controleLeitura = "S";

            // Fazendo leitura dinâmica da lista de objetos
            for (int i = contador; i < T ; i++) {

                listaDados[i] = listaDados[0]->createObject();

                listaDados[i]->leitura(indices, listaDados, contador);

                Operations::create(indices, listaDados, contador);
                contador++;

                cout << "\nDeseja continuar a leitura? (S/N): ";
                cin >> controleLeitura;

                if (controleLeitura == "N")break ;
            }
        }

        static void read(
            Indice* indices[],
            Object* listaDados[],
            int &contador,

            Indice* indicesSecond[],
            Object* listaDadosSecond[],
            int &contadorSecond
        )
        {
            // Validações antes de iniciar a leitura
            if (listaDadosSecond[0]->getCodigo() == 0) {
                cout << "\nPara cadastrar "
                     << listaDados[0]->getTypeName()
                     << " primeiro cadastre " << listaDadosSecond[0]->getTypeName() <<"!\n";
                return;
            } 

            string controleLeitura = "S";

            // Fazendo leitura dinâmica da lista de objetos
            for (int i = contador; i < T ; i++) {

                listaDados[i] = listaDados[0]->createObject();

                listaDados[i]->leitura(
                    indices,
                    listaDados,
                    contador,
                    indicesSecond,
                    listaDadosSecond,
                    contadorSecond
                );

                Operations::create(indices, listaDados, contador);
                contador++;

                cout << "\nDeseja continuar a leitura? (S/N): ";
                cin >> controleLeitura;

                if (controleLeitura == "N") break ;
            }
        }

        static void read(
            Indice* indices[],
            Object* listaDados[],
            int &contador,

            Indice* indicesSecond[],
            Object* listaDadosSecond[],
            int &contadorSecond,

            Indice* indicesThird[],
            Object* listaDadosThird[],
            int &contadorThird
        )
        {
            // Validações antes de iniciar a leitura
            if (listaDadosSecond[0]->getCodigo() == 0) {
                cout << "\nPara cadastrar "
                     << listaDados[0]->getTypeName()
                     << " primeiro cadastre " << listaDadosSecond[0]->getTypeName()
                     <<"!\n";
                return;
            } else if (listaDadosThird[0]->getCodigo() == 0) {
                cout << "\nPara cadastrar "
                     << listaDados[0]->getTypeName()
                     << " primeiro cadastre " << listaDadosThird[0]->getTypeName()
                     <<"!\n";
                return;
            }

            string controleLeitura = "S";

            // Fazendo leitura dinâmica da lista de objetos
            for (int i = contador; i < T ; i++) {

                listaDados[i] = listaDados[0]->createObject();

                listaDados[i]->leitura(
                    indices,
                    listaDados,
                    contador,

                    indicesSecond,
                    listaDadosSecond,
                    contadorSecond,
                    
                    indicesThird,
                    listaDadosThird,
                    contadorThird
                );

                Operations::create(indices, listaDados, contador);
                contador++;

                cout << "\nDeseja continuar a leitura? (S/N): ";
                cin >> controleLeitura;

                if (controleLeitura == "N") break ;
            }
        }

        static void read(
            Indice* indices[],
            Object* listaDados[],
            int &contador,

            Indice* indicesSecond[],
            Object* listaDadosSecond[],
            int &contadorSecond,

            Indice* indicesThird[],
            Object* listaDadosThird[],
            int &contadorThird,

            Indice* indicesFourth[],
            Object* listaDadosFourth[],
            int &contadorFourth,

            Indice* indicesFifth[],
            Object* listaDadosFifth[],
            int &contadorFifth,

            Indice* indicesSixth[],
            Object* listaDadosSixth[],
            int &contadorSixth,

            Indice* indicesSeventh[],
            Object* listaDadosSeventh[],
            int contadorSeventh
        )
        {
            // Validações antes de iniciar a leitura
            if (listaDadosSecond[0]->getCodigo() == 0) {

                cout << "\nPara cadastrar "
                     << listaDados[0]->getTypeName()
                     << " primeiro cadastre " << listaDadosSecond[0]->getTypeName()
                     <<"!\n";
                return;

            } else if (listaDadosThird[0]->getCodigo() == 0) {

                cout << "\nPara cadastrar "
                     << listaDados[0]->getTypeName()
                     << " primeiro cadastre " << listaDadosThird[0]->getTypeName()
                     <<"!\n";
                return;

            } else if (listaDadosFourth[0]->getCodigo() == 0) {

                cout << "\nPara cadastrar "
                     << listaDados[0]->getTypeName()
                     << " primeiro cadastre " << listaDadosFourth[0]->getTypeName()
                     <<"!\n";
                return;

            } else if (listaDadosFifth[0]->getCodigo() == 0) {

                cout << "\nPara cadastrar "
                     << listaDados[0]->getTypeName()
                     << " primeiro cadastre " << listaDadosFifth[0]->getTypeName()
                     <<"!\n";
                return;

            } else if (listaDadosSixth[0]->getCodigo() == 0) {

                cout << "\nPara cadastrar "
                     << listaDados[0]->getTypeName()
                     << " primeiro cadastre " << listaDadosSixth[0]->getTypeName()
                     <<"!\n";
                return;
            } 

            string controleLeitura = "S";

            // Fazendo leitura dinâmica da lista de objetos
            for (int i = contador; i < T ; i++) {

                listaDados[i] = listaDados[0]->createObject();

                listaDados[i]->leitura(
                    indices,
                    listaDados,
                    contador,

                    indicesSecond,
                    listaDadosSecond,
                    contadorSecond,

                    indicesThird,
                    listaDadosThird,
                    contadorThird,

                    indicesFourth,
                    listaDadosFourth,
                    contadorFourth,

                    indicesFifth,
                    listaDadosFifth,
                    contadorFifth,

                    indicesSixth,
                    listaDadosSixth,
                    contadorSixth,

                    indicesSeventh,
                    listaDadosSeventh,
                    contadorSeventh
                );

                Operations::create(indices, listaDados, contador);
                contador++;

                cout << "\nDeseja continuar a leitura? (S/N): ";
                cin >> controleLeitura;

                if (controleLeitura == "N") break ;
            }
        }

        static void create(
            Indice* indices[],
            Object* listaDados[],
            int contador
        )
        {
            indices[contador] = new Indice();

            // Primeira inclusão
            if (contador == 0) {
                indices[0]->setCodigo(listaDados[0]->Object::getCodigo());
                indices[0]->setEndereco(0);
                return;
            }

            int i;

            for (i = contador - 1; i > 0 && indices[i]->getCodigo() > listaDados[contador]->Object::getCodigo(); i--) {
                indices[i + 1] = indices[i];
            }

            indices[i + 1] = new Indice();
            indices[i + 1]->setCodigo(listaDados[contador]->Object::getCodigo());
            indices[i + 1]->setEndereco(contador);
        }

        static void list(
            Indice* indices[],
            Object* listaDados[],
            int contador
        )
        {
            int contadorListagem = 0;

            for (int i = 0; i < contador; i++) {

                // Verificando STATUS do Objeto (se foi excluído ou não)
                if (listaDados[indices[i]->getEndereco()]->getStatus() == 1) continue;

                listaDados[indices[i]->getEndereco()]->listarAtributos();
                contadorListagem++;
            }

            if (contadorListagem == 0) cout << "\nSem resultados de " << listaDados[0]->getTypeName() << "\n";
        }

        static void list(
            Indice* indices[],
            Object* listaDados[],
            int &contador,

            Indice* indicesSecond[],
            Object* listaDadosSecond[],
            int &contadorSecond
        )
        {
            int contadorListagem = 0;

            for (int i = 0; i < contador; i++) {

                // Verificando STATUS do Objeto (se foi excluído ou não)
                if (listaDados[indices[i]->getEndereco()]->getStatus() == 1) continue;

                listaDados[indices[i]->getEndereco()]->listarAtributos(
                    indicesSecond,
                    listaDadosSecond,
                    contadorSecond
                );

                contadorListagem++;
            }

            if (contadorListagem == 0) cout << "\nSem resultados de " << listaDados[0]->getTypeName() << "\n";
        }

        static void list(
            Indice* indices[],
            Object* listaDados[],
            int &contador,

            Indice* indicesSecond[],
            Object* listaDadosSecond[],
            int &contadorSecond,

            Indice* indicesThird[],
            Object* listaDadosThird[],
            int &contadorThird
        )
        {
            int contadorListagem = 0;

            for (int i = 0; i < contador; i++) {

                // Verificando STATUS do Objeto (se foi excluído ou não)
                if (listaDados[indices[i]->getEndereco()]->getStatus() == 1) continue;

                listaDados[indices[i]->getEndereco()]->listarAtributos(
                    indicesSecond,
                    listaDadosSecond,
                    contadorSecond,

                    indicesThird,
                    listaDadosThird,
                    contadorThird
                );

                contadorListagem++;
            }

            if (contadorListagem == 0) cout << "\nSem resultados de " << listaDados[0]->getTypeName() << "\n";
        }

        static void list(
            Indice* indices[],
            Object* listaDados[],
            int &contador,

            Indice* indicesSecond[],
            Object* listaDadosSecond[],
            int &contadorSecond,

            Indice* indicesThird[],
            Object* listaDadosThird[],
            int &contadorThird,

            Indice* indicesFourth[],
            Object* listaDadosFourth[],
            int &contadorFourth,

            Indice* indicesFifth[],
            Object* listaDadosFifth[],
            int &contadorFifth,

            Indice* indicesSixth[],
            Object* listaDadosSixth[],
            int &contadorSixth,

            Indice* indicesSeventh[],
            Object* listaDadosSeventh[],
            int contadorSeventh
        )
        {
            int contadorListagem = 0;

            for (int i = 0; i < contador; i++) {

                // Verificando STATUS do Objeto (se foi excluído ou não)
                if (listaDados[indices[i]->getEndereco()]->getStatus() == 1) continue;

                listaDados[indices[i]->getEndereco()]->listarAtributos(
                    indicesSecond,
                    listaDadosSecond,
                    contadorSecond,

                    indicesThird,
                    listaDadosThird,
                    contadorThird,

                    indicesFourth,
                    listaDadosFourth,
                    contadorFourth,

                    indicesFifth,
                    listaDadosFifth,
                    contadorFifth,

                    indicesSixth,
                    listaDadosSixth,
                    contadorSixth,

                    indicesSeventh,
                    listaDadosSeventh,
                    contadorSeventh
                );

                contadorListagem++;
            }

            if (contadorListagem == 0) cout << "\nSem resultados de " << listaDados[0]->getTypeName() << "\n";
        }

        static void searchInterface(
            Indice* indices[],
            Object* listaDados[],
            int contador
        )
        {
            int codigoPesquisa;

            cout << "\nPesquisa de " << listaDados[0]->getTypeName() << "\n";

            cout << "\nDigite o código a ser pesquisado: ";
            cin >> codigoPesquisa;

            int endereco = Operations::binarySearch(indices, listaDados, contador, codigoPesquisa);

            if (endereco != -1) {

                cout << "\nResultados da pesquisa de " << listaDados[0]->getTypeName() << "!\n";
                listaDados[endereco]->listarAtributos();

                return;
            }

            cout << "\nSem resultados para a pesquisa de " << listaDados[0]->getTypeName() << "!\n";  
        }

        static int binarySearch(
            Indice* indices[],
            Object* listaDados[],
            int contador,
            int codigoPesquisa
        )
        {
            int inicio = 0;
            int final = contador - 1;
            int indice = ((inicio + final) / 2);
            
            while (inicio <= final) {	
                
                if (indices[indice]->getCodigo() == codigoPesquisa) {
                    
                    int status = listaDados[indices[indice]->getEndereco()]->getStatus();

                    if (status == 0) return indices[indice]->getEndereco();

                    return -1;
                }
                
                // Continua a busca binária
                inicio = (codigoPesquisa > indices[indice]->getCodigo()) ? indice + 1 : inicio;
                final  = (codigoPesquisa < indices[indice]->getCodigo()) ? indice - 1 : final;
                
                // Calculando novamento o índice 
                indice = (inicio + final) / 2;
            }
            
            return -1;
        }

        static void rearrangeFile(
            Indice* indices[],
            Object* listaDados[],
            int &contador
        ) {
            Object* listaDadosOrganizada[T];
            Indice* indicesOrganizado[T];
            
            int novoContador = 0;
            int endereco;
            
            for (int i = 0; i < contador; i++) { 
                endereco = indices[i]->getEndereco();
                
                if (listaDados[endereco]->getStatus() == 0) {
                    listaDadosOrganizada[novoContador] = listaDados[endereco];
                    
                    // Garantindo que indicesOrganizado[novoContador] é inicializado
                    indicesOrganizado[novoContador] = new Indice();  // Alocando um novo objeto
                    
                    // Adicionando novo índice
                    indicesOrganizado[novoContador]->setCodigo(listaDadosOrganizada[novoContador]->Object::getCodigo());
                    indicesOrganizado[novoContador]->setEndereco(novoContador);
                    
                    novoContador++;
                }
            }
            
            // Sobreescrevendo valores do vetor principal
            for (int i = 0; i < novoContador; i++) {
                listaDados[i] = listaDadosOrganizada[i];
                indices[i] = indicesOrganizado[i];
            }
            
            contador = novoContador;

            cout << "\nLista de " << listaDados[0]->getTypeName() << " reorganizada com sucesso!" << endl;

            cout << "\nListagem dos códigos - Listagem cansativa sem considerar a exclusão lógica\n\n";

            for (int i = 0; i < contador; i++) {
                
                cout << " | " << indices[i]->getCodigo();
            }

            cout << endl;
        }

};

#endif