# saccalc - simple ascii C calculator

## What it does

It's a RPN calcultor that takes input from stdin. As a side effect, it can take simple programs.

## How it works

Sends ANSI terminal sequences.

## Limitations

This program depends on a good implementation of doubles.

## How to build

You can use the provided build.sh script. It should work with 99% of UNIX systems.
On Windows, you can probably use cl if you have Visual Studio installed (not tested).

You can test the build with ./saccalc < test.sac, which should output:
```
4 0x4
1.414213562373095 0x1
0.1111111111111111 0x0
512 0x200
inf 0x0
2882400066 0xabcdef42
```

## How to use

Type a number or a command, then press enter.  
Here is a list of all commands:  
```
+ : Add
- : Substract
* : Multiply
/ : Divide
c : Repeat last number
% : Remainder
< : Left shift
> : Right shift
s : Square root
```
## Copyright stuff

This program is licensed under the zlib/libpng license. See LICENSE file for details.



