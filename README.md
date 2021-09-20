### Run test
1. Create test-case:
    - Create new folder in ```test``` (e.g. ```test_basic```)
    - New folder contain 3 files:
        - ```sample.args``` contain command line arguments for test *(optional)*
        - ```sample.in``` contain input for test *(optional)*
        - ```sample.ref``` store expected output *(required)*

2. Customize your building script in ```Makefile```
    - Your script must have ```all``` target
    - Do not delete the available ```test``` target

3. Running test:
    - Execute test: 
    ```sh
    $ make test
    ```
    - In each test case folder, new file ```sample.out``` is generated to store the output and compare the result with ```sample.ref```

