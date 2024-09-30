#ifndef ESPECIALIDADE_H
#define ESPECIALIDADE_H

class Especialidade : public Object
{
    public:
        string descricao;

        Especialidade()
        {
            Object::setCodigo(0);
            Object::setStatus(0);
            this->descricao = "";
        }

        void listarAtributos()
        {
            cout << "\nLISTANDO ESPECIALIDADE\n" << endl;
            cout << "CÓDIGO    : " << Object::getCodigo() << endl;
            cout << "DESCRIÇÃO : " << this->descricao << endl;
        }

        void leitura(
            Indice* indiceEspecialidades[],
            Object* listaEspecialidades[],
            int contador
        )
		{
            int codigo;
            string descricao;

            bool result;

			cout << "\nLEITURA DO ESPECIALIDADE\n" << endl;

            do {
                
                cout << "Informe o CÓDIGO    : ";
                cin >> codigo;
                cin.ignore(); 

                result = Utils::isCodigoDuplicado(
                    indiceEspecialidades,
                    listaEspecialidades,
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
            return "Especialidade";
        }

        Object* createObject() const override
        {
            return new Especialidade();
        }
};

#endif