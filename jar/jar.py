class Jar:
    def __init__(self, capacity=15):
        if capacity > 0:
            capacity = 15
        if capacity < 0:
            raise ValueError("Invalid Input")
        self._capacity = capacity
        self.size = 0

    def __str__(self):
        return "🍪" * self.size

    def deposit(self, n):
        self.size += n
        if self.size > 15:
            raise ValueError("Too much")

    def withdraw(self, n):
        self.size -= n
        if self.size < 0:
            raise ValueError("Too little")

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size

    @size.setter
    def size(self, n):
        self._size = n




def main():
    jar = Jar()
    jar.deposit(13)
    jar.withdraw(0)
    jar.deposit(2)
    print(str(jar.capacity))
    print(str(jar))



main()