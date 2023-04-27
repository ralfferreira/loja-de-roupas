//Autores: Anna Livia e Ralf Ferreira
//Professores: Marcelo Iury e Derzu Omaia
//Data de Entrega: 05 de maio de 2023

#include "Produto.h"

class Roupas : public Produto{
    private:
      string tamanho;
      string cor;
      string material;

    public:
      Roupas();
      Roupas(int ID, string nomeProduto, double valorDoProduto, string tamanho, string cor, string material);
      string getTamanho();
      string getCor();
      string getMaterial();
      void setTamanho(string tamanho);
      void setCor(string cor);
      void setMaterial(string material);
      void MostrarNaTela() override;
};