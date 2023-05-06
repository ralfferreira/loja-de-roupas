// Autores: Anna Livia e Ralf Ferreira
// Professores: Marcelo Iury e Derzu Omaia
// Data de Entrega: 08 de maio de 2023

#pragma once
#include "Produto.h"

class Roupas : public Produto {
private:
  string material;

public:
  Roupas();
  virtual ~Roupas();
  Roupas(string nomeProduto, double valorDoProduto, int idProduto,
         int quantidadeDisponivel, string tamanhoProduto, string corProduto,
         string material, string tipoProduto, string subTipoProduto);
  string getMaterial();
  void setMaterial(string material);
};