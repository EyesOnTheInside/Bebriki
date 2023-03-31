#include "LexemBlock.h"

int LexemBlock::s_DA1ETSICL()
{
	return 0;
}

int LexemBlock::Exit3()
{
    return 0;
}

int LexemBlock::Exit2()
{
    return 0;
}

int LexemBlock::Exit1()
{
    return 0;
}

int LexemBlock::Exit4()
{
    return 0;
}

int LexemBlock::Exit5()
{
    return 0;
}

int LexemBlock::Exit6()
{
    return 0;
}

int LexemBlock::Error()
{
	return 0;
}

int LexemBlock::s_DA1D()
{
	return 0;
}

int LexemBlock::s_DA2D()
{
	return 0;
}

int LexemBlock::s_DA3D()
{
	return 0;
}

int LexemBlock::s_DA1E()
{
	return 0;
}

int LexemBlock::s_H1f()
{
    if (!Get_lexem(m_line, m_lexem))
    {
        m_lexems.pop_back();
        m_lexems.push_back(Token(m_line, std::string("Error"), std::string("Error in m_constant")));
        m_lexem.clear();
        m_copy.clear();
        m_constant = false;
        m_word = false;
    }
    else
    {
        m_lexem.clear();
        m_copy.clear();
        m_constant = false;
        m_word = false;
    }
    return H1;
}

int LexemBlock::s_M1()
{
    return 0;
}

int LexemBlock::s_M2()
{
    if (isdigit(m_buffer[m_i]))
    {
        if (m_lexem.size() == 0)
        {
            m_constant = true;
            m_lexem += m_buffer[m_i];
        }
        else
        {
            if (m_constant)
                m_lexem += m_buffer[m_i];
            else
            {
                if (Get_lexem(m_line, m_lexem))
                {
                    m_lexem.clear();
                    m_lexem += m_buffer[m_i];
                    m_constant = true;
                    m_word = false;
                    return 1;
                }
                m_lexem += m_buffer[m_i];
                return 1;
            }
        }
        return 1;
    }
    return 0;
}

int LexemBlock::s_M3()
{
    return 0;
}

int LexemBlock::s_H1e()
{
    return H1;
}

int LexemBlock::s_H1c()
{
    return H1;
}

int LexemBlock::s_H1b()
{
    return H1;
}

int LexemBlock::s_H1a()
{
    return H1;
}

int LexemBlock::s_H1()
{
    return H1;
}

int LexemBlock::s_H1d()
{
    return H1;
}

int LexemBlock::s_G1()
{
    if (m_word)
        m_lexem += m_buffer[m_i];
    else
    {
        if (m_buffer[m_i] == 'E')
            m_lexem += m_buffer[m_i];
        else
        {
            m_constant = false;
            m_word = true;
            m_lexems.push_back(Token(m_line, std::string("m_constant"), m_lexem));
            m_copy.clear();
            m_copy = m_lexem;
            m_lexem.clear();
            m_lexem += m_buffer[m_i];
        }
    }
    return G1;
}

int LexemBlock::s_F2()
{
    if (m_lexem.size() > 0)
        if (m_constant)
            m_lexem += m_buffer[m_i];
        else
        {
            m_lexem.clear();
            m_word = false;
            m_constant = false;
            m_lexems.push_back(Token(m_line, std::string("Error"), std::string("Error with point")));
            return 1;
        }
    m_constant = true;
    return 0;
}

int LexemBlock::s_F3a()
{
    return F3;
}

int LexemBlock::s_F3()
{
    return F3;
}

int LexemBlock::s_G1a()
{
    return G1;
}

