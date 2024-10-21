# Libft - Your Very First C Library

## Overview
**Libft** is a project aimed at developing a custom C library from scratch. This library includes a collection of fundamental C functions that are frequently used in programming. These functions are recreated to deepen the understanding of their functionality and implementation. It serves as a tool that will be useful in future projects, making coding in C more efficient.

## Table of Contents
- [Introduction](#introduction)
- [Common Instructions](#common-instructions)
- [Mandatory Part](#mandatory-part)
  - [Libc Functions](#libc-functions)
  - [Additional Functions](#additional-functions)
- [Bonus Part](#bonus-part)
- [Submission and Evaluation](#submission-and-evaluation)

## Introduction
The **Libft** project is designed to give you hands-on experience with C programming by building a foundational library. You will replicate a set of functions from the C Standard Library (libc) and implement additional utility functions.

## Common Instructions
- The project must be written in C and comply with the Norm.
- It must include a `Makefile` to compile the source files with the flags `-Wall`, `-Wextra`, and `-Werror`.
- No global variables are allowed.
- Proper memory management is required; no memory leaks will be tolerated.
- All `.c` files must compile without errors.
- The following Makefile rules are mandatory: `$(NAME)`, `all`, `clean`, `fclean`, `re`.
- The `libft.a` library must be created at the root of the repository.

## Mandatory Part
### Libc Functions
The project starts with implementing several libc functions, each beginning with the `ft_` prefix. The functions include:
- Character checks (`ft_isalpha`, `ft_isdigit`, etc.)
- String manipulation (`ft_strlen`, `ft_strchr`, etc.)
- Memory functions (`ft_memset`, `ft_memcpy`, etc.)
- Conversion functions (`ft_atoi`, etc.)

### Additional Functions
In this section, additional utility functions are implemented:
- `ft_substr`, `ft_strjoin`, `ft_strtrim`
- `ft_split`, `ft_itoa`, `ft_strmapi`, etc.

## Bonus Part
The bonus part involves implementing linked list functions, which include creating new nodes, adding/removing nodes, and iterating over lists. The bonus part is only evaluated if the mandatory part is completed perfectly.

## Submission and Evaluation
All submissions must be done through the assigned Git repository. Only the work present in the repository will be graded. Make sure all files are placed at the root of the repository.

## Getting Started
### Prerequisites
- GCC or any C compiler
- Git for version control

### Installation
1. Clone this repository:
   ```bash
   git clone <repository_url>
   cd libft
