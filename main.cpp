/*
* Created by Darius Sabaliauskas 2019-11-09
*/
#include <iostream>
#include <string>
using namespace std;
//we are creating the class CGloves for aggregation as you know the same gloves can be sometimes on different hands of people
//here is aggregation
class CGloves
{
public:
    CGloves(string color_of_gloves) : m_strColor{color_of_gloves}
    {

    }
    void setColorOfGloves(string& color);
   string getColorOfGloves() const;

private:
    string m_strColor;
};

void CGloves::setColorOfGloves(string& color) {
    m_strColor = color;
}
string CGloves::getColorOfGloves() const {
    return m_strColor;
}

//we are creating an outside class
class CHuman
{
private:

//In outside class CHuman we are creating the object of outside class CGloves
    CGloves *m_gloves;

public:

    CHuman(CGloves *m_gloves)
    {this->m_gloves = m_gloves;}
    void setColorOfGlovesOfHuman(string strColor) {
        m_gloves->setColorOfGloves(strColor);
    }
    void printColorOfGlovesOfHuman()
    {
        cout<<"The color of gloves of this human is "<<m_gloves->getColorOfGloves()<<endl;
    }


};
int main()
{
    CGloves gloves("red");
    CHuman human(&gloves);
    human.setColorOfGlovesOfHuman("yellow");

    human.printColorOfGlovesOfHuman();
    return 0;
}

