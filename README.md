# unfoldcon

Unfold continuation lines. Prepend every line that ends with a "\" character to
the next line. Remove any leading blanks from the continuation line.


## Usage

Consider the following file:

```sh
    $ cat example.txt
      This is a \
        continuation line.
    But these
      are not.
```

unfoldcon reads from stdin en writes to stdout:

```sh
    $ cat example.txt | unfoldcon
      This is a continuation line.
    But these
      are not.
```


## Installation

    $ git clone https://github.com/timkuijsten/unfoldcon.git
    $ cd unfoldcon
    $ cc unfoldcon.c -o unfoldcon


## License

ISC

Copyright (c) 2016 Tim Kuijsten

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
