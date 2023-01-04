#include <string>
#include <iostream>

class Product
{
public:
    virtual ~Product() {}
    virtual std::string Operation() const = 0;
};

class ConcreteProduct1 : public Product
{
public:
    std::string Operation() const override
    {
        return "{Result of the ConcreteProduct1}";
    }
};

class ConcreteProduct2 : public Product
{
public:
    std::string Operation() const override
    {
        return "{Result of the ConcreteProduct2}";
    }
};

class Creater
{
public:
    virtual ~Creater(){};
    virtual Product *FactoryMethod() const = 0;

    std::string SomeOperation() const
    {
        Product *product = this->FactoryMethod();
        std::string result = "Creator: The same creator's code has just worked with " + product->Operation();

        delete product;
        return result;
    }
};

class ConcreteCreator1 : public Creater
{
public:
    Product *FactoryMethod() const override
    {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creater
{
public:
    Product *FactoryMethod() const override
    {
        return new ConcreteProduct2();
    }
};

void ClientCode(const Creater &creater)
{
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
              << creater.SomeOperation() << std::endl;
}

int main()
{
    std::cout << "App: Launched with the ConcreateCreater1.\n";
    Creater *creater = new ConcreteCreator1();
    ClientCode(*creater);
    std::cout << std::endl;
    std::cout << "App: Launched with the ConcreateCreater2.\n";
    Creater *creater2 = new ConcreteCreator2();
    ClientCode(*creater2);

    delete creater;
    delete creater2;

    return 0;
}