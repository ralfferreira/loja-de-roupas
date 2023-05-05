//Autores: Anna Livia e Ralf Ferreira
//Professores: Marcelo Iury e Derzu Omaia
//Data de Entrega: 08 de maio de 2023

#pragma once
#include "Produto.h"

class Calcados : public Produto{
    private:
        int tamanhoCalcado;
        string cor;
        string tipo;

    public:
        Calcados();
        virtual ~Calcados();
        Calcados(string nomeProduto, double valorDoProduto, int tamanhoCalcado, string cor, string tipo);
        int getTamanho();
        string getCor();
        string getTipo();
        void setTamanho(int tamanhoCalcado);
        void setCor(string cor);
        void setTipo(string tipo);
};