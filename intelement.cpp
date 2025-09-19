#include <iostream>
#include <cmath>
#include <functional>
#include <iomanip>

using namespace std;

// Método da soma de Riemann à esquerda
double integrar_riemann(function<double(double)> f, double a, double b, int n = 100000) {
    double h = (b - a) / n;
    double soma = 0.0;
    for (int i = 0; i < n; ++i) {
        double x = a + i * h;
        soma += f(x);
    }
    return soma * h;
}

void mostrar_menu() {
    cout << "Escolha a função f(x) a ser integrada:\n";
    cout << "1. x^2\n";
    cout << "2. x^3\n";
    cout << "3. 1/x\n";
    cout << "4. sqrt(x)\n";
    cout << "5. cos(x)\n";
    cout << "6. sin(x)\n";
    cout << "7. e^x\n";
    cout << "Digite o número da função: ";
}

int main() {
    int escolha;
    double a, b;

    mostrar_menu();
    cin >> escolha;

    cout << "Digite o limite inferior a: ";
    cin >> a;
    cout << "Digite o limite superior b: ";
    cin >> b;

    // Evitar a descontinuidade quando houver divisão por 0.
    if ((escolha == 3) && (a <= 0 && b >= 0)) {
        cerr << "Erro: o intervalo inclui x = 0, onde 1/x é indefinido." << endl;
        return 1;
    }

    function<double(double)> f;

    switch (escolha) {
        case 1:
            f = [](double x) { return x * x; };
            break;
        case 2:
            f = [](double x) { return x * x * x; };
            break;
        case 3:
            f = [](double x) { return 1.0 / x; };
            break;
        case 4:
            f = [](double x) { return sqrt(x); };
            break;
        case 5:
            f = [](double x) { return cos(x); };
            break;
        case 6:
            f = [](double x) { return sin(x); };
            break;
        case 7:
            f = [](double x) { return exp(x); };
            break;
        default:
            cerr << "Opção inválida." << endl;
            return 1;
    }

    double resultado = integrar_riemann(f, a, b);
    cout << fixed << setprecision(6);
    cout << "A integral de f(x) no intervalo [" << a << ", " << b << "] é aproximadamente " << resultado << endl;

    return 0;
}
