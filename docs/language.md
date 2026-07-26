# Emerald Language Specification

Version: 0.0.0

This document describes the syntax and semantics of the Emerald programming language.

Emerald is an object-oriented programming language with a portable virtual machine, distributed object support, and interoperability with C.

---

# 1. Lexical Structure

## 1.1 Source files

Emerald source files use the `.em` extension.

Example:

```emerald
const Main <- object Main
end Main
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
object
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

Objects are the primary programming construct in Emerald.

Example:

```emerald
const Main <- object Main

end Main
```

---

# 5. Variables

Mutable variable:

```emerald
var count : Integer
```

Immutable variable:

```emerald
const PI : Real <- 3.14
```

---

# 6. Operations

```emerald
operation add[a : Integer, b : Integer] -> Integer
    return a + b
end add
```

---

# 7. Object Initialization

```emerald
initially
    stdout.putstring["Hello"]
end initially
```

---

# 8. Processes

In development

---

# 9. Distributed Objects

In development

---

# 10. C Interoperability

In development

---

# 11. Standard Library

In development

---

# 12. Virtual Machine

In development

---

# 13. Bytecode

In development
