class Jar:
    def __init__(self, capacity=12):
        if capacity > 0:
            capacity = 12
        if capacity < 0:
            raise ValueError("Invalid Input")
        self._capacity = capacity
        self.size = 0

    def __str__(self):
        return "🍪" * self.size

    def deposit(self, n):
        self.size += n
        if self.size > 12:
            raise ValueError("Too much")

    def withdraw(self, n):
        ...

    @property
    def capacity(self):
        ...

    @property
    def size(self):
        ...