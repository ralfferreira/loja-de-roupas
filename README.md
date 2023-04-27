# Loja de Roupas

## Autores

- [@Anna Livia](https://github.com/AnnaLiviaFM)
- [@Ralf Dewrich](https://github.com/ralfferreira)

## Classes

Classes Principais:

- Produto
- Roupas
- Calçados
- Loja

Classe Produto → Classe mãe → Contém os atributos comuns a todos os produtos

Classes Roupas e Calçados → Herdam a classe Produto e adicionam atributos próprios

Classe Loja → 

Classe Produto:
 - ID
 - Nome
 - Valor

 + Produto()
 + Produto(int ID, string nomeProduto, double valorDoProduto)
 + int getID()
 + string getNomeProduto()
 + double getValorDoProduto()
 + void setID(int ID)
 + void setNomeProduto(string nomeProduto)
 + void setValorDoProduto(double valorDoProduto)
 + virtual void MostrarNaTela()

Classe Roupas:
- string tamanho
- string cor
- string material

 + Roupas();
 + Roupas(int ID, string nomeProduto, double valorDoProduto, string tamanho, string cor, string material)
 + string getTamanho()
 + string getCor()
 + string getMaterial()
 + void setTamanho(string tamanho)
 + void setCor(string cor)
 + void setMaterial(string material)
 + void MostrarNaTela() override

Classe Calçados:
- string tamanho
- string cor
- string material
- string tipo