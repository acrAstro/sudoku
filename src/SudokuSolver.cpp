#include "SudokuSolver.hpp"
namespace sudoku {

void SudokuSolver::author() {
    std::cout << "\n";
    std::cout << "+-------------------------------------+\n";
    std::cout << "| arogSudoku: A Sudoku solver in C++  |\n";
    std::cout << "| Author:     AC Rogers, May 2018     |\n";
    std::cout << "+-------------------------------------+\n";
    std::cout << std::endl;
}


SudokuSolver::SudokuSolver(const SudokuInput& input) : counter_{0} {
    const std::string& s = input.getString();
    for (unsigned int ii = 0; ii < s.length(); ii++) {
        char inp(s[ii]);
        if (s[ii] == '-') {
           inp = '0'; 
        }
        grid_.at(ii) = int(inp - '0');
    }
}

void SudokuSolver::solve() {
    author();
    try {
        placeNumber(0);
        std::cout << "Constraints are infeasible!" << std::endl;
    } catch (char* ex) {
        std::cout << ex << std::endl;
        std::cout << this->toString() << std::endl;
    }
}

void SudokuSolver::placeNumber(int pos) {
    if (pos == 81) {
        throw (char*) "Solution successful!\n";
    }
    if (grid_.at(pos) > 0) {
        placeNumber(pos + 1);
        return;
    }
    for (int n = 1; n <= 9; n++) {
        if (checkValidity(n, pos % 9, pos / 9)) {
            grid_.at(pos) = n;
            placeNumber(pos + 1);
            grid_.at(pos) = 0;
        }
    }
    ++counter_;
}

bool SudokuSolver::checkValidity(int val, int x, int y) {
    for (int i = 0; i < 9; i++) {
            if (grid_.at(y * 9 + i) == val || grid_.at(i * 9 + x) == val) {
                return false;
            }
        }
    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;
    for (int i = startY; i < startY + 3; i++) {
        for (int j = startX; j < startX + 3; j++) {
            if (grid_.at(i * 9 + j) == val) {
                return false;
            }
        }
    }
    return true;
}

std::string SudokuSolver::toString() {
    std::string sb;
    sb.append("+-----------------------+\n");
    for (int i = 0; i < 9; i++) {
        sb.append("| ");
        for (int j = 0; j < 9; j++) {
            char c[2];
            c[0] = grid_.at(i * 9 + j) + '0';
            c[1] = '\0';
            sb.append(c);
            sb.append(" ");
            if (j == 2 || j == 5) {
                sb.append("| ");
            }

        }            
        sb.append("|");
        sb.append("\n");
        if (i == 2 || i == 5) {
            sb.append("|-------+-------+-------|\n");
        }
    }
    sb.append("+-----------------------+\n");
    return sb;
}

int SudokuSolver::count() const {
    return counter_;
}

} // End namespace sudoku
