// Autores: Anna Livia e Ralf Ferreira
// Professores: Marcelo Iury e Derzu Omaia
// Data de Entrega: 08 de maio de 2023

#include "Calcados.h"

Calcados::Calcados() : Produto() {}

Calcados::Calcados(string nomeProduto, double valorDoProduto, int idProduto,
                   int quantidadeDisponivel, string tamanhoProduto,
                   string corProduto, string tipoProduto, string subTipoProduto)
    : Produto(nomeProduto, valorDoProduto, idProduto, quantidadeDisponivel,
              tamanhoProduto, corProduto, "Calcados", subTipoProduto) {}

Calcados::~Calcados() {}