LexemBlock::LexemBlock()
{
    for (int i = 0; i < state_number; i++)
        for (int j = 0; j < class_number; j++)
            m_table[i][j] = &LexemBlock::Error;

    m_table[A1][Digit] = &LexemBlock::s_E2a;
    m_table[A1][Space] = &LexemBlock::s_A1;
    m_table[A1][EndOfString] = &LexemBlock::s_A1;
    m_table[A1][EndOfFile] = &LexemBlock::Exit1;
    m_table[A2][Alpha] = &LexemBlock::s_C2a;
    m_table[A2][Digit] = &LexemBlock::s_D1a;
    m_table[A2][AR_OP] = &LexemBlock::s_A2a;
    m_table[A2][Bool] = &LexemBlock::s_H1a;
    m_table[A2][Left_bracket] = &LexemBlock::s_A2h;
    m_table[A2][Right_braket] = &LexemBlock::s_A3b;
    m_table[A2][Dot] = &LexemBlock::s_D6;
    m_table[A2][Space] = &LexemBlock::s_A2;
    m_table[A2][EndOfString] = &LexemBlock::s_A1;
    m_table[A2][EndOfFile] = &LexemBlock::Exit1;
    m_table[A3][Alpha] = &LexemBlock::s_B1a;
    m_table[A3][Digit] = &LexemBlock::s_D1a;
    m_table[A3][AR_OP] = &LexemBlock::s_A2a;
    m_table[A3][Bool] = &LexemBlock::s_H1a;
    m_table[A3][Left_bracket] = &LexemBlock::s_A2h;
    m_table[A3][Right_braket] = &LexemBlock::s_A3b;
    m_table[A3][Dot] = &LexemBlock::s_D6;
    m_table[A3][Space] = &LexemBlock::s_A3;
    m_table[A3][EndOfString] = &LexemBlock::s_A1;
    m_table[A3][EndOfFile] = &LexemBlock::Exit1;

    m_table[B1][Alpha] = &LexemBlock::s_M1;
    m_table[B1][Space] = &LexemBlock::s_B1;

    m_table[C1][Alpha] = &LexemBlock::s_C2d;
    m_table[C1][Space] = &LexemBlock::s_C1;
    m_table[C2][Alpha] = &LexemBlock::s_B1b;
    m_table[C2][Digit] = &LexemBlock::s_A3a;
    m_table[C2][AR_OP] = &LexemBlock::s_A2g;
    m_table[C2][Bool] = &LexemBlock::s_H1b;
    m_table[C2][Left_bracket] = &LexemBlock::s_A2k;
    m_table[C2][Right_braket] = &LexemBlock::s_A3c;
    m_table[C2][Space] = &LexemBlock::s_C2;
    m_table[C2][EndOfString] = &LexemBlock::s_A1a;
    m_table[C2][EndOfFile] = &LexemBlock::Exit2;

    m_table[D1][Alpha] = &LexemBlock::s_M2;
    m_table[D1][Digit] = &LexemBlock::s_D1b;
    m_table[D1][AR_OP] = &LexemBlock::s_A2c;
    m_table[D1][Bool] = &LexemBlock::s_H1c;
    m_table[D1][Left_bracket] = &LexemBlock::s_A2u;
    m_table[D1][Right_braket] = &LexemBlock::s_A3d;
    m_table[D1][Dot] = &LexemBlock::s_D2c;
    m_table[D1][Space] = &LexemBlock::s_D1;
    m_table[D1][EndOfString] = &LexemBlock::s_A1b;
    m_table[D1][EndOfFile] = &LexemBlock::Exit3;
    m_table[D2][Alpha] = &LexemBlock::s_M3;
    m_table[D2][Digit] = &LexemBlock::s_D2a;
    m_table[D2][AR_OP] = &LexemBlock::s_A2d;
    m_table[D2][Bool] = &LexemBlock::s_H1d;
    m_table[D2][Left_bracket] = &LexemBlock::s_A2m;
    m_table[D2][Right_braket] = &LexemBlock::s_A3e;
    m_table[D2][Space] = &LexemBlock::s_D2;
    m_table[D2][EndOfString] = &LexemBlock::s_A1c;
    m_table[D2][EndOfFile] = &LexemBlock::Exit4;
    m_table[D3][Digit] = &LexemBlock::s_D5a;
    m_table[D3][AR_OP] = &LexemBlock::s_D4a;
    m_table[D3][Space] = &LexemBlock::s_D3;
    m_table[D4][Digit] = &LexemBlock::s_D5b;
    m_table[D4][Space] = &LexemBlock::s_D4;
    m_table[D5][Alpha] = &LexemBlock::s_B1c;
    m_table[D5][Digit] = &LexemBlock::s_D5c;
    m_table[D5][AR_OP] = &LexemBlock::s_A2e;
    m_table[D5][Bool] = &LexemBlock::s_H1e;
    m_table[D5][Left_bracket] = &LexemBlock::s_A2n;
    m_table[D5][Right_braket] = &LexemBlock::s_A3f;
    m_table[D5][Space] = &LexemBlock::s_D5;
    m_table[D5][EndOfString] = &LexemBlock::s_A1d;
    m_table[D5][EndOfFile] = &LexemBlock::Exit5;
    m_table[D6][Digit] = &LexemBlock::s_D2b;
    m_table[D6][Space] = &LexemBlock::s_D6;

    m_table[E1][Digit] = &LexemBlock::s_E2b;
    m_table[E1][Space] = &LexemBlock::s_E1;
    m_table[E2][Alpha] = &LexemBlock::s_B1e;
    m_table[E2][Digit] = &LexemBlock::s_E2c;
    m_table[E2][AR_OP] = &LexemBlock::s_A2f;
    m_table[E2][Bool] = &LexemBlock::s_H1f;
    m_table[E2][Left_bracket] = &LexemBlock::s_A2j;
    m_table[E2][Right_braket] = &LexemBlock::s_A3g;
    m_table[E2][Space] = &LexemBlock::s_E2;
    m_table[E2][EndOfString] = &LexemBlock::s_A1e;
    m_table[D1][EndOfFile] = &LexemBlock::Exit6;

    m_table[F1][Alpha] = &LexemBlock::s_F2a;
    m_table[F1][Space] = &LexemBlock::s_F1;
    m_table[F2][Digit] = &LexemBlock::s_F3a;
    m_table[F2][Bool] = &LexemBlock::s_A2o;
    m_table[F2][Space] = &LexemBlock::s_F2;
    m_table[F3][Bool] = &LexemBlock::s_A2o;
    m_table[F3][Space] = &LexemBlock::s_F3;

    m_table[G1][Alpha] = &LexemBlock::s_G1;
    m_table[G1][Digit] = &LexemBlock::s_G1;
    m_table[G1][AR_OP] = &LexemBlock::s_G1;
    m_table[G1][Bool] = &LexemBlock::s_G1;
    m_table[G1][Left_bracket] = &LexemBlock::s_G1;
    m_table[G1][Right_braket] = &LexemBlock::s_G1;
    m_table[G1][Dot] = &LexemBlock::s_G1;
    m_table[G1][Space] = &LexemBlock::s_G1;
    m_table[G1][EndOfString] = &LexemBlock::s_A1;
    m_table[G1][EndOfFile] = &LexemBlock::Exit1;

    m_table[H1][Alpha] = &LexemBlock::s_C2b;
    m_table[H1][Digit] = &LexemBlock::s_D1c;
    m_table[H1][AR_OP] = &LexemBlock::s_A2g;
    m_table[H1][Bool] = &LexemBlock::s_A2p;
    m_table[H1][Left_bracket] = &LexemBlock::s_A2k;
    m_table[H1][Right_braket] = &LexemBlock::s_A3c;
    m_table[H1][Dot] = &LexemBlock::s_D6a;
    m_table[H1][Space] = &LexemBlock::s_H1;
    m_table[H1][EndOfString] = &LexemBlock::s_A1a;
    m_table[H1][EndOfFile] = &LexemBlock::Exit2;
}

