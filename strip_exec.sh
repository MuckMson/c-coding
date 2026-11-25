#!/bin/sh
# Рекурсивно переименовывает бинарные файлы без расширения: exec_filename -> _filename
#
# Использование:
#   ./strip_exec.sh /путь/к/папке            # пробный запуск
#   ./strip_exec.sh /путь/к/папке --apply    # реально переименовать

dir=${1:?"Укажите папку: $0 /путь/к/папке [--apply]"}
apply=0
[ "$2" = "--apply" ] && apply=1

[ -d "$dir" ] || { echo "Не папка: $dir" >&2; exit 1; }

find "$dir" -type f -name 'exec_?*' ! -name '*.*' | while IFS= read -r src; do
    # пустые и текстовые файлы пропускаем (grep -I считает бинарные файлы "не совпавшими")
    [ -s "$src" ] || continue
    if grep -qI . "$src" 2>/dev/null; then
        continue
    fi

    d=$(dirname "$src")
    name=$(basename "$src")
    new="${name#exec}"
    dst="$d/$new"

    if [ -e "$dst" ]; then
        echo "ПРОПУСК (уже существует): $dst"
        continue
    fi

    echo "$src  ->  $new"
    [ "$apply" -eq 1 ] && mv -n "$src" "$dst"
done

[ "$apply" -eq 1 ] || echo "Это был пробный запуск, добавьте --apply для переименования."
