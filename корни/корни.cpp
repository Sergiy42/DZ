#include <iostream>
#include <cmath>
using namespace std;
class Equation {
public:
    virtual void solve() = 0; // абстрактный метод для вычисления корней уравнения
};

class LinearEquation : public Equation {
private:
    double a, b; // коэффициенты уравнения ax + b = 0

public:
    LinearEquation(double a_, double b_) : a(a_), b(b_) {}

    void solve() override {
        if (a == 0) {
            if (b == 0) {
                cout << "Уравнение имеет бесконечное количество корней" << endl;
            }
            else {
                cout << "Уравнение не имеет корней" << endl;
            }
        }
        else {
            double x = -b / a;
            cout << "Корень уравнения: x = " << x << endl;
        }
    }
};

class QuadraticEquation : public Equation {
private:
    double a, b, c; // коэффициенты уравнения ax^2 + bx + c = 0

public:
    QuadraticEquation(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}

    void solve() override {
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            cout << "Уравнение не имеет действительных корней" << endl;
        }
        else if (discriminant == 0) {
            double x = -b / (2 * a);
            cout << "Уравнение имеет единственный корень: x = " << x << endl;
        }
        else {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Корни уравнения: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
    }
};

void solveEquation(Equation* equation) { // функция для вычисления корней уравнений
    equation->solve();
}

int main() {
    setlocale(0, "ru");
    Equation* eq1 = new LinearEquation(2, -3);
    Equation* eq2 = new QuadraticEquation(1, -5, 6);

    solveEquation(eq1);
    solveEquation(eq2);

    delete eq1;
    delete eq2;

    return 0;
}