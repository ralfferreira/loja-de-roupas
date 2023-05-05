//Autores: Anna Livia e Ralf Ferreira
//Professores: Marcelo Iury e Derzu Omaia
//Data de Entrega: 08 de maio de 2023

#pragma once
#include "Produto.h"

class Acessorios : public Produto{
    private:
        string tamanho;
        string cor;
        string tipo;
    
    public:
        Acessorios();
        virtual ~Acessorios();
        Acessorios(string nomeProduto, double valorDoProduto, string tamanho, string cor, string tipo);
        string getTamanho();
        string getCor();
        string getTipo();
        void setTamanho(string tamanho);
        void setCor(string cor);
        void setTipo(string tipo);
};