//-*-mode:c++; mode:font-lock;-*-

#ifndef _MYROOTOBJECT_H_
#define _MYROOTOBJECT_H_

#include <string>

#include <TNamed.h>

class MyROOTObject : public TNamed
{

public:
    MyROOTObject();
    MyROOTObject(int ival, double dval, std::string &name);
    virtual ~MyROOTObject();

    int getIntValue();
    void setIntValue(int value);

    double getDoubleValue();
    void setDoubleValue(double value);

    friend std::ostream& operator << (std::ostream& os, const MyROOTObject& object);

private:
    int m_int;
    double m_double;

    ClassDef(MyROOTObject, 2);

};

#endif
