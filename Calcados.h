#include "Produto.h"

class Calcados : public Produto{
  private:
    string tamanho;
    string cor;
    string tipo;

  public:
    Calcados();
    Calcados(int ID, string nomeProduto, double valorDoProduto, string tamanho, string cor, string tipo);
    string getTamanho();
    string getCor();
    string getTipo();
    void setTamanho(string tamanho);
    void setCor(string cor);
    void setTipo(string tipo);
    void MostrarNaTela();
};