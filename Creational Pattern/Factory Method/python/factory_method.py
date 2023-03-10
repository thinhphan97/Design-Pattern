from abc import ABC, abstractmethod


class Creator(ABC):
    @abstractmethod
    def factory_method(self):
        pass

    def some_operation(self) -> str:

        product = self.factory_method()

        result = f"Creator: The same creator's code has just worked with {product.operation()}"

        return result


class Product(ABC):
    @abstractmethod
    def operation(self) -> str:
        pass


class ConcreteProduct1(Product):
    def operation(self) -> str:
        return "{Result of the ConcreteProduct1}"


class ConcreteProduct2(Product):
    def operation(self) -> str:
        return "{Result of the ConcreteProduct2}"


class concreteCreator1(Creator):
    def factory_method(self) -> Product:
        return ConcreteProduct1()


class concreteCreator2(Creator):
    def factory_method(self) -> Product:
        return ConcreteProduct2()


def client_code(creator: Creator) -> None:

    print(f"Client: I'm not aware of the creator's class, but it still works.\n"
          f"{creator.some_operation()}", end="")


if __name__ == "__main__":
    print("App: Launched with the ConcreteCreator1.")
    client_code(concreteCreator1())
    print("\n")

    print("App: Launched with the ConcreteCreator1.")
    client_code(concreteCreator2())
    print("\n")
