0. конфигурируем гит в терминале
![](Screenshots/Screenshot%202026-11-11%20at%2011.15.11%20AM.png)

1.  мы находимся в ветке main, видны неотслеживаемые скрытые файлы Finder и скриншоты.![](Screenshots/Screenshot%202026-11-11%20at%2011.16.30%20AM.png)
2. `git log` вывел историю коммитов этого репозитория. Можно ранние увидеть коммиты синхронизации из Obsidian.![](Screenshots/Screenshot%202026-11-11%20at%2011.18.23%20AM.png)
3. Напишем функцию сталинской сортировки на C и сохраним его в папку лабораторной:<img src="Screenshots/Screenshot%202026-11-17%20at%2010.01.32%20AM.png" width="563">
4. Проверим состояние в git status:![](Screenshots/Screenshot%202026-11-17%20at%2010.03.45%20AM.png)Появляется сообщение о удаленном файле README.md.md, так как он был переименован в README.md. В списке неотслеживаемых файлов отображаются скрытые папки и файлы программы Finder (.DS_Store), а также наши README.md и  stalin_sort.c.
5. Добавим эти файлы в область stage: ![](Screenshots/Screenshot%202026-11-17%20at%2010.07.59%20AM.png)
6. Коммитим изменения:![](Screenshots/Screenshot%202026-11-17%20at%2010.14.55%20AM.png)
7. Проверим git status:![](Screenshots/Screenshot%202026-11-17%20at%2010.15.43%20AM.png)
8. Добавим в скрипт сортировки комментарий:![](Screenshots/Screenshot%202026-11-17%20at%2010.17.58%20AM.png)
9. Проверим git status:![](Screenshots/Screenshot%202026-11-17%20at%2010.19.03%20AM.png)
10. Добавим с помощью git add изменения в коммит:![](Screenshots/Screenshot%202026-11-17%20at%2010.20.14%20AM.png)
11. Да, я думаю вы уже поняли, что мы снова будем делать:![](Screenshots/Screenshot%202026-11-17%20at%2010.21.41%20AM.png)
12. Добавим еще комментарий![](Screenshots/Screenshot%202026-11-17%20at%2010.23.34%20AM.png)
13. Коммититм и пушим:![](Screenshots/Screenshot%202026-11-17%20at%2010.28.55%20AM.png)
14. ![](Screenshots/Screenshot%202026-11-17%20at%2010.29.18%20AM.png)![](Screenshots/Screenshot%202026-11-17%20at%2010.29.46%20AM.png)
15. ![](Screenshots/Screenshot%202026-11-17%20at%2010.28.12%20AM.png)
16. ![](Screenshots/Screenshot%202026-11-17%20at%2010.30.28%20AM.png)

# Ветки
1. ![](Screenshots/Screenshot%202026-11-17%20at%2010.31.34%20AM.png)
2. ![](Screenshots/Screenshot%202026-11-17%20at%2010.31.58%20AM.png)
3. ![](Screenshots/Screenshot%202026-11-17%20at%2010.32.19%20AM.png)
4. ![](Screenshots/Screenshot%202026-11-18%20at%2012.54.59%20AM.png)
5. ![](Screenshots/Screenshot%202026-11-18%20at%2012.56.00%20AM.png)
6. ![](Screenshots/Screenshot%202026-11-18%20at%201.07.58%20AM.png)![](Screenshots/Screenshot%202026-11-18%20at%201.07.43%20AM.png)![](Screenshots/Screenshot%202026-11-18%20at%201.08.16%20AM.png)
7. ![](Screenshots/Screenshot%202026-11-18%20at%201.10.12%20AM.png)
8. ![](Screenshots/Screenshot%202026-11-18%20at%201.14.26%20AM.png)
9. ![](Screenshots/Screenshot%202026-11-18%20at%209.54.18%20AM.png)
10. Вот что изменилось: в git log для ветки main показваются коммиты, соответствующие только главной ветке, в то время как для mybranch там указываются все коммиты до ответвления и далее только коммиты этой ветки.![](Screenshots/Screenshot%202026-11-18%20at%209.54.37%20AM.png)
11. ![](Screenshots/Screenshot%202026-11-18%20at%2010.01.39%20AM.png)
12. ![](Screenshots/Screenshot%202026-11-18%20at%2010.02.15%20AM.png)
13. ![](Screenshots/Screenshot%202026-11-18%20at%2010.02.39%20AM.png)
14. Да, пропал,  так как это другая ветка и туда text2.txt мы не добавляли.
15. Разница между ветками в том, что в `main` нет файлов .gitignore, applewatch.jpeg, file1.txt и meme.jpeg, meme.txt, зато есть text2.txt. То есть mybranch содержит файлы, которых нет в main, а main содержит text2.txt, которого нет в mybranch![](Screenshots/Screenshot%202026-11-18%20at%2010.03.58%20AM.png)
16. ![](Screenshots/Screenshot%202026-11-18%20at%2010.08.58%20AM.png)
17. 