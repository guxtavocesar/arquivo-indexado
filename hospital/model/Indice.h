#ifndef INDICE_H
#define INDICE_H

class Indice
{
    private:
        int codigo;
        int endereco;

    public:
        Indice()
        {

        }

        Indice(int codigo, int endereco)
        {
            this->setCodigo(codigo);
            this->setEndereco(endereco);
        }

        void setCodigo(int codigo)
        {
            this->codigo = codigo;
        }

        int getCodigo()
        {
            return this->codigo;
        }

        void setEndereco(int endereco)
        {
            this->endereco = endereco;
        }

        int getEndereco()
        {
            return this->endereco;
        }
};

#endif