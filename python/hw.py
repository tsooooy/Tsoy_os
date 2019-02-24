f = open('pack.txt', 'r')
import re

numbers = set()

n1 = 0
n2 = 32000
for line in f:
    ranger = []
    line = re.findall('[0-9]+', line)[0]
    line = int(line)
    if line > n1:
        n1 = line
    if line < n2:
        n2 = line
    numbers.add(line)
    for i in range(n2, n1):
        ranger.append(i)
    for elem in numbers:
        if elem in ranger:
            ranger.remove(elem)

    if len(numbers) == 1:
        print("Пакет полный - ", n2)
    else:
        print("Пакет от", n2, "до", n1)
        print("Не хватает:")
        print(ranger)