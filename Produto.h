//Autores: Anna Livia e Ralf Ferreira
//Professores: Marcelo Iury e Derzu Omaia
//Data de Entrega: 05 de maio de 2023 

#include <iostream>
#include <string>
#pragma once

using namespace std;

class Produto{
    protected:
        string nomeProduto;
        double valorDoProduto;

    public:
        Produto();
        virtual ~Produto();
        Produto(string nomeProduto, double valorDoProduto);
        string getNomeProduto();
        double getValorDoProduto();
        void setNomeProduto(string nomeProduto);
        void setValorDoProduto(double valorDoProduto);
        bool verificarEstoque();
};