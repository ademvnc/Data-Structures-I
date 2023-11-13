#include <iostream>
#include <stack>
#include <cctype>
#include <sstream>

using namespace std;

// Infix ifadeyi postfix ifadeye çeviren fonksiyon
string Infix2Postfix(string& infixExpr) {
    stack<char> operatorStack;  // Operatörlerin tutulduðu yýðýn
    stringstream postfixExpr;   // Postfix ifadeyi tutan akýþ nesnesi

    for (char& c : infixExpr) {
        if (isdigit(c) || isalpha(c)) {
            // Operandý direkt olarak postfix ifadeye ekle
            postfixExpr << c;
        }
        else if (c == '(') {
            // Açma parantezi, operatör yýðýnýna ekle
            operatorStack.push(c);
        }
        else if (c == ')') {
            // Kapama parantezi, operatör yýðýnýndan açma parantezine kadar olan tüm operatörleri postfix ifadeye ekle
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExpr << ' ' << operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Açma parantezini yýðýndan çýkar
        }
        else if (c == '+' || c == '-') {
            // Toplama veya çýkarmaysa
            postfixExpr << ' ';
            while (!operatorStack.empty() && (operatorStack.top() == '+' || operatorStack.top() == '-' || operatorStack.top() == '*' || operatorStack.top() == '/')) {
                // Yýðýndaki öncelikli operatörleri postfix ifadeye ekle
                postfixExpr << operatorStack.top() << ' ';
                operatorStack.pop();
            }
            // Þu anki operatörü yýðýna ekle
            operatorStack.push(c);
        }
        else if (c == '*' || c == '/') {
            // Çarpma veya bölme ise
            postfixExpr << ' ';
            while (!operatorStack.empty() && (operatorStack.top() == '*' || operatorStack.top() == '/')) {
                // Yýðýndaki öncelikli operatörleri postfix ifadeye ekle
                postfixExpr << operatorStack.top() << ' ';
                operatorStack.pop();
            }
            // Þu anki operatörü yýðýna ekle
            operatorStack.push(c);
        }
    }

    // Yýðýnda kalan operatörleri postfix ifadeye ekle
    while (!operatorStack.empty()) {
        postfixExpr << ' ' << operatorStack.top();
        operatorStack.pop();
    }

    // Hazýrlanan postfix ifadeyi string olarak döndür
    return postfixExpr.str();
}

// Postfix ifadeyi deðerlendiren fonksiyon
int EvaluatePostfixExpression(string& postfixExpr) {
    stack<int> operandStack;  // Operandlarýn tutulduðu yýðýn
    stringstream ss(postfixExpr);  // Postfix ifadeyi okumak için bir akýþ nesnesi
    string token;  // Postfix ifadeden okunan her bir token

    // Postfix ifadeyi tokenlara bölerek iþleme baþla
    while (ss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            // Eðer token bir sayýysa veya negatif bir sayýysa, operand yýðýnýna ekle
            operandStack.push(stoi(token));
        }
        else {
            // Eðer token bir operatörse
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            // Operatöre göre iþlem yap ve sonucu operand yýðýnýna ekle
            switch (token[0]) {
            case '+':
                operandStack.push(operand1 + operand2);
                break;
            case '-':
                operandStack.push(operand1 - operand2);
                break;
            case '*':
                operandStack.push(operand1 * operand2);
                break;
            case '/':
                operandStack.push(operand1 / operand2);
                break;
            }
        }
    }

    // Operand yýðýnýnda kalan tek bir deðeri döndür
    return operandStack.top();
}