#ifndef UTILS_H
#define UTILS_H

class Utils
{
    public:
        static void clearConsole()
        {
            string opcao;

            cout << "\nDeseja limpar o console? (S/N): ";
            cin >> opcao;

            if (opcao == "S") system("cls");
        }

        static bool isCodigoDuplicado(
            Indice* indices[],
            Object* listaDados[],
            int contador,
            int codigo
        )
        {
            int result = Operations::binarySearch(
                indices,
                listaDados,
                contador,
                codigo
            );

            if (result != -1) {
                
                cout << "\nO CÓDIGO JÁ EXISTE, INFORME UM CÓDIGO VÁLIDO!\n\n";
                return true;
            } 

            return false;
        }

        static bool isCodigoExist(
            Indice* indices[],
            Object* listaDados[],
            int contador,
            int codigo
        )
        {
            int result = Operations::binarySearch(
                indices,
                listaDados,
                contador,
                codigo
            );

            if (result != -1) return true;
            
            cout << "\nO CÓDIGO DIGITADO NÃO EXISTE, INFORME UMA CÓDIGO VÁLIDO!\n\n";
            return false;
        }
};

#endif