std::vector <Token> LexemBlock::Run(std::string filename)
{
    file.open(filename);
    if (!(file.is_open()))
    {
        std::cout << "File " << filename << " failed to open" << std::endl;
        //m_lexems.push_back(Token(0, " ", " "));
        return m_lexems;
    }

    while (getline(file, m_buffer))
    {
        s_A2();
        m_line++;
        for (m_i = 0; m_i < m_buffer.size() + 1; m_i++)
        {
            if (m_skip_point)
            {
                m_skip_point = false;
                continue;
            }
            if (m_is_rem)
            {
                break;
            }
            if (s_A2b())
                continue;
            if (s_A3a())
                continue;
            if (s_F1b())
                continue;
            else if (m_copy.size() > 0)
                s_H1f();
            if (s_M2())
                continue;
            switch (m_buffer[m_i])
            {
            case '.':
                if (s_F2())
                    continue;
                continue;
            case '(':
                s_D2c();
                continue;
            case ')':
                s_D2a();
                continue;
            case ' ':
                s_B1b();
                continue;
            case '\t':
                s_C1();
                continue;
            case '+':
                s_A3b();
                continue;
            case '-':
                if (s_D1a())
                    continue;
                s_C2a();
                continue;
            case '/':
                s_B1d();
                continue;
            case '^':
                s_E1a();
                continue;
            case '*':
                s_B1();
                continue;
            case '=':
                s_A3f();
                continue;
            case '<':
                s_A3d();
                if (s_A2t())
                    continue;
                continue;
            case '>':
                s_A3d();
                if (s_A2u())
                    continue;
                continue;
            default:
                if (m_lexem == "REM")
                    m_is_rem = true;
                else
                    m_lexems.push_back(Token(m_line, std::string("Error"), std::string("Unknown simbol")));
                m_lexem.clear();
                m_word = false;
                m_constant = false;
                continue;
            }
        }
    }

    m_lexems.push_back(Token(m_line + 1, std::string("EOF"), std::string("EOF")));
    m_copy.clear();
    m_lexem.clear();
    m_buffer.clear();
    file.close();
    return m_lexems;
}

