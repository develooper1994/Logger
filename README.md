# Logger
The code snippet provided demonstrates the process of starting the logging functionality using a class called "Logger." The Logger class is designed to provide an easy-to-use interface for logging messages in a C++ application. 

To begin the logging process, the code initializes the Logger by calling its static function `attach()`. Before that, it outputs an information message using the `qInfo()` function from the "MainCategory" category, indicating the current file being logged, which is accessed through the `Utilities::Logger::filename` variable.

Once the `attach()` function is invoked, the Logger class will be activated, and subsequent log messages will be captured and processed according to the logging configuration.

Overall, the provided code snippet offers a simple and straightforward way to initialize and start logging within a C++ application using the Logger class, making it easier to track and analyze runtime information and potential issues.

# Start the logging process
```c++
    // Logger başlasın.
    qInfo(MainCategory) << "File:" << Utilities::Logger::filename;
    Utilities::Logger::attach();
```

## Note: 
  - I have inspired from voidrealm udemy tutorials.
  - There is a colorization bug i cannot fix right now.
