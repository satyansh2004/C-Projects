# Matrix Library (C)

A simple C static library for matrix operations.

## Build from Source

Clone the repository:

```bash
git clone <repository-url>
cd matrix-lib
```

Compile:

```bash
make
```

Install system-wide:

```bash
sudo make install
```

## Usage

Create a file named `example.c`:

```c
#include <stdio.h>
#include <stdlib.h>
#include <matrix.h>

int main(void)
{
    int a_data[] = {1, 2, 3, 4};
    int b_data[] = {5, 6, 7, 8};

    _MAT a = {a_data, 2, 2};
    _MAT b = {b_data, 2, 2};
    _MAT result;

    if (mat_addition(&result, &a, &b) != NULL) {
        mat_display(&result);
        free(result.data);
    }

    return 0;
}
```

Compile and link:

```bash
gcc example.c -lmatrix -o app
```

Run:

```bash
./app
```

Output:

```text
6 8
10 12
```

## Use Without Installing

If you already have the compiled library and header:

```bash
gcc example.c -I./lib -L./lib -lmatrix -o app
```

## Clean

```bash
make clean
```