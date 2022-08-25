#include <iostream>
#include <string>
#include <vector>

class Printable
{
public:
    virtual std::string GetClassName() = 0;
};


/**
 * PureEntity is essentially an interface which we can override
 */
class PureEntity
{
public:
    virtual void foo() = 0;
    virtual std::string getName() = 0;
    virtual std::vector<int> getMatrix() = 0;
};

class Player : public PureEntity
{
public:
    void foo() override
    {
        std::cout << "This does something" << std::endl;
    }

    std::string getName() override
    {
        return "Manish";
    }

    std::vector<int> getMatrix() override
    {
        std::vector<int> v = {1, 2, 3};
        v.push_back(4);
        v.push_back(5);
        return v;
    }
};