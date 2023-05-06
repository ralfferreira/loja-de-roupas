// Autores: Anna Livia e Ralf Ferreira
// Professores: Marcelo Iury e Derzu Omaia
// Data de Entrega: 08 de maio de 2023

#pragma once
#include "Produto.h"

class Calcados : public Produto {
private:
public:
  Calcados();
  virtual ~Calcados();
  Calcados(string nomeProduto, double valorDoProduto, int idProduto,
           int quantidadeDisponivel, string tamanhoProduto, string corProduto,
           string tipoProduto, string subTipoProduto);
};