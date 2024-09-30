#ifndef OBJECT_H
#define OBJECT_H

class Object
{
private:
    int codigo;
    int status;

public:
    void setCodigo(int codigo)
    {
        this->codigo = codigo;
    }

    int getCodigo() const
    {
        return this->codigo;
    }

    void setStatus(int status)
    {
        this->status = status;
    }

    int getStatus() const
    {
        return this->status;
    }

    // Definindo métodos virtuais puros

    virtual Object* createObject() const = 0;
    virtual string getTypeName() const = 0;

    // Definindo métodos com implementação opcional

    virtual void leitura(
        Indice* indices[],
        Object* listaDados[],
        int contador
    )
    {
        
    }

    virtual void leitura(
        Indice* indices[],
        Object* listaDados[],
        int contador,

        Indice* indicesSecond[],
        Object* listaDadosSecond[],
        int contadorSecond
    )
    {
        
    }

    virtual void leitura(
        Indice* indices[],
        Object* listaDados[],
        int contador,

        Indice* indicesSecond[],
        Object* listaDadosSecond[],
        int contadorSecond,

        Indice* indicesThird[],
        Object* listaDadosThird[],
        int contadorThird
    )
    {
        
    }

    virtual void leitura(
        Indice* indices[],
        Object* listaDados[],
        int contador,

        Indice* indicesSecond[],
        Object* listaDadosSecond[],
        int contadorSecond,

        Indice* indicesThird[],
        Object* listaDadosThird[],
        int contadorThird,

        Indice* indicesFourth[],
        Object* listaDadosFourth[],
        int contadorFourth,

        Indice* indicesFifth[],
        Object* listaDadosFifth[],
        int contadorFifth,

        Indice* indicesSixth[],
        Object* listaDadosSixth[],
        int contadorSixth,

        Indice* indicesSeventh[],
        Object* listaDadosSeventh[],
        int contadorSeventh
    )
    {
        
    }
		
    virtual void listarAtributos()
    {

    }

    virtual void listarAtributos(
        Indice* indices[],
        Object* listaDados[],
        int contador
    )
    {

    }
    
    virtual void listarAtributos(
        Indice* indices[],
        Object* listaDados[],
        int contador,

        Indice* indicesSecond[],
        Object* listaDadosSecond[],
        int contadorSecond
    )
    {

    }

    virtual void listarAtributos(
        Indice* indices[],
        Object* listaDados[],
        int contador,

        Indice* indicesSecond[],
        Object* listaDadosSecond[],
        int contadorSecond,

        Indice* indicesThird[],
        Object* listaDadosThird[],
        int contadorThird,

        Indice* indicesFourth[],
        Object* listaDadosFourth[],
        int contadorFourth
    )
    {

    }

    virtual void listarAtributos(
        Indice* indices[],
        Object* listaDados[],
        int contador,

        Indice* indicesSecond[],
        Object* listaDadosSecond[],
        int contadorSecond,

        Indice* indicesThird[],
        Object* listaDadosThird[],
        int contadorThird,

        Indice* indicesFourth[],
        Object* listaDadosFourth[],
        int contadorFourth,

        Indice* indicesFifth[],
        Object* listaDadosFifth[],
        int contadorFifth,

        Indice* indicesSixth[],
        Object* listaDadosSixth[],
        int contadorSixth
    )
    {
        
    }
};

#endif
