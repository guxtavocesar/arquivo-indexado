#ifndef CIDADE_H
#define CIDADE_H

class Cidade : public Object
{
    public:
        string nome;
        string uf;

        Cidade()
        {
            Object::setCodigo(0);
            Object::setStatus(0);
            this->nome = "";
            this->uf = "";
        }

        void listarAtributos() override
        {
            cout << "\nLISTANDO CIDADE\n" << endl;
            cout << "CÓDIGO : " << Object::getCodigo() << endl;
            cout << "NOME   : " << this->nome << endl;
            cout << "UF     : " << this->uf << endl;
        }

        void leitura(
            Indice* indiceCidade[],
            Object* listaCidade[],
            int contador
        )
        {
            int codigo;
            string nome;
            string uf;

            bool result;

            cout << "\nLEITURA DA CIDADE\n" << endl;

            do {
                
                cout << "Informe o CÓDIGO : ";
                cin >> codigo;
                cin.ignore();

                result = Utils::isCodigoDuplicado(
                    indiceCidade,
                    listaCidade,
                    contador,
                    codigo
                );
            
            } while (result);

            cout << "\nInforme o NOME   : ";
            getline(cin, nome);

            cout << "Informe o UF     : ";
            getline(cin, uf);

            Object::setCodigo(codigo);
            this->nome = nome;
            this->uf = uf;
        }

        string getTypeName() const override
        {
            return "Cidade";
        }

        Object* createObject() const override
        {
            return new Cidade();
        }
};

#endif