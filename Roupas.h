//Autores: Anna Livia e Ralf Ferreira
//Professores: Marcelo Iury e Derzu Omaia
//Data de Entrega: 08 de maio de 2023

#pragma once
#include "Produto.h"

class Roupas : public Produto{
    private:
        string tamanho;
        string cor;
        string material;
        string tipo;

    public:
        Roupas();
        virtual ~Roupas();
        Roupas(string nomeProduto, double valorDoProduto, string tamanho, string cor, string material, string tipo);
        string getTamanho();
        string getCor();
        string getMaterial();
        string getTipo();
        void setTamanho(string tamanho);
        void setCor(string cor);
        void setMaterial(string material);
        void setTipo(string tipo);
};