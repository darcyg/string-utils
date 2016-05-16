# string-utils
This library implements many commonly used but not natively supported function in **std::string**, like `str_split`, `str_join`, `str_trim`, `str_compact`, `str_replaceall`, `str_tolower`, `str_toupper`, `str_repeat`, `str_readfile`, `str_writefile`, `str_between`, `str_between_array`, `str_to_hex`, `str_left`, `str_right`

## str_split

```c++
vector<string> v = str_split("one,two,three", ","); // v: ["one", "two", "three"]
```
  
## str_join

```c++
vector<string> v;
v.push_back("1");
v.push_back("2");
v.push_back("3");
string s = str_join(v, ":"); // s: "1:2:3"
```

## str_trim

```c++
string s = str_trim(" hi "); // s: "hi"
```

## str_compact

remove empty string

```c++
vector<string> v;
v.push_back("1");
v.push_back("");
v.push_back("2");
v.push_back("3");
v.push_back("");
// v: ["1", "", "2", "3", ""]
v = str_compact(v);
// v: ["1", "2", "3"]
```

## str_replaceall

```c++
vector<string> v = str_replaceall("1-2-3-4", "-", "#"); // v: "1#2#3#4"
```

## str_tolower

```c++
string s = str_tolower("ABCD"); // s: "abcd"
```

## str_toupper

```c++
string s = str_toupper("abcd"); // s: "ABCD"
```

## str_repeat

```c++
string s = str_repeat("#", 5); // s: "#####"
```

## str_readfile

read file to string

```c++
string content = str_readfile(...file path...);
```

## str_writefile

write string to file

```c++
string content = "...";
str_writefile(...file path..., content);
```

## str_between

```c++
string s = str_between("abc","a","c");// s: "b"
```

## str_between_array

```c++
vector<string> v = str_between_array("abcabcabc", "a", "c");// v: // v: ["b", "b", "b"]
```

## str_left

```c++
string s = str_left("abc","b");// s: "a"
```

## str_right

```c++
string s = str_right("abc","b");// s: "c"
```

## str_to_hex

```c++
string s = str_to_hex("abc");// s: "0x61 0x62 0x63"
```
