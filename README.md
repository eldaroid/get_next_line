![42 stats](https://badge42.herokuapp.com/api/stats/fgracefo?cursus=42&privacyEmail=true)

# GET_Next_Line
Суть проекта заключается в создании функции, которая позволила бы считывать из файла строку за строкой. Так, например, вызывая ее в цикле, можно было бы считать весь файл. Более подробная информация размещена в папке [`get_next_line.en.pdf`](resources/get_next_line.en.pdf). Данный проект был реализован с помощью раннее написанной библиотеки [libft](https://github.com/eldaroid/libft-fgracefo). Данный проект был завершен 8го октября 2019 года и оценен на [![42Project Score](https://badge42.herokuapp.com/api/project/fgracefo/GET_Next_Line)](https://github.com/JaeSeoKim/badge42)

### Ключивые моменты проекта
Самой важной частью было понимание того, как такая функция может работать при ее неоднократном использовании. Ответ был найден в концепцией статических переменных.
В проекте также введено понятие утечек памяти, что очень важно как для get_next_line, так и для всех последующих проектов. Утечек быть не должно.
