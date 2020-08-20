# GET_Next_Line
Суть проекта заключается в создании функции, которая позволила бы считывать из файла строку за строкой. Так, например, вызывая ее в цикле, можно было бы считать весь файл. Более подробная информация размещена в папке *resources*. Данный проект был реализован с помощью раннее написанной библиотеки [libft](https://github.com/eldaroid/libft-fgracefo).

### Ключивые моменты проекта
Самой важной частью было понимание того, как такая функция может работать при ее неоднократном использовании. Ответ был найден в концепцией статических переменных.
В проекте также введено понятие утечек памяти, что очень важно как для get_next_line, так и для всех последующих проектов. Утечек быть не должно.
