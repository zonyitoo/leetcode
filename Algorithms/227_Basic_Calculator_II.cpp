#include <string>
#include <cctype>
#include <stack>
#include <vector>
using std::string;
using std::vector;
using std::stack;

enum class Operator {
    Add,
    Sub,
    Mul,
    Div
};

enum class TokenType {
    Int,
    Operator,
    End
};

struct Token {
    TokenType token_type;
    union {
        Operator op;
        int integer;
    } data;
};

int operator_priv(Operator op) {
    switch (op) {
    case Operator::Add:
    case Operator::Sub:
        return 1;
    case Operator::Mul:
    case Operator::Div:
        return 2;
    }
}

class Calculator {
  public:
    Calculator(string s)
        : data(s), cur_pos(0) {}

    int eval() {
        vector<Token> rpn = eval_rpn();

        stack<int> evalst;

        for (const auto& tok : rpn) {
            switch (tok.token_type) {
            case TokenType::Int:
                evalst.push(tok.data.integer);
                break;
            case TokenType::Operator: {
                    int right = evalst.top();
                    evalst.pop();
                    int left = evalst.top();
                    evalst.pop();

                    switch (tok.data.op) {
                    case Operator::Add:
                        evalst.push(left + right);
                        break;
                    case Operator::Sub:
                        evalst.push(left - right);
                        break;
                    case Operator::Mul:
                        evalst.push(left * right);
                        break;
                    case Operator::Div:
                        evalst.push(left / right);
                        break;
                    }
                }
                break;
            default:
                break;
            }
        }

        return evalst.top();
    }

  private:
    vector<Token> eval_rpn() {
        vector<Token> rpn;

        stack<Token> op;

        while (!eof()) {
            Token token = next();
            switch (token.token_type) {
            case TokenType::Int:
                rpn.push_back(token);
                break;
            case TokenType::Operator:
                if (op.empty()) {
                    op.push(token);
                } else {
                    while (!op.empty()) {
                        int top_priv = operator_priv(op.top().data.op);
                        int cur_priv = operator_priv(token.data.op);

                        if (cur_priv > top_priv) {
                            break;
                        } else {
                            rpn.push_back(op.top());
                            op.pop();
                        }
                    }
                    op.push(token);
                }
                break;
            default:
                break;
            }
        }

        while (!op.empty()) {
            rpn.push_back(op.top());
            op.pop();
        }

        return std::move(rpn);
    }

    Token next() {
        parse_whitespace();
        if (eof()) {
            Token token;
            token.token_type = TokenType::End;
            return token;
        }

        switch (this->current()) {
        case '+':
        case '-':
        case '*':
        case '/':
            return parse_operator();
        default:
            return parse_integer();
        }
    }

    bool bump() {
        if (cur_pos == data.size())
            return false;
        cur_pos += 1;
        return true;
    }

    bool eof() {
        return cur_pos == data.size();
    }

    char current() {
        return data[cur_pos];
    }

    void parse_whitespace() {
        while (this->current() == ' ') bump();
    }

    Token parse_integer() {
        int num = 0;
        while (std::isdigit(this->current())) {
            num = num * 10 + (this->current() - '0');
            this->bump();
        }

        Token token;
        token.token_type = TokenType::Int;
        token.data.integer = num;
        return token;
    }

    Token parse_operator() {
        Operator op;

        switch (this->current()) {
        case '+':
            op = Operator::Add;
            break;
        case '-':
            op = Operator::Sub;
            break;
        case '*':
            op = Operator::Mul;
            break;
        case '/':
            op = Operator::Div;
            break;
        }

        this->bump();

        Token token;
        token.token_type = TokenType::Operator;
        token.data.op = op;
        return token;
    }

  private:
    string data;
    size_t cur_pos;
};

class Solution {
  public:
    int calculate(string s) {
        return Calculator(s).eval();
    }
};
