#pragma once
#include "LexicalBlock.h"

class Translator
{
public:
    /*
    * @brief ����������� ��� �� filename (���� ��� ���� ������ ����������� ����)
    * @param filename: ��� ����� � ����������
    */
    void Translate(std::string filename)
    {
        ;
    }

    /*
    * @brief ��������� ��������� �� ������� � ������� ��
    * @param filename: ��� ����� � ����������
    * @param toPrint: true, ����� ������� ������� �� �����, false - �� �������� (�� ��������� false)
    * @returns m_lexems: ������ ������
    */
    std::vector<Token> GetLexems(std::string filename, bool toPrint = false)
    {
        m_lexems = m_lexer.Run(filename);

        if (toPrint)
            m_lexer.Print();

        return m_lexems;
    }

    /*
    * @brief ��������� ��������� ���������
    * @param filename: ��� ����� � ����������
    * @returns true - ��������� ��������, false - �� ��������
    */
    bool CheckSyntax(std::string filename)
    {
        return true;
    }
private:
    LexicalBlock m_lexer;       // ����������� ����
    std::vector<Token> m_lexems;// ������ ������
};

