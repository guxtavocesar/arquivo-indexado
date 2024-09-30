#ifndef CID_H
#define CID_H

class CID : public Object
{
    public:
        string descricao;

        CID()
        {
            Object::setCodigo(0);
            Object::setStatus(0);
            this->descricao = "";
        }

        void listarAtributos()
        {
            cout << "\nLISTANDO CID\n\n";
            cout << "CÓDIGO    : " << Object::getCodigo() << endl;
            cout << "DESCRIÇÃO : " << this->descricao << endl;
        }

        void leitura(
            Indice* indiceCIDs[],
            Object* listaCIDs[],
            int contador
        )
		{
            int codigo;
            string descricao;

            bool result;

			cout << "\nLEITURA DO CID\n" << endl;

            do {
                
                cout << "Informe o CÓDIGO    : ";
                cin >> codigo;
                cin.ignore();

                result = Utils::isCodigoDuplicado(
                    indiceCIDs,
                    listaCIDs,
                    contador,
                    codigo
                );
            
            } while (result);

            cout << "\nInforme a DESCRIÇÃO : ";
            getline(cin, descricao);

            Object::setCodigo(codigo);
            this->descricao = descricao;
		}

        string getTypeName() const override
        {
            return "CID";
        }

        Object* createObject() const override
        {
            return new CID();
        }
};

#endif
