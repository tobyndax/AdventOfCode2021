# Advent of Code 2021

[![Build](https://github.com/tobyndax/projectPlayground/actions/workflows/main.yml/badge.svg)](https://github.com/tobyndax/projectPlayground/actions/workflows/main.yml)

## Installing Bazel
The recommended way of installing Bazel is Bazelisk.

Lets try it out.
It can be installed via binary release, npm or homebrew, lets try npm.
`npm install -g @bazel/bazelisk`


## Compiling and running

`bazel run src/main:main`

## Running tests

`bazel test tests:tests`

## Formatting
A pre-commit hook for clang-format and other whitespace issues for yaml files and eol issues is set up.
This uses the pre-commit framework, which makes things such as which version of clang-format being used, much more
convenient.

### Pre Commit installation
[Pre-Commit](https://pre-commit.com/#install).
Basically run `pip install pre-commit`

### Running formatting
Running `pre-commit run --all-files` formats all .cpp and .h files inplace, and checks for other issues.
`pre-commit run` does the same but for all changed files.