SymbolicTokenClass LexemBlock::identification(int c)
{
    m_ch = c;
    if ((m_ch >= 192 && m_ch <= 255)) { return Alpha; }
    else if (isalpha(m_ch)) { return Alpha; }
    else if (isdigit(m_ch)) { return Digit; }
    else if (m_ch == '+' || m_ch == '-' || m_ch == '/' || m_ch == '%' || m_ch == '*') { return AR_OP; }
    else if (m_ch == '>' || m_ch == '<' || m_ch == '=' || m_ch == '!') { return Bool; }
    else if (m_ch == ' ') { return Space; }
    else if (m_ch == '\n') { return EndOfString; }
    else if (m_ch == EOF) { return EndOfFile; }
    //else { return Error; }
}

bool LexemBlock::Get_lexem(int m_line, std::string m_lexem)
{
    if (m_lexem.size() < 2)
        return false;
    if (m_lexem == "IF")
    {
        m_lexems.push_back(Token(m_line, std::string("k_if"), m_lexem));
        return true;
    }
    if (m_lexem == "LET")
    {
        m_lexems.push_back(Token(m_line, std::string("k_let"), m_lexem));
        return true;
    }
    if (m_lexem == "GOSUB")
    {
        m_lexems.push_back(Token(m_line, std::string("k_gosub"), m_lexem));
        return true;
    }
    if (m_lexem == "END")
    {
        m_lexems.push_back(Token(m_line, std::string("k_end"), m_lexem));
        return true;
    }
    if (m_lexem == "NEXT")
    {
        m_lexems.push_back(Token(m_line, std::string("k_next"), m_lexem));
        return true;
    }
    if (m_lexem == "REM")
    {
        m_lexems.push_back(Token(m_line, std::string("k_rem"), m_lexem));
        return true;
    }
    if (m_lexem == "RETURN")
    {
        m_lexems.push_back(Token(m_line, std::string("k_return"), m_lexem));
        return true;
    }
    if (m_lexem == "STEP")
    {
        m_lexems.push_back(Token(m_line, std::string("k_step"), m_lexem));
        return true;
    }
    if (m_lexem == "GOTO")
    {
        m_lexems.push_back(Token(m_line, std::string("k_goto"), m_lexem));
        return true;
    }
    if (m_lexem == "TO")
    {
        m_lexems.push_back(Token(m_line, std::string("k_to"), m_lexem));
        return true;
    }
    if (m_lexem == "FOR")
    {
        m_lexems.push_back(Token(m_line, std::string("k_for"), m_lexem));
        return true;
    }
    return false;
}

