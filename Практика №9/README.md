0. конфигурируем гит в терминале
![[Screenshots/Screenshot 2026-11-11 at 11.15.11 AM.png]]

1.  мы находимся в ветке main, видны неотслеживаемые скрытые файлы Finder и скриншоты.![[Screenshots/Screenshot 2026-11-11 at 11.16.30 AM.png]]
2. `git log` вывел историю коммитов этого репозитория. Можно ранние увидеть коммиты синхронизации из Obsidian.![[Screenshots/Screenshot 2026-11-11 at 11.18.23 AM.png]]
3. Напишем функцию сталинской сортировки на C и сохраним его в папку лабораторной:![[Screenshots/Screenshot 2026-11-17 at 10.01.32 AM.png|563]]
4. Проверим состояние в git status:![[Screenshots/Screenshot 2026-11-17 at 10.03.45 AM.png]]Появляется сообщение о удаленном файле README.md.md, так как он был переименован в README.md. В списке неотслеживаемых файлов отображаются скрытые папки и файлы программы Finder (.DS_Store), а также наши README.md и  stalin_sort.c.
5. Добавим эти файлы в область stage: ![[Screenshots/Screenshot 2026-11-17 at 10.07.59 AM.png]]
6. Коммитим изменения:![[Screenshots/Screenshot 2026-11-17 at 10.14.55 AM.png]]
7. Проверим git status:![[Screenshots/Screenshot 2026-11-17 at 10.15.43 AM.png]]
8. Добавим в скрипт сортировки комментарий:![[Screenshots/Screenshot 2026-11-17 at 10.17.58 AM.png]]
9. Проверим git status:![[Screenshots/Screenshot 2026-11-17 at 10.19.03 AM.png]]
10. Добавим с помощью git add изменения в коммит:![[Screenshots/Screenshot 2026-11-17 at 10.20.14 AM.png]]
11. Да, я думаю вы уже поняли, что мы снова будем делать:![[Screenshots/Screenshot 2026-11-17 at 10.21.41 AM.png]]
12. Добавим еще комментарий![[Screenshots/Screenshot 2026-11-17 at 10.23.34 AM.png]]
13. Коммититм и пушим:![[Screenshots/Screenshot 2026-11-17 at 10.28.55 AM.png]]
14. ![[Screenshots/Screenshot 2026-11-17 at 10.29.18 AM.png]]![[Screenshots/Screenshot 2026-11-17 at 10.29.46 AM.png]]
15. ![[Screenshots/Screenshot 2026-11-17 at 10.28.12 AM.png]]
16. ![[Screenshots/Screenshot 2026-11-17 at 10.30.28 AM.png]]

# Ветки
1. ![[Screenshots/Screenshot 2026-11-17 at 10.31.34 AM.png]]
2. ![[Screenshots/Screenshot 2026-11-17 at 10.31.58 AM.png]]
3. ![[Screenshots/Screenshot 2026-11-17 at 10.32.19 AM.png]]
4. ![[Screenshots/Screenshot 2026-11-18 at 12.54.59 AM.png]]
5. ![[Screenshots/Screenshot 2026-11-18 at 12.56.00 AM.png]]
6. ![[Screenshots/Screenshot 2026-11-18 at 1.07.58 AM.png]]![[Screenshots/Screenshot 2026-11-18 at 1.07.43 AM.png]]![[Screenshots/Screenshot 2026-11-18 at 1.08.16 AM.png]]
7. ![[Screenshots/Screenshot 2026-11-18 at 1.10.12 AM.png]]
8. ![[Screenshots/Screenshot 2026-11-18 at 1.14.26 AM.png]]
9. ![[Screenshots/Screenshot 2026-11-18 at 9.54.18 AM.png]]
10. Вот что изменилось: в git log для ветки main показваются коммиты, соответствующие только главной ветке, в то время как для mybranch там указываются все коммиты до ответвления и далее только коммиты этой ветки.![[Screenshots/Screenshot 2026-11-18 at 9.54.37 AM.png]]
11. ![[Screenshots/Screenshot 2026-11-18 at 10.01.39 AM.png]]
12. ![[Screenshots/Screenshot 2026-11-18 at 10.02.15 AM.png]]
13. ![[Screenshots/Screenshot 2026-11-18 at 10.02.39 AM.png]]
14. Да, пропал,  так как это другая ветка и туда text2.txt мы не добавляли.
15. Разница между ветками в том, что в `main` нет файлов .gitignore, applewatch.jpeg, file1.txt и meme.jpeg, meme.txt, зато есть text2.txt. То есть mybranch содержит файлы, которых нет в main, а main содержит text2.txt, которого нет в mybranch![[Screenshots/Screenshot 2026-11-18 at 10.03.58 AM.png]]
16. ![[Screenshots/Screenshot 2026-11-18 at 10.08.58 AM.png]]
17.