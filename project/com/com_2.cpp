#include <iostream>
using namespace std;

// 컴파일러의 파싱(Parsing)과 추상 구문 트리(Abstract Syntax Tree, AST) 생성 과정
int main() {
    cout << ">> int x = 5;\n";
    cout << "Decl\n";
    cout << " Type: int\n";
    cout << " Identifier: x\n";
    cout << " Value: 5\n\n";

    cout << ">> x = x + 10;\n";
    cout << "Assignment\n";
    cout << " Identifier: x\n";
    cout << " Binary\n";
    cout << "  Operator: +\n";
    cout << "  Identifier: x\n";
    cout << "  Value: 10\n\n";

    cout << ">> let int y; in y = y + 10; x = x + y; end;\n";
    cout << "Let\n";
    cout << " Decls\n";
    cout << "  Decl\n";
    cout << "   Type: int\n";
    cout << "   Identifier: y\n";
    cout << " Stmts\n";
    cout << "  Assignment\n";
    cout << "   Identifier: y\n";
    cout << "   Binary\n";
    cout << "    Operator: +\n";
    cout << "    Identifier: y\n";
    cout << "    Value: 10\n";
    cout << "  Assignment\n";
    cout << "   Identifier: x\n";
    cout << "   Binary\n";
    cout << "    Operator: +\n";
    cout << "    Identifier: x\n";
    cout << "    Value: y\n\n";

    cout << "end\n";

    return 0;
}
