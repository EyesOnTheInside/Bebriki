#pragma once
#include <iostream>
#include "LexBase.h"
#include <fstream>
#include <algorithm>
#include <string>
#include <Windows.h>
#include <sstream>
#include <vector>
#include <stack>
#include <list>

enum SymbolicTokenClass { Alpha, Digit, AR_OP, 
    Bool, Dot, Left_bracket, 
    Right_braket, Space, EndOfString, 
    EndOfFile, Exception, END, 
    FOR, GOSUB, GOTO, 
    IF, LET, NEXT, 
    REM, RETURN, STEP, TO };
enum States { A1, A2, A3, B1, C1, C2, D1, D2, D3, D4, D5, D6, E1, E2, F1, F2, F3, G1, H1, Stop };

struct LexemToken
{
    SymbolicTokenClass token_class = END;   // ��� �������
    std::string reg_data;                   // ������ � ��������
    int number_reg = 0;                     // ������� �����
    std::string relat_reg;                  // ������� ���������
    std::string variable_reg;               // ������� ����������
    int detect_reg = 0;                     // ������� �����������
    std::string token_reg;                  // ������� �������
    int reg_str = 1;                        // ����� ������

    void clear()
    {
        number_reg = 0;
        reg_data.clear();
        relat_reg.clear();
        variable_reg.clear();
        detect_reg = 0;
        token_reg.clear();
    }
};

