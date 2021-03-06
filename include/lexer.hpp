#ifndef LEXER_HPP__
#define LEXER_HPP__

#include <memory>
#include <vector>
#include <string.h>
#include <optional>
#include <algorithm>
#include "token.hpp"
#include "symbol.hpp"
#include <stack>
#include <unordered_map>

struct Token
{
    std::string type;
    std::optional<double> value;
    std::optional<std::string> str;
};


class Lexer
{
private:
    char* src; //  源码
    int token;
    TokenType token_type;
    TokenValue token_val;
    std::vector<Symbol> symtab; // 符号表
    std::optional<char*> name;
    std::vector<std::string> keywords_name;
    Token parser_token; // 传输给 parser 的 token
    FILE* ofstream;
    // 添加关键字
    void add_keywords();
	bool printToken();
    // 向前查看 n 个字符
    char* lookupn(int size);
    // 向后查看 n 个字符
    char* lookdown(int size);
    // 将符号加入到 parser_token 中, 需要区分是关键字还是符号
    void add_idn_to_token(Symbol symbol);
public:
    void init();
    bool next(bool show = false);
    Token get_token();
    int get_current_token_value();
    void run(char* src);
    Lexer();
    ~Lexer();
};




#endif