

# 📘 Integração Numérica com Riemann em C++

Este projeto contém um programa que calcula a **aproximação de integrais definidas** utilizando o **método da soma de Riemann à esquerda**.  
Ele permite escolher uma função matemática, definir um intervalo \([a, b]\) e retorna a área aproximada sob a curva.

---

## ⚙️ Como o código funciona

1. O programa exibe um **menu de funções** para o usuário escolher.  
   Cada número corresponde a uma função matemática diferente.  

2. O usuário digita o **limite inferior (a)** e o **limite superior (b)** da integral.  

3. O código divide o intervalo em **100.000 pequenos subintervalos** (quanto mais subdivisões, mais precisa a aproximação).  

4. Para cada subintervalo, o programa calcula a área de um retângulo usando o valor da função no **início** do intervalo (*método de Riemann à esquerda*).  

5. A soma de todas as áreas desses retângulos resulta em uma aproximação da integral.  

6. O resultado é exibido na tela com **6 casas decimais**.

---

## 🧮 Funções disponíveis

O menu inicial oferece estas opções:

| Número | Função       |
|--------|--------------|
| 1      | \(f(x) = x^2\) |
| 2      | \(f(x) = x^3\) |
| 3      | \(f(x) = 1/x\) (⚠️ inválido se o intervalo incluir 0) |
| 4      | \(f(x) = \sqrt{x}\) |
| 5      | \(f(x) = \cos(x)\) |
| 6      | \(f(x) = \sin(x)\) |
| 7      | \(f(x) = e^x\) |

---

## 💻 Como usar

### 1. Compilar
No terminal, dentro da pasta do projeto:
```bash
g++ main.cpp -o integral -std=c++11 -O2
