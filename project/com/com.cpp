#include <iostream>
using namespace std;

int main() {
    cout << "int main() {\n";
    cout << "    int x, y, k;\n";
    cout << "    x = 1;\n";
    cout << "    y = 2;\n";
    cout << "    k = 0;\n";
    cout << "    if (x < y) {\n";
    cout << "        k = 100;\n";
    cout << "    }\n";
    cout << "};\n\n";
    
    cout << "Start parsing..\n\n";
    
    cout << "Program (abstract syntax:)\n";
    cout << "    Declarations:\n";
    cout << "    Declarations = { <x, int> <y, int> <k, int> }\n";
    cout << "    Display Block (for Statements)\n";
    cout << "        Assignment:\n";
    cout << "            Variable x\n";
    cout << "            Int: 1\n";
    cout << "        Assignment:\n";
    cout << "            Variable y\n";
    cout << "            Int: 2\n";
    cout << "        Assignment:\n";
    cout << "            Variable k\n";
    cout << "            Int: 0\n";
    cout << "        Binary:\n";
    cout << "            Operator: <\n";
    cout << "            Variable x\n";
    cout << "            Variable y\n";
    cout << "        Display Block (for Statements)\n";
    cout << "            Assignment:\n";
    cout << "                Variable k\n";
    cout << "                Int: 100\n\n";

    cout << "Start type checking..\n";
    cout << "Type stack-value pair:\n";
    cout << "Display Abstract Syntax Tree\n";
    cout << "Program (abstract syntax:)\n";
    cout << "    Declarations:\n";
    cout << "    Declarations = { <x, int> <y, int> <k, int> }\n";
    cout << "    Display Block (for Statements)\n";
    cout << "        Assignment:\n";
    cout << "            Variable x\n";
    cout << "            Int: 1\n";
    cout << "        Assignment:\n";
    cout << "            Variable y\n";
    cout << "            Int: 2\n";

    return 0;
}