Embeddedfella
Library Management System – C++ Console Application
Project Overview
Embeddedfella is a library management system developed as a portfolio project to demonstrate robust C++ programming and embedded systems design principles. The goal of this project is to simulate the core functions of a library (managing books and members) in a simple console application. By implementing this system in modern C++ without external libraries, the project highlights skills that are directly applicable to embedded C development for microcontrollers. It showcases clean code architecture, efficient data handling, and a focus on reliability – all important aspects of embedded systems programming.
Features
Book and Member Management: Add new books to the catalog and register new library members. Delete or update records as needed.
Search and Sorting: Quickly search for books or members by various criteria. The system can list and sort records (e.g., by title or member name) to easily organize library data.
Borrowing Reports: (Planned) Generate simple reports of library usage, such as a list of books issued to members or a summary of available vs. borrowed books.
User-Friendly Interface: Text-based menu-driven interface that guides librarians through all operations, making the application easy to use without prior training.
System Architecture
This project follows an object-oriented design for clarity and modularity. Major components include:
Book and Member Classes: Each book and each library member is represented by a class (e.g., Book, Member) containing relevant attributes (book ID, title, author, etc., or member ID, name, contact info).
LibraryItem Base Class: Common functionality for library items (such as books) is abstracted into a base class LibraryItem to demonstrate inheritance and polymorphism. This allows the system to handle different item types in a uniform way.
User Interface Module: A userInterface component manages all input/output. It presents text menus, captures user selections, and invokes the appropriate class methods to perform actions.
Reporting Module: A Report module is responsible for collating information (e.g. listing all books checked out or summarizing membership data), showcasing how the system can be extended with analytical features.
The code is organized into multiple source (.cpp) and header (.h) files corresponding to these components, improving maintainability and readability. By separating logic into classes and modules, it’s easy to add or modify features (for example, adding a new type of report or a new kind of library item) without affecting other parts of the code. Embedded Systems Focus: The implementation emphasizes efficient use of resources and minimal external dependencies, mirroring best practices in embedded C/C++ development. All data structures are from the standard library or custom-built, avoiding heavyweight frameworks. This means the core logic could be ported to run on a microcontroller (with appropriate hardware interface code) with little modification. By coding in this style, the project underlines the developer’s ability to write firmware-like code: tightly optimized, modular, and dependable.
Technologies Used
Programming Language: Modern C++ (utilizing C++11/C++14 features for compatibility). This allows for an object-oriented approach while still providing low-level control similar to C, which is beneficial for embedded programming.
Development Environment: Created and tested on Windows using Visual Studio (project solution files are included). The code is standard C++, so it can be compiled on other platforms (Linux, macOS) with a suitable C++ compiler.
Libraries & Tools: Only the C++ Standard Library (e.g., <iostream>, <vector>, etc.) is used. No third-party libraries or frameworks are required, keeping the project lightweight and portable.
How to Run
To run the library management system on your machine:
Download the Code: Click the green “Code” button on GitHub to download the repository as a ZIP, or clone it via Git.
Build the Project: You have two options:
Using Visual Studio (Windows): Open the provided Visual Studio solution file (Library managementFinal.sln). Build the solution (this will compile all source files). Then start the program using the Visual Studio debugger or by running the built .exe.
Using a Compiler (Windows/Linux/macOS): Ensure you have a C++ compiler installed (e.g. GCC or Clang). Compile all the .cpp files together. For example, with GCC you can run:
bash
Copy
Edit
g++ Source.cpp Member.cpp HoursOfOperation.cpp Report.cpp userInterface.cpp -o LibraryManagementSystem
This will produce an executable named LibraryManagementSystem (on Windows it will be LibraryManagementSystem.exe).
Run the Application: Execute the compiled program from a terminal or command prompt. A text-based menu will appear in the console.
Use the Menu: Follow the on-screen instructions. For example, choose the option to add a new book and then enter the book’s details when prompted. You can similarly add members, search for records, list all books or members, etc., by selecting the corresponding menu options.
Exit: Select the menu option to exit when you are done. The program will close the console interface.
No special hardware or environment configuration is needed to run this project. It operates as a standalone console application. (If adapted to an actual embedded device, the core logic would remain the same, with only the input/output layer changing to suit the device’s interface — for instance, using a serial console or an LCD/button setup on a microcontroller.)
Concluding Note
Embeddedfella’s Library Management System is more than a simple coding exercise – it’s structured and documented as a professional-grade project. By focusing on clean code, thoughtful architecture, and embedded-friendly practices, this application serves as a strong portfolio piece for showcasing the developer’s skills in both software development and embedded systems engineering. Whether running on a PC or potentially on an embedded platform, Embeddedfella reflects a commitment to code quality, efficiency, and effective system design.
