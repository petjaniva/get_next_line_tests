Tests for Hive Helsinki's GET_NEXT_LINE project. Tests follow the evaluation form of the project, but there are also extra tests, but nothing extra tricky I think. Tests follow my own understanding of the subject and passing them doesn't mean you will pass the project and failing them don't mean you will fail.

Some of the tests use https://nemequ.github.io/munit/ framework, but some are done just with basic c assert or shell commands. You need Valgrind for the memory leak test.

1. Clone into a subfolder in your GNL-project folder. For example: ~/get_next_line/tests/
2. run 'make'
3. 'make test_all' runs all tests, but there is quite a bit of output so it is hard to read.


'make basic' runs the basic tests from the evaluation form.

'make middle' runs the middle tests from the evaluation form.

'make advanced' runs most of the advanced tests from the evaluation form.

'make extra' tests reading an empty file from advanced tests of the form and tests error management.

'make error' runs the extra tests with the different buffer sizes specified in the evaluation form.

'make multi_fd' runs tests for handling reading from multiple files without finishing the previous file.

'make leaks' tests for memory leaks. You need to have valgrind installed for this to work.

'make stdin' an extra stdin reading test.
