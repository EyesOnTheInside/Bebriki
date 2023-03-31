#pragma once
#include <iostream>
#include <fstream>
#include <vector>

struct Token {
    int line;               // ����� ������
    std::string lexem_type; // ��� �������
    std::string lexem_name; // �������

    Token(int cur_line, std::string type, std::string name) {
        line = cur_line;
        lexem_type = type;
        lexem_name = name;
    }
};

class LexBase
{
public:
	virtual ~LexBase() { ; }
	virtual std::vector<Token> Run(std::string filename) = 0;
    virtual void Print() = 0;
protected:
	std::ifstream file;	            // ���� � ����������
    std::vector<Token> m_lexems;	// ������ ������
};

