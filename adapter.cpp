#include <string>
#include <iostream>
class Computer //adaptee
{
public:
    virtual std::string Read()
    {
        std::cout<<data<<"\n";
    }

    virtual void Write(std::string d)
    {
        data = d;
        Read();
    }
private:
    std::string data;
};

class SDCard //Target
{
public:
    virtual void WriteToPC(std::string){}
};

class CardCase : //adapter
    public SDCard , private Computer
{
public:
    virtual void WriteToPC(std::string d) override
    {
        this->Write(d);
    }
};

int main()
{
    std::string text = "SDCard to PC !";
    SDCard *sdcard = new CardCase();
    sdcard->WriteToPC(text);
}