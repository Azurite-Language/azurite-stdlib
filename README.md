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
The rule is: any library must contain a macro whose name is the same as the file name. and whose take one paratemers which is the name of the language.
