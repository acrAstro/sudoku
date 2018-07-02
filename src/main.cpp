#include "SudokuInput.hpp"
#include "SudokuSolver.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace sudoku;

void printDirections() {
    std::cout << "\nEnter the Sudoku puzzle one row at a time\n" << std::endl;
}

bool checkStringLength(const std::string& s) {
    if (s.size() == 9) {
        return true;
    } else {
        std::cout << "String length must be 9!\n";
        return false;
    }
}

void invalidInput() {
    std::cout << "\nInvalid command entered\n";
}

void invalidRow(int index) {
    std::cout << "Enter row " << std::to_string(index) << " again...\n";
}

void exampleSolution() {
    std::cout << "+-----------------------+\n";
    std::cout << "| 3 6 7 | 5 1 8 | 2 4 9 |\n";
    std::cout << "| 4 1 9 | 2 6 3 | 7 5 8 |\n";
    std::cout << "| 8 5 2 | 7 4 9 | 1 6 3 |\n";
    std::cout << "| ------+-------+------ |\n";
    std::cout << "| 1 2 5 | 8 9 6 | 3 7 4 |\n";
    std::cout << "| 7 9 8 | 4 3 5 | 6 1 2 |\n";
    std::cout << "| 6 3 4 | 1 7 2 | 9 8 5 |\n";
    std::cout << "| ------+-------+------ |\n";
    std::cout << "| 5 8 3 | 6 2 1 | 4 9 7 |\n";
    std::cout << "| 2 7 1 | 9 8 4 | 5 3 6 |\n";
    std::cout << "| 9 4 6 | 3 5 7 | 8 2 1 |\n";
    std::cout << "+-----------------------+\n";
}

void printHelp() {
    SudokuSolver::author();
    std::cout << "--> Example problem (wicked difficulty):\n\n";
    std::cout << "--> Row 1: 367500000\n";
    std::cout << "--> Row 2: 000060000\n";
    std::cout << "--> Row 3: 850000103\n";
    std::cout << "--> Row 4: 020006300\n";
    std::cout << "--> Row 5: 700000002\n";
    std::cout << "--> Row 6: 004100080\n";
    std::cout << "--> Row 7: 503000097\n";
    std::cout << "--> Row 8: 000080000\n";
    std::cout << "--> Row 9: 000007821\n\n";

    std::cout << "This will yield the following solution:\n\n";
    exampleSolution();

}

void exampleCall() {
    SudokuSolver::author();
    std::cout << "Usage: ./sudoku <arg>\n";
    std::cout << "> arg: -h(h) -- Help mode: display example problem\n";
    std::cout << "> arg: -r(r) -- Run mode: run a problem from command line\n";
    std::cout << "> If run-mode is selected, exit at any time with Ctrl-C or";
    std::cout << " by typing 'exit'\n";
    std::cout << "> Enter each row of your problem with zeros (0) or\n";
    std::cout << "  dashes (-) for the empty blocks\n\n";
}

bool exitCalled(const std::string& input) {
    if (input == "exit") {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        exampleCall();
        return -1;
    } else if (argc > 1 &&
            (std::string(argv[1]) == "-h" || std::string(argv[1]) == "h")) {
        printHelp();
    } else if (argc > 1 &&
            (std::string(argv[1]) == "-r" || std::string(argv[1]) == "r")) {
        SudokuInput si;
        int index{1};
        std::string input;
        printDirections();
        while (index <= 9) {
            std::string in;
            std::cout << "Row " << std::to_string(index) << ": ";
            std::cin >> in;
            if (exitCalled(in)) {
                std::cout << "Exiting" << std::endl;
                return -1;
            } else {
                if (checkStringLength(in) && !exitCalled(in)) {
                    input += in;
                    index++;
                } else {
                    invalidRow(index);
                }
            }
        }
        si.setString(input);
        SudokuSolver s(si);
        //author();
        s.solve();
        std::cout << "Solved in " << s.count() << " moves\n\n";
        return 0;
    } else {
        invalidInput();
    }
}
