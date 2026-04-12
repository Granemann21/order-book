# Order Book System

## Descrição do Trabalho
Este projeto consiste na implementação de um **Order Book** (Livro de Ofertas) simplificado para a negociação de uma única ação. O sistema gerencia ordens de compra (*Buy*) e venda (*Sell*), executando transações automaticamente sempre que os critérios de compatibilidade de preço são atingidos.

O diferencial deste sistema é que ele prioriza o **melhor preço** para a contraparte e utiliza ordem de chegada como critério de desempate, garantindo a execução justa conforme as regras de mercado financeiro especificadas no enunciado.

---

## Instruções de Compilação e Execução
O projeto foi desenvolvido de forma modular em C++, sem a utilização de bibliotecas prontas (STL), exigindo a compilação de todos os módulos de estrutura de dados customizados.

Para compilar o projeto completo, execute o seguinte comando no terminal:
```bash
g++ main.cpp OrderBook.cpp Order.cpp Transaction.cpp LinkedOrderlist.cpp LinkedTransactionList.cpp -o order_book
```

Para executar, siga o seguinte passo, verificando qual o seu ambiente:

### Windows (PowerShell ou CMD):
```
.\order_book.exe
```

### Linux/MacOS (Terminal):
```
chmod +x order_book
./order_book
```

---

## Organização Interna e Arquitetura

1. Estrutura de Dados

    `LinkedOrderList` / `LinkedTransactionList`: Listas encadeadas simples com ponteiros para head e tail.

    `OrderBook`: Gerenciador central que coordena as instâncias das listas de compras, vendas e histórico de transações.

    Nodes: Cada nó é o detentor da posse do objeto dinâmico que carrega.

2. Motor de Cruzamento

  A lógica de `submit()` segue o fluxo:
  
  Busca: Percorre a lista de contraparte para identificar ordens com preço compatível.
  
  Prioridade: Seleciona a contraparte com o melhor preço (maior para venda, menor para compra). Em empates, utiliza-se a de menor timestamp.
  
  Execução: Gera uma Transaction com o preço da ordem que já estava no livro e remove os itens compatíveis.

3. Gerenciamento de Memória

    Deep Copy: Toda ordem inserida é clonada via new `Order()` para garantir persistência no heap.
   
    Destruição em Cascata: Os destrutores das listas percorrem os nós e deletam tanto o nó quanto o objeto encapsulado, prevenindo memory leaks.
   
    Arrays Dinâmicos: Os métodos get... retornam cópias em arrays alocados com `new[]`, cuja liberação via `delete[]` é de responsabilidade do chamador.

---

## Autores
* **Murilo Granemann de Souza**
* **Luis Eduardo Weigert Weiss**

---
*Projeto desenvolvido para o Trabalho 2 da disciplina de Estrutura de Dados - Abril de 2026.*
   
