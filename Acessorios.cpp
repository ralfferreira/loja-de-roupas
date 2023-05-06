// Autores: Anna Livia e Ralf Ferreira
// Professores: Marcelo Iury e Derzu Omaia
// Data de Entrega: 08 de maio de 2023

#include "Acessorios.h"

Acessorios::Acessorios() : Produto() {}

Acessorios::Acessorios(string nomeProduto, double valorDoProduto, int idProduto,
                       int quantidadeDisponivel, string tamanhoProduto,
                       string corProduto, string material, string tipoProduto,
                       string subTipoProduto)
    : Produto(nomeProduto, valorDoProduto, idProduto, quantidadeDisponivel,
              tamanhoProduto, corProduto, "Acessorios", subTipoProduto),
      material(material) {
  this->material = material;
}

Acessorios::~Acessorios() {}

string Acessorios::getMaterial() { return material; }
void Acessorios::setMaterial(string material) { this->material = material; }