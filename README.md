# Welcome to My Libft Project!

## Hey There!
If you’re here, it probably means you’re curious about my very first custom C library, **Libft**. This project is all about recreating some of the most fundamental functions from the C Standard Library (libc), but with my own twist. It's not just about writing code; it's about understanding how things work under the hood, which is pretty exciting!

## Table of Contents
- [What’s This All About?](#whats-this-all-about)
- [The Common Instructions](#the-common-instructions)
- [What I Built (Mandatory Part)](#what-i-built-mandatory-part)
  - [Recreated Libc Functions](#recreated-libc-functions)
  - [Additional Functions I Added](#additional-functions-i-added)
- [Going the Extra Mile (Bonus Part)](#going-the-extra-mile-bonus-part)
- [How to Try It Out](#how-to-try-it-out)

## What’s This All About?
This is my attempt to build a foundational C library from scratch. The goal is to replicate many of the standard C functions that we all use and love (like `strlen`, `memset`, etc.) but under the **ft_** prefix (e.g., `ft_strlen`). Plus, I’ve thrown in some additional utility functions that I think are pretty handy.

If you’ve ever found yourself frustrated by C’s quirks, I think you’ll appreciate what’s in this library—especially since it’s meant to be built upon and improved over time.

## The Common Instructions
Let’s get technical for a second:
- This project is written in C, following the 42 School’s Norm guidelines.
- Everything is compiled with the flags: `-Wall`, `-Wextra`, `-Werror`.
- There’s a `Makefile` included to make your life easier (and mine too).
  - The rules are: `all`, `clean`, `fclean`, `re`, and, of course, `bonus`.
- **No global variables** allowed (yep, you heard it right).
- Memory management is key: no leaks or it’s game over.

## What I Built (Mandatory Part)
### Recreated Libc Functions
Here’s where it gets interesting. I took on the challenge of implementing a bunch of libc functions from scratch. Here are some examples:
- **Character checks**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, etc.
- **String manipulation**: `ft_strlen`, `ft_strchr`, `ft_strrchr`, etc.
- **Memory handling**: `ft_memset`, `ft_memcpy`, `ft_memmove`, etc.
- **Conversions**: `ft_atoi`, and more!

### Additional Functions I Added
I also added a few extras to make life easier:
- **Substring extraction**: `ft_substr`
- **String join**: `ft_strjoin`
- **String trim**: `ft_strtrim`
- **String split**: `ft_split`
- **Integer to string conversion**: `ft_itoa`

All of these are implemented with dynamic memory allocation, so be sure to free the memory when you’re done!

## Going the Extra Mile (Bonus Part)
I didn’t just stop at the basics! If the mandatory part is solid, the bonus part comes into play. This part is all about working with **linked lists**, which is where things get even more useful. I implemented functions like:
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstclear`, and more!

I made sure to follow the same coding standards, so it’s all integrated seamlessly into the main library.

## How to Try It Out
If you want to give it a spin, here’s how to get started:

### Prerequisites
- You’ll need a C compiler (like GCC) and Git for version control.

### Installation
1. Clone this repository:
   ```bash
   git clone <repository_url>
   cd libft
