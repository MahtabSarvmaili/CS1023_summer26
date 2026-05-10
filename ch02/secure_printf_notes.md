# Secure printf Notes

## Unsafe Program

Input used:

```text
%x %x %x
```

Output:

```text
ff760000 fffffffc ff912d40
```

The unsafe program used `printf(userInput);`. This is unsafe because the user input became the format string.

## Fixed Program

Input used:

```text
%x %x %x
```

Output:

```text
%x %x %x
```

The fixed program used `printf("%s", userInput);`. This is safer because the format string is fixed and the user input is printed as normal text.

### Evidence

![Secure printf notes file](images/secure_printf_notes_file.png)

### Commit Commands

```powershell
git status
git add ch02/printf_unsafe_example.c ch02/printf_fixed_example.c ch02/secure_printf_notes.md
git commit -m "Explore secure printf examples"
git push
```
