#!/usr/bin/env fish

# Find all C files recursively in subdirectories
for file in (find . -name '*.c')
    if test -f "$file"
        set filename (basename "$file" .c)
        set output_path (dirname "$file")
        clang -o "$output_path/$filename" "$file"
        if test $status -eq 0
            echo "Compilation successful for $file"
        else
            echo "Error compiling $file"
        end
    end
end

