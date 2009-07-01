#include "ROOTObject.h"

ClassImp(MyROOTObject);

MyROOTObject::MyROOTObject()
{
    m_int = -1;
    m_double = -1.0;
    TNamed::SetName("default");
}

MyROOTObject::MyROOTObject(int ival, double dval, std::string &name)
{
    m_int = ival;
    m_double = dval;
    TNamed::SetName(name.c_str()); 
}

MyROOTObject::~MyROOTObject()
{
    // Do nothing for now
}

int MyROOTObject::getIntValue()
{
    return m_int;
}

void MyROOTObject::setIntValue(int value)
{
    m_int = value;
}

double MyROOTObject::getDoubleValue()
{
    return m_double;
}

void MyROOTObject::setDoubleValue(double value)
{
    m_double = value;
}
