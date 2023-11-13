#include <iostream>
#include <stack>
#include <cctype>
#include <sstream>

using namespace std;

// Infix ifadeyi postfix ifadeye �eviren fonksiyon
string Infix2Postfix(string& infixExpr) {
    stack<char> operatorStack;  // Operat�rlerin tutuldu�u y���n
    stringstream postfixExpr;   // Postfix ifadeyi tutan ak�� nesnesi

    for (char& c : infixExpr) {
        if (isdigit(c) || isalpha(c)) {
            // Operand� direkt olarak postfix ifadeye ekle
            postfixExpr << c;
        }
        else if (c == '(') {
            // A�ma parantezi, operat�r y���n�na ekle
            operatorStack.push(c);
        }
        else if (c == ')') {
            // Kapama parantezi, operat�r y���n�ndan a�ma parantezine kadar olan t�m operat�rleri postfix ifadeye ekle
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExpr << ' ' << operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // A�ma parantezini y���ndan ��kar
        }
        else if (c == '+' || c == '-') {
            // Toplama veya ��karmaysa
            postfixExpr << ' ';
            while (!operatorStack.empty() && (operatorStack.top() == '+' || operatorStack.top() == '-' || operatorStack.top() == '*' || operatorStack.top() == '/')) {
                // Y���ndaki �ncelikli operat�rleri postfix ifadeye ekle
                postfixExpr << operatorStack.top() << ' ';
                operatorStack.pop();
            }
            // �u anki operat�r� y���na ekle
            operatorStack.push(c);
        }
        else if (c == '*' || c == '/') {
            // �arpma veya b�lme ise
            postfixExpr << ' ';
            while (!operatorStack.empty() && (operatorStack.top() == '*' || operatorStack.top() == '/')) {
                // Y���ndaki �ncelikli operat�rleri postfix ifadeye ekle
                postfixExpr << operatorStack.top() << ' ';
                operatorStack.pop();
            }
            // �u anki operat�r� y���na ekle
            operatorStack.push(c);
        }
    }

    // Y���nda kalan operat�rleri postfix ifadeye ekle
    while (!operatorStack.empty()) {
        postfixExpr << ' ' << operatorStack.top();
        operatorStack.pop();
    }

    // Haz�rlanan postfix ifadeyi string olarak d�nd�r
    return postfixExpr.str();
}

// Postfix ifadeyi de�erlendiren fonksiyon
int EvaluatePostfixExpression(string& postfixExpr) {
    stack<int> operandStack;  // Operandlar�n tutuldu�u y���n
    stringstream ss(postfixExpr);  // Postfix ifadeyi okumak i�in bir ak�� nesnesi
    string token;  // Postfix ifadeden okunan her bir token

    // Postfix ifadeyi tokenlara b�lerek i�leme ba�la
    while (ss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            // E�er token bir say�ysa veya negatif bir say�ysa, operand y���n�na ekle
            operandStack.push(stoi(token));
        }
        else {
            // E�er token bir operat�rse
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            // Operat�re g�re i�lem yap ve sonucu operand y���n�na ekle
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

    // Operand y���n�nda kalan tek bir de�eri d�nd�r
    return operandStack.top();
}