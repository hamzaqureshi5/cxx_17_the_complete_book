#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class ProcessingElement {
public:
    int acc = 0;

    void compute(int a, int b) {
        acc += a * b;
    }
};

void printMatrix(const vector<vector<int>>& matrix, const string& name) {
    cout << name << ":\n";
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << setw(5) << value << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

vector<vector<int>> systolicArrayMatMulDebug(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B
) {
    int M = A.size();        // rows of A
    int K = A[0].size();     // columns of A
    int N = B[0].size();     // columns of B

    vector<vector<ProcessingElement>> PE(
        M, vector<ProcessingElement>(N)
    );

    cout << "Starting Systolic Array Simulation\n\n";

    printMatrix(A, "Matrix A");
    printMatrix(B, "Matrix B");

    // Each k represents one systolic beat/cycle
    for (int k = 0; k < K; k++) {
        cout << "=============================\n";
        cout << "Cycle / Beat: " << k + 1 << "\n";
        cout << "=============================\n\n";

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int a = A[i][k];
                int b = B[k][j];

                int before = PE[i][j].acc;
                PE[i][j].compute(a, b);
                int after = PE[i][j].acc;

                cout << "PE[" << i << "][" << j << "] ";
                cout << "receives A[" << i << "][" << k << "] = " << a;
                cout << ", B[" << k << "][" << j << "] = " << b << "\n";

                cout << "    Compute: acc = " << before
                     << " + (" << a << " * " << b << ")"
                     << " = " << after << "\n\n";
            }
        }

        cout << "PE accumulator state after cycle " << k + 1 << ":\n";

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cout << setw(5) << PE[i][j].acc << " ";
            }
            cout << "\n";
        }

        cout << "\n";
    }

    vector<vector<int>> C(M, vector<int>(N));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = PE[i][j].acc;
        }
    }

    return C;
}

int main() {
    vector<vector<int>> A = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> B = {
        {5, 6},
        {7, 8}
    };

    vector<vector<int>> C = systolicArrayMatMulDebug(A, B);

    cout << "=============================\n";
    cout << "Final Output Matrix C = A x B\n";
    cout << "=============================\n\n";

    printMatrix(C, "Matrix C");

    return 0;
}