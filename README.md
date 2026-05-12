# sish — A Simple Shell in C

A minimal Unix shell written in C, built as a first systems programming project. Supports command execution, dynamic input buffering, and a clean exit.

---

## Features

- **Command execution** — runs any program available in your `PATH` using `execvp`
- **Dynamic input buffering** — handles arbitrarily long input lines by reallocating memory as needed
- **Tokenization** — splits input on spaces, tabs, and newlines using `strtok`
- **Graceful exit** — type `exit` to quit the shell cleanly
- **Color-coded errors** — fork and allocation errors are highlighted in red

---

## Installation & Usage

**Requirements:**
- GCC
- A Unix-like OS (Linux / macOS)

**Build:**
```bash
gcc shell.c -o sish
```

**Run:**
```bash
./sish
```

**Example:**
```
> ls -la
> echo hello world
> exit
```

---

## Known Limitations

- No support for piping (`|`) or I/O redirection (`>`, `<`)
- No built-in `cd` command — directory changes are not possible
- No command history
- Only one built-in command: `exit`
- Empty input (pressing Enter) previously caused a crash — fixed with a null guard on `args[0]`