int LexemBlock::s_A1()
{
    return A1;
}

int LexemBlock::s_A1a()
{
    return A1;
}

int LexemBlock::s_A1b()
{
    s_DA1D();
    return A1;
}

int LexemBlock::s_A1c()
{
    s_DA2D();
    return A1;
}

int LexemBlock::s_A1d()
{
    s_DA3D();
    return A1;
}

int LexemBlock::s_A1e()
{
    s_DA1E();
    return A1;
}

int LexemBlock::s_A2c()
{
    s_DA1D();
    return A2;
}

int LexemBlock::s_A2g()
{
    return A2;
}

int LexemBlock::s_A2a()
{
    return A2;
}

int LexemBlock::s_A2b()
{
    if (m_buffer[m_i] == '\0')
    {
        if (m_lexem.size() > 0)
            if (!(Get_lexem(m_line, m_lexem)))
                if (isdigit(m_lexem[0]))
                    if (m_mark)
                        m_lexems.push_back(Token(m_line, std::string("Error"), std::string("Empty m_line")));
                    else
                        m_lexems.push_back(Token(m_line, std::string("m_constant"), m_lexem));
                else
                    m_lexems.push_back(Token(m_line, std::string("Variable"), m_lexem));
        if (m_lexems.back().lexem_type == std::string("m_mark"))
            m_lexems.push_back(Token(m_line, std::string("Error"), std::string("Empty m_line")));
        m_lexem.clear();
        m_word = false;
        m_constant = false;
        return 1;
    }
    return 0;
}

int LexemBlock::s_A2()
{
    m_lexem.clear();
    m_copy.clear();
    m_mark = true;
    m_constant = false;
    m_word = false;
    m_skip_point = false;
    m_is_rem = false;
    return A2;
}

int LexemBlock::s_A2d()
{
    s_DA2D();
    return A2;
}

int LexemBlock::s_A2e()
{
    return A2;
}

int LexemBlock::s_A2f()
{
    return A2;
}

int LexemBlock::s_A2j()
{
    return A2;
}

int LexemBlock::s_A2k()
{
    return A2;
}

int LexemBlock::s_A2h()
{
    return A2;
}

int LexemBlock::s_A2l()
{
    return A2;
}

int LexemBlock::s_A2m()
{
    return A2;
}

int LexemBlock::s_A2n()
{
    return A2;
}

int LexemBlock::s_A2o()
{
    return A2;
}

int LexemBlock::s_A2p()
{
    return A2;
}

int LexemBlock::s_A2q()
{
    return A2;
}

int LexemBlock::s_A2r()
{
    return A2;
}

int LexemBlock::s_A2s()
{
    return A2;
}

int LexemBlock::s_A2t()
{
    if (m_buffer[m_i + 1] == '=')
    {
        m_lexems.push_back(Token(m_line, std::string("Bool_op"), std::string("<=")));	m_skip_point = true; return 1;
    }
    if (m_buffer[m_i + 1] == '>')
    {
        m_lexems.push_back(Token(m_line, std::string("Bool_op"), std::string("<>")));	m_skip_point = true; return 1;
    }
    if (m_buffer[m_i + 1] == '<')
    {
        m_lexems.push_back(Token(m_line, std::string("Error"), std::string("Error in bool operator"))); m_skip_point = true; return 1;
    }
    m_lexems.push_back(Token(m_line, std::string("Bool_op"), std::string("<")));
    return 0;
}

