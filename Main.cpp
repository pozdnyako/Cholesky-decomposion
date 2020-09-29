// Cholesky decomp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "LinSystem.h"

int main() {
    try {
        std::ifstream fin("input.txt");
        Matrix A(fin);
        fin.close();
        
        Vector x(A.N);
        for (int i = 0; i < x.N; i++) {
            x[i] = i + 1;
        }

        LinSystem sys(A, A*x);

        std::cout << "result:" << sys.solve();
    }
    catch (std::exception& e) {
        std::cerr << e.what();
    }
}