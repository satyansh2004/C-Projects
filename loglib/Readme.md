# Logging Library (C)

A small, dependency-free logging library for C. It prints colored log messages for three levels — info, warning, and error — and can be fully disabled at compile time with zero runtime cost.

## Features

- Three log levels: `LOG_INFO`, `LOG_WARN`, `LOG_ERROR`
- Colored terminal output (light blue, yellow, red)
- Disabled by default; compiles to an empty function when turned off
- Needs only the C standard library

## Build

```bash
cd loglib
make        # builds liblogs.a
make clean  # removes liblogs.a and liblogs.o
```

## API

Include the header in your source file:

```c
#include "log.h"
```

The public interface is:

```c
typedef enum {
  LOG_INFO,
  LOG_WARN,
  LOG_ERROR,
} _LOG_TYPE;

void print_log(char *log_message, _LOG_TYPE log_type);
```

| Log type    | Color      | Prefix  |
| ----------- | ---------- | ------- |
| `LOG_INFO`  | Light blue | `[INF]` |
| `LOG_WARN`  | Yellow     | `[WRN]` |
| `LOG_ERROR` | Red        | `[ERR]` |

## Enabling Logs

Logging is turned off by default because `ENABLE_LOG` defaults to `0`; when off, `print_log()` does nothing. Rebuild the library to change it:

```bash
make enable-log     # turn logging on
make disable-log    # turn logging off
```

You can also set the value directly:

```bash
make ENABLE_LOG=1
```

The setting is baked into `liblogs.a`, so it applies when the library is built — your own program does not need any `-D` flag.

## Example

Create `example.c`:

```c
#include "log.h"

int main(void) {
  print_log("Application started", LOG_INFO);
  print_log("Low disk space", LOG_WARN);
  print_log("Failed to open config file", LOG_ERROR);

  return 0;
}
```

Build and run it against the library:

```bash
gcc example.c -Iloglib -Lloglib -llogs -o example
./example
```

Output:

```text
[INF] Application started
[WRN] Low disk space
[ERR] Failed to open config file
```
