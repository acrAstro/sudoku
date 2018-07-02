#include "SudokuInput.hpp"
#include "SudokuSolver.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace sudoku;

int main() {
    std::string s;
    s.append("367500000");
    s.append("000060000");
    s.append("850000103");
    s.append("020006300");
    s.append("700000002");
    s.append("004100080");
    s.append("503000097");
    s.append("000080000");
    s.append("000007821");
    SudokuInput si;
    si.setString(s);
    SudokuSolver solver(si);
    solver.solve();
    std::cout << "Solved in " << solver.count() << " moves\n\n";
    return 0;
}
