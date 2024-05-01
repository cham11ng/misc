class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return not self.items

    def size(self):
        return len(self.items)

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.is_empty():
            return None

        return self.items.pop()

    def peek(self):
        return self.items[-1]

    def __str__(self):
        return str(self.items)


if __name__ == "__main__":
    stack = Stack()

    print("is_empty", stack.is_empty())

    stack.push(1)
    stack.push(2)
    stack.push(3)

    print("__str__", stack.__str__())
    print("pop", stack.pop())
    print("peek", stack.peek())
    print("is_empty", stack.is_empty())
    print("size", stack.size())

    print("\n-------------\n")

    palindrome = Stack()

    word = input("enter word to check palindrome: ")
    new_word = ""

    for i in word:
        palindrome.push(i)

    while not palindrome.is_empty():
        new_word += palindrome.pop()

    print("reversed word:", new_word)

    if word == new_word:
        print(word, "is palindrome")
    else:
        print(word, "is not palindrome")
