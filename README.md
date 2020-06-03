# push_swap
___

### Цель проекта
___
###### На вход подаются различные числа, необходимо произвести наиболее эффективную сортировку этих чисел используя тип данных - стэк. Программа push_swap - выдает набор команд необходимых для сортировки, программа checker - проверяет команды и выдает результат(отсортирован стэк или нет).

##### Коротко о задаче:
- Число операций для 100 чисел - не более 700
- Число операция для 500 чисел - не более 5500
- Число операция для 5 чисел - не более 12
- Число операция для 3 чисел - не более 3

##### Для сортировки необходимо реализовать и использовать след. операции:
- pb - верхний элемент из стэка а преходит в стэк b
- pb - верхний элемент из стэка b преходит в стэк a
- sa - поменять местами два верхних элемента в стэке а
- sb - поменять местами два верхних элемента в стэке b
- ss - sa + sb
- ra - сдвинуть все элементы в стэке а вверх, верхний элемент переходит вниз
- rb - сдвинуть все элементы в стэке b вверх, верхний элемент переходит вниз
- rr - ra + rb
- rra - сдвинуть все элементы в стэке а вниз, нижний элемент переходит вверх
- rrb - сдвинуть все элементы в стэке b вниз, нижний элемент переходит вверх
- rrr - rra + rrb
___
#### Пример использования
![](https://i.imgur.com/TJADSze.png "пример")
