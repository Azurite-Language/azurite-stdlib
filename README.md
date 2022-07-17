# azurite-stdlib
not yet standard azurite library

## Usage
Include the file with this syntax.
```lisp
(import "filepath/my_file")
```
Then you can enable the feature for this file with:
```lisp
(my_file lang)
```

Library: every files must contain a macro whose name is the same as the file name which take one paratemer, the name of the language.
```lisp
(import "filepath/foo")
(foo azur)
```
Language support: once the file is import every functionality should be activated.
