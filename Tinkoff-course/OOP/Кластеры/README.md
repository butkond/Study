## Условие задачи

Напишите программу, которая разделяет входной поток чисел на кластеры – группы близких по значению чисел. Числа принадлежат одному кластеру, если расстояние между любыми соседними числами не больше заданного числа _L_ , а расстояние от любого числа данного кластера до любого числа другого кластера больше _L_ . Исходные данные записаны в файл input.txt , результаты нужно вывести в файл output.txt .

### Входные данные
В первой строке файла input.txt записаны числа _N_ и _L_ . Во второй строке записаны _N_ элементов входного массива, разделённые пробелами.

### Выходные данные
В первой строке файла output.txt нужно вывести число найденных кластеров _K_ . В следующих _K_ строчках выводятся элементы, входящие в каждый кластер, в порядке возрастания (неубывания).

### Примеры
#### входные данные
```
6 10
15 11 44 12 13 49
```
#### выходные данные
```
2
11 12 13 15
44 49
```
