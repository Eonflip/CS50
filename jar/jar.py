class Jar:
    def __init__(self, capacity=12):
        ...

    def __str__(self):
        return "🍪" * self.size

    def deposit(self, n):
        ...

    def withdraw(self, n):
        ...

    @property
    def capacity(self):
        ...

    @property
    def size(self):
        ...