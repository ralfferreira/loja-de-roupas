// Autores: Anna Livia e Ralf Ferreira
// Professores: Marcelo Iury e Derzu Omaia
// Data de Entrega: 08 de maio de 2023

#include "Roupas.h"

Roupas::Roupas() : Produto() {}

Roupas::Roupas(string nomeProduto, double valorDoProduto, int idProduto,
               int quantidadeDisponivel, string tamanhoProduto,
               string corProduto, string material, string tipoProduto,
               string subTipoProduto)
    : Produto(nomeProduto, valorDoProduto, idProduto, quantidadeDisponivel,
              tamanhoProduto, corProduto, "Roupas", subTipoProduto),
      material(material) {
  this->material = material;
}

Roupas::~Roupas() {}

string Roupas::getMaterial() { return material; }
void Roupas::setMaterial(string material) { this->material = material; }