int LexemBlock::s_A2u()
{
    if (m_buffer[m_i + 1] == '=')
    {
        m_lexems.push_back(Token(m_line, std::string("Bool_op"), std::string(">=")));	m_skip_point = true; return 1;
    }
    if (m_buffer[m_i + 1] == '>')
    {
        m_lexems.push_back(Token(m_line, std::string("Error"), std::string("Error in bool operator"))); m_skip_point = true; return 1;
    }
    if (m_buffer[m_i + 1] == '<')
    {
        m_lexems.push_back(Token(m_line, std::string("Error"), std::string("Error in bool operator"))); m_skip_point = true; return 1;
    }
    m_lexems.push_back(Token(m_line, std::string("Bool_op"), std::string(">")));
    return 0;
}

int LexemBlock::s_A3a()
{
    if (m_mark)
    {
        if (isdigit(m_buffer[m_i]))
        {
            m_lexem += m_buffer[m_i];
            return 1;
        }
        else
        {
            if (m_lexem.size() > 0)
                m_lexems.push_back(Token(m_line, std::string("m_mark"), m_lexem));
            else
                m_lexems.push_back(Token(m_line, std::string("Error"), std::string("Error in m_mark")));
            m_mark = false;
            m_lexem.clear();
        }
    }
    return 0;
}

int LexemBlock::s_A3()
{
    return A3;
}

int LexemBlock::s_A3d()
{
    if (m_lexem.size() > 0)
        if (!(Get_lexem(m_line, m_lexem)))
            if (isdigit(m_lexem[0]))
                m_lexems.push_back(Token(m_line, std::string("m_constant"), m_lexem));
            else
                m_lexems.push_back(Token(m_line, std::string("Variable"), m_lexem));
    if (m_lexem == "REM")
        m_is_rem = true;
    m_lexem.clear();
    m_word = false;
    m_constant = false;
    return A3;
}

int LexemBlock::s_A3c()
{
    return A3;
}

int LexemBlock::s_A3b()
{
    if (m_lexem.size() > 0)
        if (!(Get_lexem(m_line, m_lexem)))
            if (isdigit(m_lexem[0]))
                m_lexems.push_back(Token(m_line, std::string("m_constant"), m_lexem));
            else
                m_lexems.push_back(Token(m_line, std::string("Variable"), m_lexem));
    if (m_lexem == "REM")
        m_is_rem = true;
    m_lexem.clear();
    m_word = false;
    m_constant = false;
    m_lexems.push_back(Token(m_line, std::string("AR_OP"), std::string("+")));
    return A3;
}

int LexemBlock::s_A3e()
{
    return A3;
}

int LexemBlock::s_A3f()
{
    if (m_lexem.size() > 0)
        if (!(Get_lexem(m_line, m_lexem)))
            if (isdigit(m_lexem[0]))
                m_lexems.push_back(Token(m_line, std::string("m_constant"), m_lexem));
            else
                m_lexems.push_back(Token(m_line, std::string("Variable"), m_lexem));
    if (m_lexem == "REM")
        m_is_rem = true;
    m_lexem.clear();
    m_word = false;
    m_constant = false;
    m_lexems.push_back(Token(m_line, std::string("Equality"), std::string("=")));
    return A3;
}

int LexemBlock::s_A3g()
{
    return A3;
}

int LexemBlock::s_B1c()
{
    return B1;
}

