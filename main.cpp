#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

class CFraction
{
    public:
        CFraction(const int n = 0, const int d = 1)
            : m_num(n)
            , m_den(d)
        {
            assert(0 < m_den);
            normalize();
        }
        CFraction& operator=(const CFraction& rhs);
        CFraction& operator+=(const CFraction& rhs);
        CFraction& operator-=(const CFraction& rhs);
        CFraction& operator*=(const CFraction& rhs);
        CFraction& operator/=(const CFraction& rhs);
        CFraction& operator++();
        CFraction& operator--();
        CFraction operator++(int);
        CFraction operator--(int);
        bool operator>(const CFraction& rhs) const;
        bool operator<(const CFraction& rhs) const;
        bool operator==(const CFraction& rhs) const;
        ostream& output(ostream& ostr) const;
        istream& input(istream& istr);
        ~CFraction() {};
    private:
        int m_num;
        int m_den;
        void normalize();
        
};


CFraction& CFraction::operator=(const CFraction& rhs)
{
    m_num = rhs.m_num;
    m_den = rhs.m_den;
    normalize();
    return *this;
}

CFraction& CFraction::operator+=(const CFraction& rhs)
{
    m_num = m_num * rhs.m_den + m_den * rhs.m_num;
    m_den = m_den * rhs.m_den;
    normalize();
    return *this;
}

CFraction& CFraction::operator-=(const CFraction& rhs)
{
    m_num = m_num * rhs.m_den - m_den * rhs.m_num;
    m_den = m_den * rhs.m_den;
    normalize();
    return *this;
}

CFraction& CFraction::operator*=(const CFraction& rhs)
{
    m_num = m_num * rhs.m_num;
    m_den = m_den * rhs.m_den;
    normalize();
    return *this;
}

CFraction& CFraction::operator/=(const CFraction& rhs)
{
    m_num = m_num * rhs.m_den;
    m_den = m_den * rhs.m_num;
    normalize();
    return *this;
}

CFraction& CFraction::operator++()
{   
    m_num += m_den;
    normalize();
    return *this;
}

CFraction CFraction::operator++(int)
{
    CFraction initValue(*this);
    ++(*this);
    return initValue;
}

CFraction& CFraction::operator--()
{
    m_num -= m_den;
    normalize();
    return *this;
}

CFraction CFraction::operator--(int)
{
    CFraction initValue(*this);
    --(*this);
    return initValue;
}

bool CFraction::operator>(const CFraction& temVar) const
{
    int lhs(m_num * temVar.m_den);
    int rhs(m_den * temVar.m_num);
    
    if(lhs > rhs)
        return true;
    else
        return false;
}

bool CFraction::operator<(const CFraction& temVar) const
{
    int lhs(m_num * temVar.m_den);
    int rhs(m_den * temVar.m_num);
    
    if(lhs < rhs)
        return true;
    else
        return false;
}

bool CFraction::operator==(const CFraction& temVar) const
{
    if(m_num == temVar.m_num && m_den == temVar.m_den)
        return true;
    else
        return false;
}

bool operator!=(const CFraction& lhs, const CFraction& rhs)
{
    if(lhs == rhs)
        return false;
    else
        return true;
}

bool operator<=(const CFraction& lhs, const CFraction& rhs)
{
    if(lhs == rhs || lhs <= rhs)
        return true;
    else
        return false;
}

bool operator>=(const CFraction& lhs, const CFraction& rhs)
{
    if(lhs == rhs || lhs >= rhs)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& ostr, const CFraction& rhs)
{
    return rhs.output(ostr);
}

istream& operator>>(istream& istr, CFraction& rhs)
{
    return rhs.input(istr);
}

ostream& CFraction::output(ostream& ostr) const
{
    if(1 == m_den)
        cout << m_num;
    else
        cout << m_num << '/' << m_den << endl;
    return ostr;
}

istream& CFraction::input(istream& istr)
{
    istr >> m_num >> m_den; 
    normalize();
    return istr;
}

void CFraction::normalize()
{
    int temVarF(m_num);
    int temVarS(m_den);
    while(temVarF && temVarS)
    {
        if(temVarF >= temVarS)
            temVarF = temVarF % temVarS;
        else
        temVarS = temVarS % temVarF;
    }

    int nod = temVarS + temVarF;

    if(1 != nod)
    {
        m_num = m_num / nod;
        m_den = m_den / nod;
    }
}

int genNumber()
{
    return rand() % 11 + 1;
}





int main()
{
    CFraction fFract(genNumber(), genNumber());
    CFraction sFract(genNumber(), genNumber());
    CFraction tFract(genNumber(), genNumber());
    cout << fFract<<endl;
    cout << sFract<<endl;
    ++sFract;
    cout << sFract;
    cin>>tFract;
    cout<<tFract;
    
    return 0;
}