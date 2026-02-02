# My-Ls – Reproduction of the Unix `ls` Command in C

## Description

My-Ls is a re-implementation of the Unix `ls` command written in C.  
The project consists of browsing the contents of a directory, retrieving file data, and displaying it in a formatted way while respecting the behavior of the original command.

## Project Goals

- Understand directory manipulation in C
- Use Unix system calls
- Manage file permissions and metadata
- Structure a project while respecting EPITECH coding standards

## Technologies Used

- C language
- Unix system calls (`opendir`, `readdir`, `stat`, etc.)
- Makefile

## Implemented Features

- Directory content reading
- File listing display
- Permission handling
- Metadata retrieval using `stat`
- Error handling

## Compilation

make

## Usage

./my_ls -l include/
