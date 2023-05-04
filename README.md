# Loja de Roupas

## Autores

- [@Anna Livia](https://github.com/AnnaLiviaFM)
- [@Ralf Dewrich](https://github.com/ralfferreira)

## Classes

Classes Principais:

- Produto
- Roupas
- Calçados
- Acessórios
- Loja

Classe Produto → Classe mãe → Contém os atributos comuns a todos os produtos

Classes Roupas, Calçados e Acessórios → Herdam a classe Produto e adicionam atributos próprios

Classe Loja → Classe para adicionar, remover e listar produtos

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
- string tipo

 + Roupas();
 + Roupas(int ID, string nomeProduto, double valorDoProduto, string tamanho, string cor, string material, string tipo)
 + string getTamanho()
 + string getCor()
 + string getMaterial()
 + string getTipo()
 + void setTamanho(string tamanho)
 + void setCor(string cor)
 + void setMaterial(string material)
 + void setTipo(string tipo)
 + void MostrarNaTela() 

Classe Calçados:
- string tamanho
- string cor
- string tipo

+ Calcados();
+ Calcados(int ID, string nomeProduto, double valorDoProduto, string tamanho, string cor, string tipo);
+ string getTamanho();
+ string getCor();
+ string getTipo();
+ void setTamanho(string tamanho);
+ void setCor(string cor);
+ void setTipo(string tipo);
+ void MostrarNaTela();

Classe Acessórios
- string tamanho;
- string cor;
- string material;
- string tipo;


+ Acessorios();
+ Acessorios(int ID, string nomeProduto, double valorDoProduto, string tamanho, string cor, string material, string tipo);
+ string getTamanho();
+ string getCor();
+ string getMaterial();
+ string getTipo();
+ void setTamanho(string tamanho);
+ void setCor(string cor);
+ void setMaterial(string material);
+ void setTipo(string tipo);
+ void MostrarNaTela();