int LexemBlock::s_B1b()
{
    if (m_lexem.size() > 0)
        if (!(Get_lexem(m_line, m_lexem)))
            if (isdigit(m_lexem[0]))
                m_lexems.push_back(Token(m_line, std::string("m_constant"), m_lexem));
            else
                m_lexems.push_back(Token(m_line, std::string("Variable"), m_lexem));
    if (m_lexem == "REM")
    {
        m_is_rem = true;
        int k = 2;
        while ((m_buffer[k - 2] != 'R') and (m_buffer[k - 1] != 'E') and (m_buffer[k] != 'M'))
            k++;
        m_buffer.erase(m_buffer.begin(), m_buffer.begin() + k + 2);
        m_lexems.push_back(Token(m_line, std::string("rem_cont"), m_buffer));
    }
    m_lexem.clear();
    m_word = false;
    m_constant = false;
    return B1;
}

int LexemBlock::s_B1a()
{
    return B1;
}

int LexemBlock::s_B1()
{
    if (m_lexem.size() > 0)
        if (!(Get_lexem(m_line, m_lexem)))
            if (isdigit(m_lexem[0]))
                m_lexems.push_back(Token(m_line, std::string("m_constant"), m_lexem));
            else
                m_lexems.push_back(Token(m_line, std::string("Variable"), m_lexem));
    if (m_lexem == "REM")
        m_is_rem = true;
    m_lexem.clear();
    m_word = false;
    m_constant = false;
    m_lexems.push_back(Token(m_line, std::string("AR_OP"), std::string("*")));
    return B1;
}

int LexemBlock::s_B1d()
{
    if (m_lexem.size() > 0)
        if (!(Get_lexem(m_line, m_lexem)))
            if (isdigit(m_lexem[0]))
                m_lexems.push_back(Token(m_line, std::string("m_constant"), m_lexem));
            else
                m_lexems.push_back(Token(m_line, std::string("Variable"), m_lexem));
    if (m_lexem == "REM")
        m_is_rem = true;
    m_lexem.clear();
    m_word = false;
    m_constant = false;
    m_lexems.push_back(Token(m_line, std::string("AR_OP"), std::string("/")));
    return B1;
}

int LexemBlock::s_B1e()
{
    return B1;
}

int LexemBlock::s_C1a()
{
    return C1;
}

int LexemBlock::s_C1()
{
    if (m_lexem.size() > 0)
        if (!(Get_lexem(m_line, m_lexem)))
            if (isdigit(m_lexem[0]))
                m_lexems.push_back(Token(m_line, std::string("m_constant"), m_lexem));
            else
                m_lexems.push_back(Token(m_line, std::string("Variable"), m_lexem));
    if (m_lexem == "REM")
        m_is_rem = true;
    m_lexem.clear();
    m_word = false;
    m_constant = false;
    return C1;
}

int LexemBlock::s_C2b()
{
    return C2;
}

int LexemBlock::s_C2a()
{
    if (m_lexem.size() == 0)
    {
        if ((m_lexems.back().lexem_type != std::string("m_constant")) and (m_lexems.back().lexem_type != std::string("Variable")) and (m_lexems.back().lexem_type != std::string("Right_bracket")))
        {
            m_constant = true;
            m_lexem += m_buffer[m_i];
        }
        m_lexem.clear();
        m_word = false;
        m_constant = false;
        m_lexems.push_back(Token(m_line, std::string("AR_OP"), std::string("-")));
    }
    else
    {
        m_lexem.clear();
        m_word = false;
        m_constant = false;
        m_lexems.push_back(Token(m_line, std::string("AR_OP"), std::string("-")));
    }
    return C2;
}

int LexemBlock::s_C2d()
{
    return C2;
}

int LexemBlock::s_C2()
{
    return C2;
}

int LexemBlock::s_D1c()
{
    return D1;
}

