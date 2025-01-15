## Simple code project done to play around with developing a C workflow. 
Translates a number into its word equivalent up to 999,999. 
e.g. "six hundred and fifty thousand one hundred and twenty three" == 650123

## Quickstart

You will need `make`, `clang` and `lldb` installed. 
These are present by default on macOS, and on Ubuntu can be installed with
`sudo apt install clang lldb`.

```shell
# Clone the repo, download a zip, or run...
; mkdir my-c-project && cd my-c-project
; npx degit neoeno/toy-c-project-template

# Check `make`, `clang` and `lldb` are installed
; make check

# To build and run `src/main.c`
; make run

# To run the tests in `src/test.c`
; make test

# To start `src/main.c` in the debugger
; make debug

# To start `src/test.c` in the debugger
; make debug-test
```

## Tests

This project uses a very basic set of C macros to facilitate tests. You can see
examples of this in `src/test.c`.

