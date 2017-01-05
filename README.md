### Assignment 4
##### Searching, Sorting, Counting
This is a tiny diversion from our larger project to explore data processing. The goal of this assignment is to exercise data processing and manipulation. This is possibly the most important programming skill you can become comfortable with. As you grow you will use techniques like this on a daily basis.

##### Here is what you will build:
###### An Analysis Tool

1. Build an application that once again uses command line arguments. You now that `argv` thing from assignemnt 2. We are going to have a number of commands our application will support.
  1. The first argument `argv[1]` will be a file path to a datafile to process and that datafile will look a little something like this
    ```txt
    how now brown cow
    1 2 3 4 5 6 7 8
    livevil
    the purpose of life is to challenge yourself and explore the limits of your abilities otherwise how would you push those limits.
    ```
  2. the second argument `argv[2]` will be one of the following
    - `search <query>` 
        - In the event of search we will add an additional argument `argv[3]` which will represent what to search for. Your program will return the line position and line number of each match to the query.
        - example `assign4.exe ./data.txt search how`
    - `sort <asc|desc>`
      - In the event of sort you will sort each line in the file using the criteria provided by `argv[3]`. The criteria will be ascending or descending using the shorthand `asc` or `desc`. You should try and use selection or bubble sort as your sorting algorithm.
    - `count`
        - In the event of count you will count the number of instances of every character in the entire file and return the most used and least used characters. Please feel free to exclude things that are not letters and numbers like punctuation and spaces. A __HINT__ here would be to use 2 arrays one to keep the order of the letters and another to keep the count of those letters in the same order. The point of this is that the index of `a` should match the index of its count in the other array. These are called parallel arrays.
2. Have your program produce output to a text file in the same directory as the running application. I would recommend modifying the workding directory in your build configuration of CLion to make finding the created file easier. Do not "absolute" the path to your output file. It must use the relative path `./report.txt`. Absolute paths being with `C:/` where relative paths start with `.`
  - when outputting `search` make your report includes the query and each match should be listed on its own line. Feel free to use 0 based counts or 1 based counts just be consistent
  - output should look something like this with 0 based counts using the txt file above. I would like to point out that the text file has only 4 real lines not 5. The last line wraps.
    ```txt
    Searched for: "how"
    Located on:
    Pos   Line
    0     0
    96    3
    ```
  - when outputting `sort` make your report reproduce the lines in the same order as the input file but with each line's contents sorted and should include the intended sort direction.
  - when outputting count your output file should look like this
    ```txt
    Most common character: e
    Least common character: i
    ```
3. Do not use `cin` rely completely on the argument list provided by the command line or through the argument list in the build configuration for your testing.
4. Do not use `cout` rely completely on outputting a file in the directory local to the working directory by using `./` on your results path. This doesn't mean you can't use `cout` for testing but your final product should not use them.