int LexemBlock::s_D1a()
{
    if (m_lexem.size() > 0)
        if (!(Get_lexem(m_line, m_lexem)))
            if (isdigit(m_lexem[0]))
                if (m_lexem[m_lexem.size() - 1] == 'E')
                {
                    m_lexem += m_buffer[m_i];
                    return 1;
                }
                else
                    m_lexems.push_back(Token(m_line, std::string("m_constant"), m_lexem));
            else
                m_lexems.push_back(Token(m_line, std::string("Variable"), m_lexem));
    if (m_lexem == "REM")
        m_is_rem = true;
    return 0;
}

int LexemBlock::s_D1b()
{
    return D1;
}

int LexemBlock::s_D1()
{
    return D1;
}

int LexemBlock::s_D2a()
{
    if (m_lexem.size() > 0)
        if (!(Get_lexem(m_line, m_lexem)))
            if (isdigit(m_lexem[0]))
                m_lexems.push_back(Token(m_line, std::string("m_constant"), m_lexem));
            else
                m_lexems.push_back(Token(m_line, std::string("Variable"), m_lexem));
    if (m_lexem == "rem")
        m_is_rem = true;
    m_lexem.clear();
    m_word = false;
    m_constant = false;
    m_lexems.push_back(Token(m_line, std::string("Right_bracket"), std::string(")")));
    return D2;
}

int LexemBlock::s_D2()
{
    return D2;
}

int LexemBlock::s_D2b()
{
    return D2;
}

int LexemBlock::s_D2c()
{
    if (m_lexem.size() > 0)
        if (!(Get_lexem(m_line, m_lexem)))
            if (isdigit(m_lexem[0]))
                m_lexems.push_back(Token(m_line, std::string("m_constant"), m_lexem));
            else
                m_lexems.push_back(Token(m_line, std::string("Variable"), m_lexem));
    if (m_lexem == "rem")
        m_is_rem = true;
    m_lexem.clear();
    m_word = false;
    m_constant = false;
    m_lexems.push_back(Token(m_line, std::string("Left_bracket"), std::string("(")));
    return D2;
}

int LexemBlock::s_D3a()
{
    return D3;
}

int LexemBlock::s_D3()
{
    return D3;
}

int LexemBlock::s_D4a()
{
    return D4;
}

int LexemBlock::s_D4()
{
    return D4;
}

int LexemBlock::s_D5a()
{
    return D5;
}

int LexemBlock::s_D5b()
{
    return D5;
}

int LexemBlock::s_D5()
{
    return D5;
}

int LexemBlock::s_D5c()
{
    return D5;
}

int LexemBlock::s_D6a()
{
    return D6;
}

int LexemBlock::s_D6()
{
    return D6;
}

int LexemBlock::s_E1a()
{
    if (m_lexem.size() > 0)
        if (!(Get_lexem(m_line, m_lexem)))
            if (isdigit(m_lexem[0]))
                m_lexems.push_back(Token(m_line, std::string("m_constant"), m_lexem));
            else
                m_lexems.push_back(Token(m_line, std::string("Variable"), m_lexem));
    m_lexem.clear();
    m_word = false;
    m_constant = false;
    m_lexems.push_back(Token(m_line, std::string("AR_OP"), std::string("^")));
    return E1;
}

int LexemBlock::s_E1()
{
    return E1;
}

int LexemBlock::s_E1b()
{
    return E1;
}

int LexemBlock::s_E2a()
{
    return E2;
}

int LexemBlock::s_E2b()
{
    return E2;
}

int LexemBlock::s_E2()
{
    return E2;
}

int LexemBlock::s_E2c()
{
    return E2;
}

int LexemBlock::s_F1a()
{
    return F1;
}

int LexemBlock::s_F1()
{
    return F1;
}

int LexemBlock::s_F1b()
{
    if (isalpha(m_buffer[m_i]))
    {
        if (m_lexem.size() == 0)
        {
            m_word = true;
            m_lexem += m_buffer[m_i];
        }
        else {
            s_G1();
        }
        return 1;
    }
    return 0;
}

int LexemBlock::s_F2a()
{
    return F2;
}