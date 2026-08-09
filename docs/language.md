# Emerald Language Specification

Version: 0.0.0

This document describes the syntax and semantics of the Emerald programming language.

Emerald is an object-oriented programming language with a portable virtual machine, distributed object support, and interoperability with C.

---

# 1. Lexical Structure

## 1.1 Source files

Emerald source files use the `.em` extension.

Example

```emerald
Main.em
hello.em
qwerty.em
```

## 1.2 Comments

Single-line comments:

```emerald
-- This is a comment
```

Block comments:

```emerald
(*
    This is a block comment
*)
```

## 1.3 Identifiers

Identifiers may contain:

- letters
- digits
- `_`

The first character must not be a digit.

Examples:

```
counter
myObject
printHello
```

---

# 2. Keywords

```
new
object
module
const
var
operation
export
process
initially
if
elseif
else
loop
while
return
end
```

---

# 3. Primitive Types

- Integer
- Real
- Boolean
- Character
- String
- Nil

---

# 4. Objects

Everything is built around objects. Objects encapsulate state and behavior, and program execution occurs through interactions between objects.
Objects are the fundamental units of computation in Emerald.

Example:

```emerald
const Main: object = new object Main {
   --- something beautiful
}
```

---

# 5. Modules

Modules are used to organize Emerald programs into independent units and provide a namespace for objects, types, and operations.

A module can contain multiple objects and expose only the parts of its implementation that are intended to be used by other modules.

Modules allow large programs to be divided into smaller, reusable components while keeping their internal implementation separated from the rest of the program.

Exemple:

```emerald
const io: module = import std.stdio
```

---

# 6. Variables

Mutable variable:

```emerald
var count : Integer
```

Immutable variable:

```emerald
const PI : Real = 3.14
```

---

# 7. Operations

```emerald
operation add(a : Integer, b : Integer) -> Integer {
    return a + b
}
```

---

# 8. Object Initialization

```emerald
initially {
    --- Initialization code
}
```

---

# 9. Processes

In development

---

# 10. Distributed Objects

In development

---

# 11. C Interoperability

In development

---

# 12. Standard Library

In development

---

# 13. Virtual Machine

In development

---

# 14. Bytecode

In development
