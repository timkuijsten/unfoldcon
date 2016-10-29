/*
 * Copyright (c) 2016 Tim Kuijsten
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <err.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

enum states { NORM, ESCAPE };

/* unfold continuation lines, lines that end with a "\" */
int
main(int argc, char *argv[])
{
  char c;
  enum states state;

  if (argc != 1)
    errx(1, "usage: unfoldcon");

  while ((c = getc(stdin)) != EOF)
    switch (state) {
    case NORM:
      switch (c) {
      case '\\':
        /* wait for next char */
        state = ESCAPE;
        break;
      default:
        putc(c, stdout);
      }
      break;
    case ESCAPE:
      switch (c) {
      case '\n':
        /* swallow \ + \n */
        break;
      default:
        putc('\\', stdout);
        putc(c, stdout);
      }
      state = NORM;
      break;
    }

  if (ferror(stdin))
    err(1, NULL);

  return 0;
}