class LexicalBlock :
    public LexBase
{
public:
    LexicalBlock();
    LexicalBlock(const LexicalBlock& lexer) = delete;
    LexicalBlock(const LexicalBlock&& lexer) = delete;

    /*
    * @brief ��������� ��������� � filename �� ������� � ���������� ������ � ����
    * @param filename: ��� �����
    * @return m_lexems: ������ ������
    */
    std::vector<Token> Run(std::string filename);

    /*
    * @brief �������� ������ ������
    */
    void Print();
private:
    /*
    * @brief ���������� ��� ������� �� �
    * @param c: ������
    * @return �������������� �����
    */
    SymbolicTokenClass identification(int c);

    /*
    * @brief ���������, �������� �� ������� �������� ������, ���� ��, �� ��������� � � ������ ������
    * @param m_line: ������
    * @param m_lexem: �������
    * @return true/false
    */
    bool Get_lexem(int m_line, std::string m_lexem);

    //��������� ��������

    /*
    * ��������� ����������� �������
    */
    int s_A1();

    /*
    * ��������� ����������� ��������� DA1D
    */
    int s_A1b();

    /*
    * ��������� ��������� �������
    */
    int s_A1a();

    /*
    * ��������� ����������� ��������� DA2D
    */
    int s_A1c();

    /*
    * ��������� ����������� ��������� DA3D
    */
    int s_A1d();

    /*
    * ��������� ����������� ��������� DA1E
    */
    int s_A1e();

    /*
    * ��������� ����������� ������� �������
    */
    int s_A2();

    /*
    * ��������� ����������� ��������� DA1D
    */
    int s_A2c();

    /*
    * ��������� ����������� �������� �������
    */
    int s_A2g();

    /*
    * ��������� ����������� �������� �������������� �������� � ������� ������
    */
    int s_A2a();

    /*
    * ��������� ����������� ��������� ������� � ����� ������
    */
    int s_A2b();

    /*
    * ��������� ����������� DA2D
    */
    int s_A2d();

    /*
    * ��������� ����������� DA3D
    */
    int s_A2e();

    /*
    * ��������� ����������� DA1E
    */
    int s_A2f();

    /*
    * ��������� ����������� DA1E
    */
    int s_A2j();

    /*
    * ��������� ����������� �������� �������
    */
    int s_A2k();

    /*
    * ��������� �����������  �������� ����� ������ � ������� ������ � ������� �������
    */
    int s_A2h();

    /*
    * ��������� ����������� DA1D
    */
    int s_A2l();

    /*
    * ��������� ����������� DA2D
    */
    int s_A2m();

    /*
    * ��������� ����������� DA3D
    */
    int s_A2n();

    /*
    * ��������� ����������� ��������� ������ ���� ���� �� ������� �������� �� =
    */
    int s_A2o();

    /*
    * ��������� ����������� ���� ������� ��������� � ������� �������� ����� ������� ���� 0 => ������ ����� ���������� ����� ��������� � ������� ���������
    */
    int s_A2p();

    /*
    * ��������� ����������� �������� ����� � ������� ������
    */
    int s_A2q();

    /*
    * ��������� ����������� �������� ���� � ������� ������
    */
    int s_A2r();

    /*
    * ��������� ����������� �������� ������� � ������� ������
    */
    int s_A2s();
    ///////////////////////////////////////
    /*
    * ��������� ����������� ��������� '<'
    */
    int s_A2t();

    /*
    * ��������� ����������� ��������� '>'
    */
    int s_A2u();

    /*
    * ��������� ����������� ��������� �����
    */
    int s_A3a();

    /*
    * ��������� ����������� ������� �� �������
    */
    int s_A3();

    /*
    * ��������� ����������� ����� ����� ��������� '<' � '>'
    */

    int s_A3d();

    /*
    * ��������� ����������� �������� �������
    */
    int s_A3c();

    /*
    * ��������� ����������� ��������� '+'
    */
    int s_A3b();

    /*
    * ��������� ����������� ��2� � ������� ������
    */
    int s_A3e();

    /*
    * ��������� ����������� ��������� '='
    */
    int s_A3f();

    /*
    * ��������� ����������� ��1� � ������� ������
    */
    int s_A3g();

    /*
    * ��������� ����������� ��3� � ������� ������
    */
    int s_B1c();
    /*
    * ��������� ����������� ��������� �������
    */
    int s_B1b();

    /*
    * ��������� ����������� ����� �� �������� ����������� ��������� �������� ���� 0 - ������
    */
    int s_B1a();

    /*
    * ��������� ����������� ��������� '*'
    */
    int s_B1();

    /*
    * ��������� ����������� ��������� '/'
    */
    int s_B1d();

    /*
    * ��������� ����������� ��1�
    */
    int s_B1e();

    /*
    * ��������� ����������� �������� ����� ����� � ������� ������
    */
    int s_C1a();

    /*
    * ��������� ����������� ��������� ���������
    */
    int s_C1();

    /*
    * ��������� ����������� ������� �������
    */
    int s_C2b();

    /*
    * ��������� ����������� ��������� '-'
    */
    int s_C2a();

    /*
    * ��������� ����������� ��������  � ������� ��������� ��� + ������� ��������
    */
    int s_C2d();

    /*
    * ��������� ����������� �������
    */
    int s_C2();

    /*
    * ��������� ����������� ������� �������
    */
    int s_D1c();

    /*
    * ��������� ����������� ��������� '-'
    */
    int s_D1a();

    /*
    * ��������� ����������� ������� �����*10 ������� ����� + ������� ��������
    */
    int s_D1b();

    /*
    * ��������� ����������� �������
    */
    int s_D1();

    /*
    * ��������� ����������� ��������� ����������� ������
    */
    int s_D2a();

    /*
    * ��������� ����������� �������
    */
    int s_D2();

    /*
    * ��������� ����������� ������� �������� = 1 ������� �������� -> ������� �����
    */
    int s_D2b();

    /*
    * ��������� ����������� ��������� ����������� ������
    */
    int s_D2c();

    /*
    * ��������� ����������� ������� �������� =0
    */
    int s_D3a();

    /*
    * ��������� ����������� �������
    */
    int s_D3();

    /*
    * ��������� ����������� ���� + - ������� +1 ���� ��= 2 �� -1 ����� ������
    */
    int s_D4a();

    /*
    * ��������� ����������� �������
    */
    int s_D4();

    /*
    * ��������� ����������� �������� +1 � ������� �����
    */
    int s_D5a();

    /*
    * ��������� ����������� ����� ������� �������� -> ������ �������
    */
    int s_D5b();

    /*
    * ��������� ����������� �������
    */
    int s_D5();

    /*
    * ��������� ����������� ������� ������� *10 ������� ������� + ������� ��������
    */
    int s_D5c();

    /*
    * ��������� ����������� ������� �������
    */
    int s_D6a();

    /*
    * ��������� ����������� �������� �������� � ������� ������
    */
    int s_D6();

    /*
    * ��������� ����������� ��������� '^'
    */
    int s_E1a();

    /*
    * ��������� ����������� �������
    */
    int s_E1();

    /*
    * ��������� ����������� �������� ������� �� ����� � ������� ������
    */
    int s_E1b();

    /*
    * ��������� ����������� �������� ������ � ������� ������
    */
    int s_E2a();

    /*
    * ��������� ����������� �������� � ������� ������ ������� ��������
    */
    int s_E2b();

    /*
    * ��������� ����������� �������
    */
    int s_E2();

    /*
    * ��������� ����������� *10 ������� ������ ������� ������ + ������� ��������
    */
    int s_E2c();

    /*
    * ��������� ����������� �������� ��������� � ������� ������
    */
    int s_F1a();

    /*
    * ��������� ����������� �������
    */
    int s_F1();

    /*
    * ��������� ����������� ���������� ������ ����� ��� �������� ���������
    */
    int s_F1b();

    /*
    * ��������� ����������� �������� � ������� ��������� ����+ ������� ��������
    */
    int s_F2a();

    /*
    * ��������� ����������� ��������� ����� � ���������
    */
    int s_F2();

    /*
    * ��������� ����������� ������� �������� +1 *26 ������� ��������� +
    */
    int s_F3a();

    /*
    * ��������� ����������� �������
    */
    int s_F3();

    /*
    * ��������� ����������� �������� ����������� � ������� ������ � ������� �������
    */
    int s_G1a();

    /*
    * ��������� ����������� �������� ���������
    */
    int s_G1();

    /*
    * ��������� ����������� ��1�
    */
    int s_H1c();

    /*
    * ��������� ����������� ������� �������
    */
    int s_H1b();

    /*
    * ��������� ����������� ������� �������� => ������� ��������� ��������� -> ������� ������
    */
    int s_H1a();

    /*
    * ��������� ����������� �������
    */
    int s_H1();

    /*
    * ��������� ����������� ��2�
    */
    int s_H1d();

    /*
    * ��������� ����������� ��3�
    */
    int s_H1e();

    /*
    * ��������� ����������� ��������� ������ � ������ ���������
    */
    int s_H1f();

    /*
    * ��������� ����������� �������� ������� ����������� � ������� ��������  == -> ������� �� ������� ���������� ���� 0 �� ������
    */
    int s_M1();

    /*
    * ��������� ����������� ���������� ������ ���������
    */
    int s_M2();

    /*
    * ��������� ����������� �� - �������� ����� �� ������ 5 �� ��2� � ������� �� �1� ���� 5 �� �3
    */
    int s_M3();

    /*
    * ��������� ����������� ��1�
    */
    int Exit3();

    /*
    * ��������� ����������� ������� �������
    */
    int Exit2();

    /*
    * ��������� ����������� �������� ���� ������ � ������� ������ ������� ������� � ����� � ��
    */
    int Exit1();

    /*
    * ��������� ����������� ��2� � �����2
    */
    int Exit4();

    /*
    * ��������� ����������� ��3� � �����2
    */
    int Exit5();

    /*
    * ��������� ����������� ��1� � �����2
    */
    int Exit6();

    /*
    * ��������� ����������� ��������� ������
    */
    int Error();

    /*
    * ��������� ����������� �������� ������� � ������� ������
    */
    int s_DA1D();

    /*
    * ��������� ����������� �������� ������� � ������� ������
    */
    int s_DA2D();

    /*
    * ��������� ����������� �������� ������� � ������� ������
    */
    int s_DA3D();

    /*
    * ��������� ����������� �������� ������� � ������� ������
    */
    int s_DA1E();

    /*
    * ��������� ����������� �������� ������� � ������� ������
    */
    int s_DA1ETSICL();

    //state_number = 19 -  ����� ��������� ��� s_Stop
    //class_number = 11 - ����� �������� �������� ��������

    int m_ch = 0;                                       // ��� ��������
    int m_line = 0;                                     // ����� ������
    int m_i = 0;                                        // ������� � ������

    typedef int(LexicalBlock::* function_pointer)();
    function_pointer m_table[19][11];                   // ������� ��������

    std::string m_buffer;                               // ������
    std::string m_lexem;                                // �������
    std::string m_copy;                                 // ����� �������

    bool m_mark = true;                                 // ���� �����
    bool m_constant = false;                            // ���� ���������
    bool m_word = false;                                // ���� �����
    bool m_skip_point = false;                          // ���� ��������
    bool m_is_rem = false;                              // ���� �����������
};
