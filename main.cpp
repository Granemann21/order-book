#include <iostream>
#include "OrderBook.hpp"

using namespace std;

// Função auxiliar para evitar repetição no código de teste
void printStatus(OrderBook& book, string msg) {
    cout << "\n========================================" << endl;
    cout << "ESTADO APOS: " << msg << endl;
    cout << "========================================" << endl;
    book.printBuyOrders();
    cout << "----------------" << endl;
    book.printSellOrders();
    cout << "----------------" << endl;
    book.printTransactions();
    cout << "========================================\n" << endl;
}

int main() {
    OrderBook book;

    // 1. Início: Livro Vazio
    printStatus(book, "INICIALIZACAO (Vazio)");

    // 2. Adicionar Compra (Deve ir para a lista)
    cout << ">> Submetendo Compra ID 1, Preco 50.0" << endl;
    book.submit(new Order(1, 'B', 50.0, 100));
    printStatus(book, "ADICAO DE COMPRA ID 1");

    // 3. Adicionar Venda sem Match (Preco maior que a compra)
    cout << ">> Submetendo Venda ID 2, Preco 60.0" << endl;
    book.submit(new Order(2, 'S', 60.0, 101));
    printStatus(book, "ADICAO DE VENDA ID 2 (SEM MATCH)");

    // 4. Match Perfeito (Venda cruzando com a compra existente)
    cout << ">> Submetendo Venda ID 3, Preco 50.0 (Deve dar MATCH com ID 1)" << endl;
    book.submit(new Order(3, 'S', 50.0, 102));
    printStatus(book, "MATCH ID 3 COM ID 1 (Transacao gerada)");

    // 5. Teste de Cancelamento
    cout << ">> Submetendo Venda ID 4 (70.0) e cancelando logo em seguida" << endl;
    book.submit(new Order(4, 'S', 70.0, 103));
    book.cancel(4);
    printStatus(book, "CANCELAMENTO DA ORDEM ID 4");

    // 6. Teste de Prioridade de Preço (Compra)
    cout << ">> Adicionando Compra 5 (40.0) e depois Compra 6 (45.0)" << endl;
    book.submit(new Order(5, 'B', 40.0, 104));
    book.submit(new Order(6, 'B', 45.0, 105));
    printStatus(book, "PRIORIDADE: ID 6 deve aparecer antes de ID 5");

    // 7. Teste de Prioridade de Preço (Venda)
    cout << ">> Adicionando Venda 7 (80.0) e depois Venda 8 (75.0)" << endl;
    book.submit(new Order(7, 'S', 80.0, 106));
    book.submit(new Order(8, 'S', 75.0, 107));
    printStatus(book, "PRIORIDADE: ID 8 deve aparecer antes de ID 7");

    // 8. Match com Melhoria de Preço
    cout << ">> Compra ID 9 (78.0) deve fazer match com a melhor Venda (ID 8 a 75.0)" << endl;
    book.submit(new Order(9, 'B', 78.0, 108));
    printStatus(book, "MATCH ID 9 COM MELHOR VENDA (ID 8)");

    // 9. Match com Múltiplas Ordens (Limpar o book)
    cout << ">> Venda ID 10 (40.0) deve fazer match com a melhor Compra (ID 6 a 45.0)" << endl;
    book.submit(new Order(10, 'S', 40.0, 109));
    printStatus(book, "MATCH ID 10 COM ID 6");

    // 10. Estado Final
    cout << ">> Teste Final: Tentativa de cancelar ordem ja executada (ID 1)" << endl;
    if (!book.cancel(1)) {
        cout << "[OK] Sistema recusou cancelar ordem ja transacionada." << endl;
    }
    printStatus(book, "FIM DOS TESTES");

    return 0;
}